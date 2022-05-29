#include "pch.h"
#include "BikaHttpClient.h"
#include "BikaHttpClient.g.cpp"

using namespace winrt;
using namespace std;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;
using namespace Windows::Storage::Streams;
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Headers;
using namespace Windows::Security::Cryptography;
using namespace Windows::Security::Cryptography::Core;
using namespace Windows::Data::Json;
using namespace BikaClient::Responses;
using namespace BikaClient::Utils;

namespace winrt::BikaClient::implementation
{
    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="token">用户凭证</param>
    BikaHttpClient::BikaHttpClient(hstring const& token)
    {
        BikaHttpClient(token, BikaClient::ImageQualityMode::HIGH, DEFAULT_FILE_SERVER);
    }

    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="token">用户凭证</param>
    /// <param name="imageQuality">图片质量</param>
    BikaHttpClient::BikaHttpClient(hstring const& token, BikaClient::ImageQualityMode const& imageQuality)
    {
        BikaHttpClient(token, imageQuality, DEFAULT_FILE_SERVER);
    }
    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="token">用户凭证</param>
    /// <param name="imageQuality">图片质量</param>
    /// <param name="fileServer">图片地址</param>
    BikaHttpClient::BikaHttpClient(hstring const& token, BikaClient::ImageQualityMode const& imageQuality, hstring const& fileServer)
    {
        m_token = token;
        m_imageQuality = imageQuality;
        m_fileServer = fileServer;
    }
    void BikaHttpClient::Token(hstring const& value)
    {
		m_token = value;
    }

    hstring BikaHttpClient::Token()
    {
        return m_token;
    }

    hstring BikaHttpClient::GetImageQuality(BikaClient::ImageQualityMode const& imageQuality)
    {
		switch (imageQuality)
		{
		case BikaClient::ImageQualityMode::ORIGINAL:
			return L"original";
		case BikaClient::ImageQualityMode::LOW:
			return L"low";
		case BikaClient::ImageQualityMode::MEDIUM:
			return L"medium";
		case BikaClient::ImageQualityMode::HIGH:
			return L"high";
		default:
			return L"original";
		}
    }

    void BikaHttpClient::ImageQuality(BikaClient::ImageQualityMode const& value)
    {
        m_imageQuality = value;
    }

    BikaClient::ImageQualityMode BikaHttpClient::ImageQuality()
    {
        return m_imageQuality;
    }

    void BikaHttpClient::FileServer(BikaClient::FileServerMode const& fileServerMode)
    {
        if (fileServerMode == BikaClient::FileServerMode::S1) m_fileServer = L"https://storage1.picacomic.com/static/";
        else if (fileServerMode == BikaClient::FileServerMode::S2) m_fileServer = L"https://s2.picacomic.com/static/";
        else m_fileServer = L"https://s3.picacomic.com/static/";

    }

    hstring BikaHttpClient::FileServer()
    {
        return m_fileServer;
    }

    hstring BikaHttpClient::APPVersion()
    {
        return m_appVersion;
    }

    void BikaHttpClient::HttpLogOut(hstring const& s1, hstring const& s2)
    {
        m_loggingChannel.LogMessage(L"\n"+s1 + L"\n" + s2+ L"\n");
        OutputDebugStringW(L"\n");
        OutputDebugStringW(s1.c_str());
        OutputDebugStringW(L"\n");
        OutputDebugStringW(s2.c_str());
        OutputDebugStringW(L"\n");
    }

    /// <summary>
    /// 转换成十六进制
    /// </summary>
    /// <param name="x">原始</param>
    /// <returns>十六进制</returns>
    unsigned char ToHex(unsigned char x)
    {
        return  x > 9 ? x + 55 : x + 48;
    }

    /// <summary>
    /// 转换成十进制
    /// </summary>
    /// <param name="x">原始</param>
    /// <returns>十进制</returns>
    unsigned char FromHex(unsigned char x)
    {
        unsigned char y = '0';
        if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
        else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
        else if (x >= '0' && x <= '9') y = x - '0';
        else assert(0);
        return y;
    }

