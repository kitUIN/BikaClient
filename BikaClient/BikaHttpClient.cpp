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
        BikaHttpClient(token, BikaClient::ImageQualityMode::HIGH, L"https://storage1.picacomic.com/static/");
    }

    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="token">用户凭证</param>
    /// <param name="imageQuality">图片质量</param>
    BikaHttpClient::BikaHttpClient(hstring const& token, BikaClient::ImageQualityMode const& imageQuality)
    {
        BikaHttpClient(token, imageQuality, L"https://storage1.picacomic.com/static/");
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
    /// <summary>
    /// 设置Token
    /// </summary>
    /// <param name="value">Token</param>
    void BikaHttpClient::Token(hstring const& value)
    {
		m_token = value;
    }
    /// <summary>
    /// 获取当前Toekn
    /// </summary>
    /// <returns>当前token</returns>
    hstring BikaHttpClient::Token()
    {
        return m_token;
    }
    /// <summary>
    /// 当前画质 Mode 转 String
    /// </summary>
    /// <param name="imageQuality">画质Mode</param>
    /// <returns></returns>
    hstring BikaHttpClient::ImageQualityModeToString(BikaClient::ImageQualityMode const& imageQualityMode)
    {
		switch (imageQualityMode)
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
			return L"high";
		}
    }
    /// <summary>
    /// 当前画质 String 转 Mode
    /// </summary>
    /// <param name="imageQualityString"></param>
    /// <returns></returns>
    BikaClient::ImageQualityMode BikaHttpClient::ImageQualityStringToMode(hstring const& imageQualityString)
    {
        if (imageQualityString == L"original") return BikaClient::ImageQualityMode::ORIGINAL;
        else if (imageQualityString == L"low") return BikaClient::ImageQualityMode::LOW;
        else if (imageQualityString == L"medium") return BikaClient::ImageQualityMode::MEDIUM;
        else return BikaClient::ImageQualityMode::HIGH;
    }
    /// <summary>
    /// 设置图片画质
    /// </summary>
    /// <param name="value"></param>
    void BikaHttpClient::ImageQuality(BikaClient::ImageQualityMode const& value)
    {
        m_imageQuality = value;
    }
    /// <summary>
    /// 获取图片画质
    /// </summary>
    /// <returns></returns>
    BikaClient::ImageQualityMode BikaHttpClient::ImageQuality()
    {
        return m_imageQuality;
    }
    /// <summary>
    /// 设置图片服务器
    /// </summary>
    /// <param name="fileServerMode">图片服务器</param>
    void BikaHttpClient::FileServer(BikaClient::FileServerMode const& fileServerMode)
    {
        m_fileServer = FileServerModeToString(fileServerMode);
    }
    /// <summary>
    /// 获取图片服务器
    /// </summary>
    /// <returns></returns>
    hstring BikaHttpClient::FileServer()
    {
        return m_fileServer;
    }
    /// <summary>
    /// 获取APP 内核版本
    /// </summary>
    /// <returns></returns>
    hstring BikaHttpClient::APPVersion()
    {
        return m_appVersion;
    }
    /// <summary>
    /// 设置分流
    /// </summary>
    /// <param name="value">分流(1-3)</param>
    void BikaHttpClient::APPChannel(int32_t const& value)
    {
        m_appChannel = value;
    }
    /// <summary>
    /// 获取分流
    /// </summary>
    /// <returns></returns>
    int32_t BikaHttpClient::APPChannel()
    {
        return m_appChannel;
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
    /// FileServer Mode 转 String
    /// </summary>
    /// <param name="fileServerMode">Mode</param>
    /// <returns></returns>
    hstring BikaHttpClient::FileServerModeToString(BikaClient::FileServerMode const& fileServerMode)
    {
        if (fileServerMode == BikaClient::FileServerMode::S3) return L"https://s3.picacomic.com/static/";
        else if (fileServerMode == BikaClient::FileServerMode::S2) return L"https://s2.picacomic.com/static/";
        else return L"https://storage1.picacomic.com/static/";

    }
    /// <summary>
    /// FileServer String 转 Mode
    /// </summary>
    /// <param name="fileServerModeString">String</param>
    /// <returns></returns>
    BikaClient::FileServerMode BikaHttpClient::FileServerStringToMode(hstring const& fileServerString)
    {
        if (fileServerString == L"https://s2.picacomic.com/static/") return BikaClient::FileServerMode::S2;
        else if (fileServerString == L"https://s3.picacomic.com/static/") return BikaClient::FileServerMode::S3;
        else return BikaClient::FileServerMode::S1;
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
        headers.Insert(L"image-quality", ImageQualityModeToString(m_imageQuality));
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
                res.Insert(L"message", JsonValue::CreateStringValue(ex.message()));
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
    winrt::Windows::Foundation::IAsyncOperation<KeywordsResponse> BikaHttpClient::Keywords()
    {
        hstring api = L"keywords";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/keywords\nReturn:", res.Stringify().c_str());
        co_return KeywordsResponse{ res };
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

        hstring api = L"comics?page=" + to_hstring(page) + L"&c=" + to_hstring(UrlEncode(to_string(title))) + L"&s=" + BikaSort::ToSort(sort);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ComicsResponse{ res, m_fileServer };
    }
    /// <summary>
    /// 最近更新
    /// </summary>
    /// <param name="page"></param>
    /// <param name="sort"></param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> BikaHttpClient::Comics(int32_t const& page, winrt::BikaClient::Utils::SortMode const& sort)
    {
        hstring api = L"comics?page=" + to_hstring(page) + L"&s=" + BikaSort::ToSort(sort);
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

        hstring api = L"users/favourite?s=" + BikaSort::ToSort(sort) + L"&page=" + to_hstring(page);
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
    /// <summary>
    /// 搜索
    /// </summary>
    /// <param name="keywords">关键字</param>
    /// <param name="sort">排序</param>
    /// <param name="categories">分区</param>
    /// <param name="page">页数</param>
    /// <returns>ComicsResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Search(int32_t const& page, hstring const& keywords, winrt::BikaClient::Utils::SortMode const& sort, winrt::Windows::Data::Json::JsonArray const& categories)
    {
        hstring api = L"comics/advanced-search?page=" + to_hstring(page);
        JsonObject json;
        json.SetNamedValue(L"keyword", JsonValue::CreateStringValue(keywords));
        if (categories.Size() > 0) json.SetNamedValue(L"categories", categories);
        json.SetNamedValue(L"sort", JsonValue::CreateStringValue(BikaSort::ToSort(sort)));
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
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Search(int32_t const& page, hstring const& keywords, winrt::BikaClient::Utils::SortMode const& sort)
    {
        JsonArray jsonArray;
        co_return co_await Search(page, keywords,sort, jsonArray);
    }
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Search(int32_t const& page, hstring const& keywords)
    {
        co_return co_await Search(page, keywords, BikaClient::Utils::SortMode::UA);
    }
    /// <summary>
    /// 收藏本子
    /// </summary>
    /// <param name="bookId">本子ID</param>
    /// <returns>ActionResponse</returns>
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
    /// <summary>
    /// 喜欢本子
    /// </summary>
    /// <param name="bookId">本子ID</param>
    /// <returns>ActionResponse</returns>
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
    /// <summary>
    /// 本子的评论
    /// </summary>
    /// <param name="bookId">本子ID</param>
    /// <param name="page">页数</param>
    /// <returns>CommentsResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<CommentsResponse> BikaHttpClient::Comments(hstring const& bookId, int32_t const& page)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/comments?page=" + to_hstring(page);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return CommentsResponse{ res, m_fileServer };
    }

    /// <summary>
    /// 发送评论
    /// </summary>
    /// <param name="bookId">本子ID</param>
    /// <param name="content">评论内容</param>
    /// <returns>ActionResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::SendComments(hstring const& bookId, hstring const& content)
    {
        hstring api = L"comics/" + to_hstring(bookId) + L"/comments";
        JsonObject json;
        json.SetNamedValue(L"content", JsonValue::CreateStringValue(content));
        JsonObject res = co_await POST(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    /// <summary>
    /// 打卡
    /// </summary>
    /// <returns>ActionResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::PunchIn()
    {
        hstring api = L"users/punch-in";
        JsonObject res = co_await POST(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                L"{}",
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    /// <summary>
    /// 设置个性签名
    /// </summary>
    /// <param name="slogan">个性签名</param>
    /// <returns>ActionResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::SetSlogan(hstring const& slogan)
    {
        hstring api = L"users/profile";
        JsonObject json;
        json.SetNamedValue(L"slogan", JsonValue::CreateStringValue(slogan));
        JsonObject res = co_await PUT(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Put]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    /// <summary>
    /// 设置密码
    /// </summary>
    /// <param name="oldPassword">旧密码</param>
    /// <param name="newPassword">新密码</param>
    /// <returns>ActionResponse</returns>
    winrt::Windows::Foundation::IAsyncOperation<ActionResponse> BikaHttpClient::SetPassword(hstring const& oldPassword, hstring const& newPassword)
    {
        hstring api = L"users/password";
        JsonObject json;
        json.SetNamedValue(L"old_password", JsonValue::CreateStringValue(oldPassword));
        json.SetNamedValue(L"new_password", JsonValue::CreateStringValue(newPassword));
        JsonObject res = co_await PUT(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Put]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ActionResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<JsonResponse> BikaHttpClient::SetTitle(hstring const& userId, hstring const& title)
    {
        hstring api = L"users/" + userId + L"/title";
        JsonObject json;
        json.SetNamedValue(L"title", JsonValue::CreateStringValue(title));
        JsonObject res = co_await PUT(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Put]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return JsonResponse{ res };
    }
    /// <summary>
    /// 设置头像
    /// </summary>
    /// <param name="buffer">图片缓冲流</param>
    /// <param name="fileType">图片类型</param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<JsonResponse> BikaHttpClient::SetAvatar(Windows::Storage::Streams::IBuffer const& buffer, hstring const& fileType)
    {
        hstring api = L"users/avatar";
        hstring avatar = L"data:image/" + fileType + L";base64," + CryptographicBuffer::EncodeToBase64String(buffer);
        JsonObject json;
        json.SetNamedValue(L"avatar", JsonValue::CreateStringValue(avatar));
        JsonObject res = co_await PUT(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Put]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return JsonResponse{ res };
    }
    /// <summary>
    /// 回复评论
    /// </summary>
    /// <param name="commentId">评论ID</param>
    /// <param name="content">评论内容</param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::ReplyComment(hstring const& commentId, hstring const& content)
    {
        hstring api = L"comments/" + commentId;
        JsonObject json;
        json.SetNamedValue(L"content", JsonValue::CreateStringValue(content));
        JsonObject res = co_await POST(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[Post]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return res.Stringify();
    }
    /// <summary>
    /// 获取评论的回复
    /// </summary>
    /// <param name="commentId">评论ID</param>
    /// <param name="page">页数</param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::GetReplyComment(hstring const& commentId, int32_t const& page)
    {
        hstring api = L"comments/" + commentId + L"/childrens?page=" + to_hstring(page);
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return res.Stringify();
    }

    /// <summary>
    /// 安卓平台初始化
    /// </summary>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<JsonResponse> BikaHttpClient::PlatformInit()
    {
        hstring api = L"init?platform=android";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return JsonResponse{ res };
    }
    /// <summary>
    /// 本子神魔
    /// </summary>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<JsonResponse> BikaHttpClient::Collections()
    {
        hstring api = L"collections";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return JsonResponse{ res };
    }
    /// <summary>
    /// 公告栏
    /// </summary>
    /// <param name="page"></param>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<JsonResponse> BikaHttpClient::Announcements(int32_t const& page)
	{
		hstring api = L"announcements?page=" + to_hstring(page);
		JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
		HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return JsonResponse{ res };
	}
    /// <summary>
    /// 随机本子
    /// </summary>
    /// <returns></returns>
    winrt::Windows::Foundation::IAsyncOperation<ComicsResponse> BikaHttpClient::Random()
    {
        hstring api = L"comics/random";
        JsonObject res = co_await GET(Uri{ ORIGINURL + api }, api);
        HttpLogOut(L"[GET]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return ComicsResponse{ res };
    }
    winrt::Windows::Foundation::IAsyncOperation<JsonResponse> BikaHttpClient::Register(hstring const& email, hstring const& password, hstring const& name, hstring const& birthday, BikaClient::Utils::Gender const& gender, hstring const& question1, hstring const& question2, hstring const& question3, hstring const& answer1, hstring const& answer2, hstring const& answer3)
    {
        hstring api = L"auth/register";
        JsonObject json;
        json.Insert(L"email", JsonValue::CreateStringValue(email));
        json.Insert(L"password", JsonValue::CreateStringValue(password));
        json.Insert(L"name", JsonValue::CreateStringValue(name));
        json.Insert(L"birthday", JsonValue::CreateStringValue(birthday));
        hstring g;
        if (BikaClient::Utils::Gender::Female == gender) g = L"f";
        else if(BikaClient::Utils::Gender::Male == gender) g = L"m";
        else g = L"bot";
        json.Insert(L"gender", JsonValue::CreateStringValue(g));
        json.Insert(L"question1", JsonValue::CreateStringValue(question1));
        json.Insert(L"question2", JsonValue::CreateStringValue(question2));
        json.Insert(L"question3", JsonValue::CreateStringValue(question3));
        json.Insert(L"answer1", JsonValue::CreateStringValue(answer1));
        json.Insert(L"answer2", JsonValue::CreateStringValue(answer2));
        json.Insert(L"answer3", JsonValue::CreateStringValue(answer3));
        JsonObject res = co_await POST(
            Uri{ ORIGINURL + api },
            HttpStringContent{
                json.Stringify(),
                UnicodeEncoding::Utf8,
                L"application/json" },
                api);
        HttpLogOut(L"[POST]->/" + api + L"\nReturn:", res.Stringify().c_str());
        co_return JsonResponse{ res };
    }

}
