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

namespace winrt::BikaClient::implementation
{
    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="token">用户凭证</param>
    BikaHttpClient::BikaHttpClient(hstring token)
    {
		m_token = token;
    }

    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="token">用户凭证</param>
    /// <param name="imageQuality">图片质量</param>
    BikaHttpClient::BikaHttpClient(hstring token, hstring imageQuality)
    {
		m_token = token;
		m_imageQuality = imageQuality;
    }

    void BikaHttpClient::Token(hstring value)
    {
		m_token = value;
    }

    hstring BikaHttpClient::Token()
    {
        return m_token;
    }

    void BikaHttpClient::ImageQuality(hstring value)
    {
		m_imageQuality = value;
    }

    hstring BikaHttpClient::ImageQuality()
    {
        return m_imageQuality;
    }

    void BikaHttpClient::HttpLogOut(hstring s1, hstring s2)
    {
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
        headers.Insert(L"image-quality", m_imageQuality);
        headers.Insert(L"api-key", L"C69BAF41DA5ABD1FFEDC6D2FEA56B");
        headers.Insert(L"accept", L"application/vnd.picacomic.com.v1+json");
        headers.Insert(L"app-channel", L"3");
        headers.Insert(L"time", to_hstring(t));
        headers.Insert(L"signature", L"encrypt");
        headers.Insert(L"app-version", L"2.2.1.2.3.4");
        headers.Insert(L"nonce", L"b1ab87b4800d4d4590a11701b8551afa");
        headers.Insert(L"app-uuid", L"defaultUuid");
        headers.Insert(L"app-platform", L"android");
        headers.Insert(L"app-build-version", L"45");
        headers.Insert(L"User-Agent", L"okhttp/3.8.1");
        headers.Insert(L"signature", BikaEncryption(strAPI, L"b1ab87b4800d4d4590a11701b8551afa", t, method, L"c69baf41da5abd1ffedc6d2fea56b", L"~d}$Q7$eIni=V)9\\RK/P.RM4;9[7|@/CA}b~OW!3?EV`:<>M7pddUBL5n|0/*Cn"));
        return headers;
    }

    /// <summary>
    /// GET
    /// </summary>
    /// <param name="requestUri">url</param>
    /// <param name="strAPI">strAPI</param>
    /// <param name="uuid">uuid</param>
    /// <returns></returns>
    IAsyncOperation<hstring> BikaHttpClient::GET(Uri const& requestUri,hstring const& strAPI)
    {
        HttpClient httpClient;
        HttpRequestMessage httpRequestMessage;
        HttpResponseMessage httpResponseMessage;
        time_t t = time(NULL);
        httpRequestMessage.Method(HttpMethod::Get());
        httpRequestMessage.RequestUri(requestUri);
        httpRequestMessage.Headers() = SetHeader(httpRequestMessage.Headers(), strAPI, t, L"GET");
        try
        {
            HttpResponseMessage res{ co_await httpClient.SendRequestAsync(httpRequestMessage) };
            co_return co_await res.Content().ReadAsStringAsync();
        }
        catch (winrt::hresult_error const& ex)
        {
            winrt::hstring message = ex.message();
            winrt::hresult hr = ex.code();
            if (hr == WININET_E_CANNOT_CONNECT) {
                OutputDebugStringW(message.c_str());
                co_return L"[TimeOut]" + message;
            }
            else
            {
                co_return L"[ERROR]" + message;
            }
        }
    }