    /// <summary>
    /// Url转义
    /// </summary>
    /// <param name="str">url</param>
    /// <returns>转义后的url</returns>
    string UrlEncode(const string& str)
    {
        string strTemp = "";
        size_t length = str.length();
        for (size_t i = 0; i < length; i++)
        {
            if (isalnum((unsigned char)str[i]) ||
                (str[i] == '-') ||
                (str[i] == '_') ||
                (str[i] == '.') ||
                (str[i] == '~'))
                strTemp += str[i];
            else if (str[i] == ' ')
                strTemp += "+";
            else
            {
                strTemp += '%';
                strTemp += ToHex((unsigned char)str[i] >> 4);
                strTemp += ToHex((unsigned char)str[i] % 16);
            }
        }
        return strTemp;
    }

    winrt::Windows::Foundation::Diagnostics::LoggingChannel BikaHttpClient::GetLoggingChannel()
    {
        return m_loggingChannel;
    }
    /// <summary>
    /// 设置URL
    /// </summary>
    /// <param name="strAPI">调用的API</param>
    /// <param name="uid">uid</param>
    /// <param name="t">timestamp</param>
    /// <param name="method">请求方式</param>
    /// <param name="apiKey">APIKey</param>
    /// <returns>URL</returns>
    hstring BikaHttpClient::SetRaw(hstring const& strAPI,hstring const& uid,time_t const& t,hstring const& method,hstring const& apiKey)
    {
        hstring raw = strAPI + to_hstring(t) + uid + method + apiKey;
        return to_hstring(_strlwr(to_string(raw).data()));
    }

    /// <summary>
    /// HMAC-SHA256 加密
    /// </summary>
    /// <param name="strAPI">调用的API</param>
    /// <param name="uid">uid</param>
    /// <param name="t">timestamp</param>
    /// <param name="method">请求方式</param>
    /// <param name="apiKey">APIKey</param>
    /// <param name="strKey">密钥</param>
    /// <returns></returns>
    hstring BikaHttpClient::BikaEncryption(hstring const& strAPI,hstring const& uid,time_t const& t,hstring const& method,hstring const& apiKey,hstring const& strKey)
    {
        BinaryStringEncoding encoding = BinaryStringEncoding::Utf8;
        IBuffer buffMsg = CryptographicBuffer::ConvertStringToBinary(SetRaw(strAPI, uid, t, method, apiKey), encoding);
        IBuffer buffPublicKey = CryptographicBuffer::ConvertStringToBinary(strKey, encoding);
        MacAlgorithmProvider objMacProv = MacAlgorithmProvider::OpenAlgorithm(MacAlgorithmNames::HmacSha256());
        CryptographicHash hash = objMacProv.CreateHash(buffPublicKey);
        hash.Append(buffMsg);
        hstring res = CryptographicBuffer::EncodeToHexString(hash.GetValueAndReset());
        return res;
    }

