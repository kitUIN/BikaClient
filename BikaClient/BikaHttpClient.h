#pragma once
#include "BikaHttpClient.g.h"
#include "Responses/Responses.LoginResponse.h"
#include "Responses/Responses.CategoriesResponse.h"
#include "Responses/Responses.UserResponse.h"
#include "Responses/Responses.ComicsResponse.h"
#include "Utils/Utils.BikaSort.h"
namespace winrt::BikaClient::implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient>
    {
        BikaHttpClient() = default;
        BikaHttpClient(hstring token);
        BikaHttpClient(hstring token,hstring imageQuality);
        BikaHttpClient(hstring token,hstring imageQuality,hstring fileServer);
        winrt::Windows::Foundation::Diagnostics::LoggingChannel GetLoggingChannel();
        void Token(hstring value);
        hstring Token();
        void ImageQuality(hstring value);
        hstring ImageQuality();
        void FileServer(hstring value);
        hstring FileServer();
        hstring APPVersion();
        void HttpLogOut(hstring s1, hstring s2);
        hstring SetRaw(hstring const& strAPI, hstring const& uid, time_t const& t, hstring const& method, hstring const& apiKey);
        hstring BikaEncryption(hstring const& strAPI, hstring const& uid, time_t const& t, hstring const& method, hstring const& apiKey, hstring const& strKey);
        winrt::Windows::Web::Http::Headers::HttpRequestHeaderCollection SetHeader(winrt::Windows::Web::Http::Headers::HttpRequestHeaderCollection const& headers, hstring const& strAPI, time_t const& t, hstring const& method);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> Submit(winrt::Windows::Web::Http::HttpClient const& httpClient, winrt::Windows::Web::Http::HttpRequestMessage const& httpRequestMessage);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> GET(winrt::Windows::Foundation::Uri const& requestUri, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> POST(winrt::Windows::Foundation::Uri const& requestUri, winrt::Windows::Web::Http::HttpStringContent const& jsonContent, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> PUT(winrt::Windows::Foundation::Uri const& requestUri, winrt::Windows::Web::Http::HttpStringContent const& jsonContent, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::LoginResponse> Login(hstring const& account, hstring const& password);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::UserResponse> PersonInfo();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::CategoriesResponse> Categories();
        winrt::Windows::Foundation::IAsyncOperation<hstring> Keywords();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> Comics(int32_t const& page, hstring const& title, winrt::BikaClient::Utils::SortMode const& sort);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::BookInfoResponse> BookInfo(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::EpisodesResponse> Episodes(hstring const& bookId, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Picture(hstring const& bookId, int32_t const& epsId, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PersonFavourite(hstring const& sort, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PersonComment(int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Search(hstring const& keywords, hstring const& sort, winrt::Windows::Data::Json::JsonArray const& categories, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Favourite(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Like(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<hstring> Comments(hstring const& bookId, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<hstring> SendComments(hstring const& bookId, hstring const& content);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PunchIn();
        winrt::Windows::Foundation::IAsyncOperation<hstring> SetSlogan(hstring const& slogan);
        winrt::Windows::Foundation::IAsyncOperation<hstring> SetPassword(hstring const& oldPassword, hstring const& newPassword);
        winrt::Windows::Foundation::IAsyncOperation<hstring> ReplyComment(hstring const& commentId, hstring const& content);
        winrt::Windows::Foundation::IAsyncOperation<hstring> GetReplyComment(hstring const& commentId, int32_t const& page);
        const hstring ORIGINURL = L"https://picaapi.picacomic.com/";
    private:
		hstring m_token;
        hstring m_imageQuality;
        hstring m_fileServer=DEFAULT_FILE_SERVER;
        hstring m_appVersion=L"2.2.1.2.3.4";
        winrt::Windows::Foundation::Diagnostics::LoggingChannel m_loggingChannel = winrt::Windows::Foundation::Diagnostics::LoggingChannel(to_hstring(winrt::Windows::Foundation::GuidHelper::CreateNewGuid()));
    };
}
namespace winrt::BikaClient::factory_implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient, implementation::BikaHttpClient>
    {
    };
}