    /// <summary>
    /// POST
    /// </summary>
    /// <param name="requestUri">url</param>
    /// <param name="jsonContent">json</param>
    /// <param name="strAPI">strAPI</param>
    /// <returns></returns>
    IAsyncOperation<hstring>  BikaHttpClient::POST(Uri const& requestUri,HttpStringContent const& jsonContent, hstring const& strAPI)
    {
        HttpClient httpClient;
        HttpRequestMessage httpRequestMessage;
        time_t t = time(NULL);
        httpRequestMessage.Method(HttpMethod::Post());
        httpRequestMessage.RequestUri(requestUri);
        httpRequestMessage.Headers() = SetHeader(httpRequestMessage.Headers(), strAPI, t, L"POST");
        httpRequestMessage.Content(jsonContent);
        try
        {
            HttpResponseMessage res{ co_await httpClient.SendRequestAsync(httpRequestMessage) };
            co_return co_await res.Content().ReadAsStringAsync();
        }
        catch (winrt::hresult_error const& ex)
        {
            winrt::hstring message = ex.message();
            winrt::hresult hr = ex.code();
            if (hr == WININET_E_CANNOT_CONNECT) {
                OutputDebugStringW(message.c_str());
                co_return L"[TimeOut]" + message;
            }
            else
            {
                co_return L"[ERROR]" + message;
            }
        }
    }

    /// <summary>
    /// PUT
    /// </summary>
    /// <param name="requestUri">url</param>
    /// <param name="jsonContent">json</param>
    /// <param name="strAPI"></param>
    /// <returns></returns>
    IAsyncOperation<hstring>  BikaHttpClient::PUT(Uri const& requestUri,HttpStringContent const& jsonContent,hstring const& strAPI)
    {
        HttpClient httpClient;
        HttpRequestMessage httpRequestMessage;
        time_t t = time(NULL);
        httpRequestMessage.Method(HttpMethod::Put());
        httpRequestMessage.RequestUri(requestUri);
        httpRequestMessage.Headers() = SetHeader(httpRequestMessage.Headers(), strAPI, t, L"PUT");
        httpRequestMessage.Content(jsonContent);
        try
        {
            HttpResponseMessage res{ co_await httpClient.SendRequestAsync(httpRequestMessage) };
            co_return co_await res.Content().ReadAsStringAsync();
        }
        catch (winrt::hresult_error const& ex)
        {
            winrt::hstring message = ex.message();
            winrt::hresult hr = ex.code();
            if (hr == WININET_E_CANNOT_CONNECT) {
                OutputDebugStringW(message.c_str());
                co_return L"[TimeOut]" + message;
            }
            else
            {
                co_return L"[ERROR]" + message;
            }
        }
    }

    /// <summary>
    /// 登录接口
    /// </summary>
    /// <param name="account" >用户名.</param>
    /// <param name="password" >密码.</param>
    /// <returns>请求结果</returns>
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Login(hstring account, hstring password)
    {
        Uri requestUri{ L"https://picaapi.picacomic.com/auth/sign-in" };
        guid uuid = GuidHelper::CreateNewGuid();
        HttpStringContent jsonContent(
            L"{ \"email\": \"" + account + L"\", \"password\": \"" + password + L"\" }",
            UnicodeEncoding::Utf8,
            L"application/json");
        hstring ress = co_await POST(requestUri, jsonContent, L"auth/sign-in");
        HttpLogOut(L"[POST]->/auth/sign-in\nReturn:", ress.c_str());
        co_return ress;
    }

    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::PersonInfo()
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Categories()
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Keywords()
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Comics(int32_t page, hstring title, hstring sort)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::BookInfo(hstring bookId)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Episodes(hstring bookId, int32_t page)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Picture(hstring bookId, int32_t epsId, int32_t page)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::PersonFavourite(hstring sort, int32_t page)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::PersonComment(int32_t page)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Search(hstring keywords, hstring sort, winrt::Windows::Data::Json::JsonArray categories, int32_t page)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Favourite(hstring bookId)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Like(hstring bookId)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Comments(hstring bookId, int32_t page)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::SendComments(hstring bookId, hstring content)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::PunchIn()
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::SetSlogan(hstring slogan)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::SetPassword(hstring oldPassword, hstring newPassword)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::ReplyComment(hstring commentId, hstring content)
    {
        throw hresult_not_implemented();
    }
    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::GetReplyComment(hstring commentId, int32_t page)
    {
        throw hresult_not_implemented();
    }

}