    /// <summary>
    /// 设置请求头
    /// </summary>
    /// <param name="headers">请求头</param>
    /// <param name="strAPI">API</param>
    /// <param name="uuid">uuid</param>
    /// <param name="t">timestamp</param>
    /// <param name="method">请求方式</param>
    /// <returns></returns>
    HttpRequestHeaderCollection BikaHttpClient::SetHeader(HttpRequestHeaderCollection const& headers,hstring const& strAPI,time_t const& t,hstring const& method)
    {
        if (m_token!=L"")
        {
            headers.Insert(L"Authorization", m_token);
        }
        headers.Insert(L"image-quality", GetImageQuality(m_imageQuality));
        headers.Insert(L"api-key", L"C69BAF41DA5ABD1FFEDC6D2FEA56B");
        headers.Insert(L"accept", L"application/vnd.picacomic.com.v1+json");
        headers.Insert(L"app-channel", to_hstring(m_appChannel));
        headers.Insert(L"time", to_hstring(t));
        headers.Insert(L"signature", L"encrypt");
        headers.Insert(L"app-version", m_appVersion);
        headers.Insert(L"nonce", L"b1ab87b4800d4d4590a11701b8551afa");
        headers.Insert(L"app-uuid", L"defaultUuid");
        headers.Insert(L"app-platform", L"android");
        headers.Insert(L"app-build-version", L"45");
        headers.Insert(L"User-Agent", L"okhttp/3.8.1");
        headers.Insert(L"signature", BikaEncryption(strAPI, L"b1ab87b4800d4d4590a11701b8551afa", t, method, L"c69baf41da5abd1ffedc6d2fea56b", L"~d}$Q7$eIni=V)9\\RK/P.RM4;9[7|@/CA}b~OW!3?EV`:<>M7pddUBL5n|0/*Cn"));
        return headers;
    }
    IAsyncOperation<JsonObject> BikaHttpClient::Submit(HttpClient const& httpClient, HttpRequestMessage const& httpRequestMessage)
    {
        try
        {
            HttpResponseMessage res{ co_await httpClient.SendRequestAsync(httpRequestMessage) };
            co_return JsonObject::Parse(co_await res.Content().ReadAsStringAsync());
        }
        catch (winrt::hresult_error const& ex)
        {
            JsonObject res;
            winrt::hresult hr = ex.code();
            if (hr == WININET_E_CANNOT_CONNECT) {
                res.Insert(L"code", JsonValue::CreateNumberValue(-1));
                res.Insert(L"message", JsonValue::CreateStringValue(L"Time out"));
            }
            else
            {
                res.Insert(L"code", JsonValue::CreateNumberValue(-2));
                res.Insert(L"message", JsonValue::CreateStringValue(L"Error"));
            }
            res.Insert(L"detail", JsonValue::CreateStringValue(ex.message()));
            co_return res;
        }
    }
    /// <summary>
    /// GET
    /// </summary>
    /// <param name="requestUri">url</param>
    /// <param name="strAPI">API</param>
    /// <param name="uuid">uuid</param>
    /// <returns></returns>
    IAsyncOperation<JsonObject> BikaHttpClient::GET(Uri const& requestUri,hstring const& strAPI)
    {
        HttpClient httpClient;
        HttpRequestMessage httpRequestMessage;
        httpRequestMessage.Method(HttpMethod::Get());
        httpRequestMessage.RequestUri(requestUri);
        httpRequestMessage.Headers() = SetHeader(httpRequestMessage.Headers(), strAPI, time(NULL), L"GET");
        co_return co_await Submit(httpClient, httpRequestMessage);
    }

    /// <summary>
    /// POST
    /// </summary>
    /// <param name="requestUri">url</param>
    /// <param name="jsonContent">json</param>
    /// <param name="strAPI">API</param>
    /// <returns></returns>
    IAsyncOperation<JsonObject> BikaHttpClient::POST(Uri const& requestUri,HttpStringContent const& jsonContent, hstring const& strAPI)
    {
        HttpClient httpClient;
        HttpRequestMessage httpRequestMessage;
        httpRequestMessage.Method(HttpMethod::Post());
        httpRequestMessage.RequestUri(requestUri);
        httpRequestMessage.Headers() = SetHeader(httpRequestMessage.Headers(), strAPI, time(NULL), L"POST");
        httpRequestMessage.Content(jsonContent);
        co_return co_await Submit(httpClient, httpRequestMessage);

    }

    /// <summary>
    /// PUT
    /// </summary>
    /// <param name="requestUri">url</param>
    /// <param name="jsonContent">json</param>
    /// <param name="strAPI">API</param>
    /// <returns></returns>
    IAsyncOperation<JsonObject>  BikaHttpClient::PUT(Uri const& requestUri,HttpStringContent const& jsonContent,hstring const& strAPI)
    {
        HttpClient httpClient;
        HttpRequestMessage httpRequestMessage;
        httpRequestMessage.Method(HttpMethod::Put());
        httpRequestMessage.RequestUri(requestUri);
        httpRequestMessage.Headers() = SetHeader(httpRequestMessage.Headers(), strAPI, time(NULL), L"PUT");
        httpRequestMessage.Content(jsonContent);
        co_return co_await Submit(httpClient, httpRequestMessage);
    }

