#pragma once
#include "BikaHttpClient.g.h"
#include "Responses/Responses.LoginResponse.h"

namespace winrt::BikaClient::implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient>
    {
        BikaHttpClient() = default;
        BikaHttpClient(hstring token);
        BikaHttpClient(hstring token,hstring imageQuality);
        winrt::Windows::Foundation::Diagnostics::LoggingChannel GetLoggingChannel();
        void Token(hstring value);
        hstring Token();
        void ImageQuality(hstring value);
        hstring ImageQuality();
        void HttpLogOut(hstring s1, hstring s2);
        hstring SetRaw(hstring const& strAPI, hstring const& uid, time_t const& t, hstring const& method, hstring const& apiKey);
        hstring BikaEncryption(hstring const& strAPI, hstring const& uid, time_t const& t, hstring const& method, hstring const& apiKey, hstring const& strKey);
        winrt::Windows::Web::Http::Headers::HttpRequestHeaderCollection SetHeader(winrt::Windows::Web::Http::Headers::HttpRequestHeaderCollection const& headers, hstring const& strAPI, time_t const& t, hstring const& method);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> Submit(winrt::Windows::Web::Http::HttpClient const& httpClient, winrt::Windows::Web::Http::HttpRequestMessage const& httpRequestMessage);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> GET(winrt::Windows::Foundation::Uri const& requestUri, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> POST(winrt::Windows::Foundation::Uri const& requestUri, winrt::Windows::Web::Http::HttpStringContent const& jsonContent, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> PUT(winrt::Windows::Foundation::Uri const& requestUri, winrt::Windows::Web::Http::HttpStringContent const& jsonContent, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::LoginResponse> Login(hstring account, hstring password);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PersonInfo();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::CategoriesResponse> Categories();
        winrt::Windows::Foundation::IAsyncOperation<hstring> Keywords();
        winrt::Windows::Foundation::IAsyncOperation<hstring> Comics(int32_t page, hstring title, hstring sort);
        winrt::Windows::Foundation::IAsyncOperation<hstring> BookInfo(hstring bookId);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Episodes(hstring bookId, int32_t page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Picture(hstring bookId, int32_t epsId, int32_t page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PersonFavourite(hstring sort, int32_t page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PersonComment(int32_t page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Search(hstring keywords, hstring sort, winrt::Windows::Data::Json::JsonArray categories, int32_t page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Favourite(hstring bookId);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Like(hstring bookId);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Comments(hstring bookId, int32_t page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> SendComments(hstring bookId, hstring content);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PunchIn();
        winrt::Windows::Foundation::IAsyncOperation<hstring> SetSlogan(hstring slogan);
        winrt::Windows::Foundation::IAsyncOperation<hstring> SetPassword(hstring oldPassword, hstring newPassword);
        winrt::Windows::Foundation::IAsyncOperation<hstring> ReplyComment(hstring commentId, hstring content);
        winrt::Windows::Foundation::IAsyncOperation<hstring> GetReplyComment(hstring commentId, int32_t page);
        const hstring ORIGINURL = L"https://picaapi.picacomic.com/";
    private:
		hstring m_token;
        hstring m_imageQuality = L"original";
        hstring m_fileServer = DEFAULT_FILE_SERVER;
        winrt::Windows::Foundation::Diagnostics::LoggingChannel m_loggingChannel = winrt::Windows::Foundation::Diagnostics::LoggingChannel(to_hstring(winrt::Windows::Foundation::GuidHelper::CreateNewGuid()));
    };
}
namespace winrt::BikaClient::factory_implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient, implementation::BikaHttpClient>
    {
    };
}