    /// <summary>
    /// 登录接口
    /// </summary>
    /// <param name="account" >用户名.</param>
    /// <param name="password" >密码.</param>
    /// <returns>LoginResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<LoginResponse> BikaHttpClient::Login(hstring const& email, hstring const& password)
    {
        hstring api = L"auth/sign-in";
        JsonObject json;
        json.Insert(L"email", JsonValue::CreateStringValue(email));
        json.Insert(L"password", JsonValue::CreateStringValue(password));
        LoginResponse res{
            co_await POST(
                Uri{ ORIGINURL + api },
                HttpStringContent{
                    json.Stringify(),
                    UnicodeEncoding::Utf8,
                    L"application/json" },
                api) };
        HttpLogOut(L"[POST]->/auth/sign-in\nReturn:", res.Json());
		if(res.Code() == 200) m_token = res.Token();
        co_return res;
    }

    winrt::Windows::Foundation::IAsyncOperation<UserResponse> BikaHttpClient::PersonInfo()
    {
        hstring api = L"users/profile";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/users/profile\nReturn:", res.Stringify().c_str());
        co_return UserResponse{ res, m_fileServer };
    }

    /// <summary>
    /// 获取分区列表
    /// </summary>
    /// <returns>CategoriesResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<CategoriesResponse> BikaHttpClient::Categories()
    {
        hstring api = L"categories";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/categories\nReturn:", res.Stringify().c_str());
        co_return CategoriesResponse{ res , m_fileServer };
    }
    /// <summary>
    /// 大家都在搜
    /// </summary>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Keywords()
    {
        hstring api = L"keywords";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/keywords\nReturn:", res.Stringify().c_str());
        co_return res.Stringify();
    }
    /// <summary>
    /// 获取分区
    /// </summary>
    /// <param name="page">页</param>
    /// <param name="title">分区</param>
    /// <param name="sort">排序</param>
    /// <returns>ComicsResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Comics(int32_t const& page, hstring const& title, SortMode const& sort)
    {
        BikaSort bikasort{ sort };
        hstring api = L"comics?page=" + to_hstring(page) + L"&c=" + to_hstring(UrlEncode(to_string(title))) + L"&s=" + bikasort.Sort();
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ComicsResponse{ res, m_fileServer };
    }

    /// <summary>
    /// 获取本子详细信息
    /// </summary>
    /// <param name="bookId">本子id</param>
    /// <returns>BookInfoResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<BookInfoResponse> BikaHttpClient::BookInfo(hstring const& bookId)
    {
        hstring api = L"comics/" + bookId;
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return BookInfoResponse{ res, m_fileServer };
    }
    /// <summary>
    /// 获取本子分话信息
    /// </summary>
    /// <param name="bookId">本子id</param>
    /// <param name="page">页数</param>
    /// <returns>EpisodesResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<EpisodesResponse> BikaHttpClient::Episodes(hstring const& bookId, int32_t const& page)
    {
        hstring api = L"comics/" + bookId + L"/eps?page=" + to_hstring(page);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return EpisodesResponse{ res };
    }
    /// <summary>
    /// 获取本子本体图片
    /// </summary>
    /// <param name="bookId">本子id</param>
    /// <param name="epsId">本子分话id</param>
    /// <param name="page">页数</param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<PicturesResponse> BikaHttpClient::Pictures(hstring const& bookId, int32_t const& epsId, int32_t const& page)
    {
        hstring api = L"comics/" + bookId + L"/order/" + to_hstring(epsId) + L"/pages?page=" + to_hstring(page);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return PicturesResponse{ res, m_fileServer };
    }
    /// <summary>
    /// 获取用户的收藏
    /// </summary>
    /// <param name="sort">排序</param>
    /// <param name="page">页数</param>
    /// <returns>ComicsResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::PersonFavourite(SortMode const& sort, int32_t const& page)
    {
        BikaSort bikasort{ sort };
        hstring api = L"users/favourite?s=" + bikasort.Sort() + L"&page=" + to_hstring(page);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ComicsResponse{ res, m_fileServer };
    }
    /// <summary>
    /// 获取用户的评论
    /// </summary>
    /// <param name="page">页数</param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<CommentsResponse> BikaHttpClient::PersonComment(int32_t const& page)
    {
        hstring api = L"users/my-comments?page=" + to_hstring(page);
        Uri uri = Uri{ L"https://picaapi.picacomic.com/" + api };
        JsonObject res = co_await GET(uri, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return CommentsResponse{ res, m_fileServer };
    }
    /// <summary>
    /// 看了这本子的人也在看
    /// </summary>
    /// <param name="bookId">本子id</param>
    /// <returns>ComicsResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Recommend(hstring const& bookId)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/recommendation";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ComicsResponse{ res, m_fileServer };
    }
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Search(hstring const& keywords, winrt::BikaClient::Utils::SortMode const& sort, winrt::Windows::Data::Json::JsonArray const& categories, int32_t const& page)
    {
        hstring api = L"comics/advanced-search?page=" + to_hstring(page);
        JsonObject json;
        BikaSort bikasort{ sort };
        json.SetNamedValue(L"keyword", JsonValue::CreateStringValue(keywords));
        if (categories.Size() > 0) json.SetNamedValue(L"categories", categories);
        json.SetNamedValue(L"sort", JsonValue::CreateStringValue(bikasort.Sort()));
        JsonObject res = co_await POST(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ComicsResponse{ res, m_fileServer };
    }
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::Favourite(hstring const& bookId)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/favourite";
        HttpStringContent jsonContent(
            L"",
            UnicodeEncoding::Utf8,
            L"application/json");
        JsonObject res = co_await POST(Uri{ ORIGINURL + api }, jsonContent, api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::Like(hstring const& bookId)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/like";
        HttpStringContent jsonContent(
            L"",
            UnicodeEncoding::Utf8,
            L"application/json");
        JsonObject res = co_await POST(Uri{ ORIGINURL + api }, jsonContent, api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<CommentsResponse> BikaHttpClient::Comments(hstring const& bookId, int32_t const& page)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/comments?page=" + to_hstring(page);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return CommentsResponse{ res, m_fileServer };
    }
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::SendComments(hstring const& bookId, hstring const& content)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/comments";
        Uri uri = Uri{ L"https://picaapi.picacomic.com/" + api };
        guid uuid = GuidHelper::CreateNewGuid();
        HttpStringContent jsonContent(
            L"{\"content\":\"" + content + L"\"}",
            UnicodeEncoding::Utf8,
            L"application/json");
        auto res = co_await POST(uri, jsonContent, api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::PunchIn()
    {
        hstring api = L"users/punch-in";
        Uri uri = Uri{ L"https://picaapi.picacomic.com/" + api };
        guid uuid = GuidHelper::CreateNewGuid();
        HttpStringContent jsonContent(
            L"{}",
            UnicodeEncoding::Utf8,
            L"application/json");
        auto res = co_await POST(uri, jsonContent, api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::SetSlogan(hstring const& slogan)
    {
        hstring api = L"users/profile";
        Uri uri = Uri{ L"https://picaapi.picacomic.com/" + api };
        guid uuid = GuidHelper::CreateNewGuid();
        HttpStringContent jsonContent(
            L"{\"slogan\":\"" + slogan + L"\"}",
            UnicodeEncoding::Utf8,
            L"application/json");
        auto res = co_await PUT(uri, jsonContent, api);
        HttpLogOut(L"[Put]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::SetPassword(hstring const& oldPassword, hstring const& newPassword)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::ReplyComment(hstring const& commentId, hstring const& content)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::GetReplyComment(hstring const& commentId, int32_t const& page)
    {
        throw hresult_not_implemented();
    }

}
