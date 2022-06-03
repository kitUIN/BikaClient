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
        BikaHttpClient(hstring const& token);
        BikaHttpClient(hstring const& token, BikaClient::ImageQualityMode const& imageQuality);
        BikaHttpClient(hstring const& token, BikaClient::ImageQualityMode const& imageQuality,hstring const& fileServer);
        winrt::Windows::Foundation::Diagnostics::LoggingChannel GetLoggingChannel();
        static hstring FileServerModeToString(BikaClient::FileServerMode const& fileServerMode);
        static BikaClient::FileServerMode FileServerStringToMode(hstring const& fileServerString);
        static hstring ImageQualityModeToString(BikaClient::ImageQualityMode const& imageQualityMode);
        static BikaClient::ImageQualityMode ImageQualityStringToMode(hstring const& imageQualityString);
        void Token(hstring const& value);
        hstring Token();

        void ImageQuality(BikaClient::ImageQualityMode const& value);
        BikaClient::ImageQualityMode ImageQuality();
        void FileServer(BikaClient::FileServerMode const& fileServerMode);
        hstring FileServer();
        hstring APPVersion();
        void APPChannel(int32_t const& value);
        int32_t APPChannel();
        void HttpLogOut(hstring const& s1, hstring const& s2);
        hstring SetRaw(hstring const& strAPI, hstring const& uid, time_t const& t, hstring const& method, hstring const& apiKey);
        hstring BikaEncryption(hstring const& strAPI, hstring const& uid, time_t const& t, hstring const& method, hstring const& apiKey, hstring const& strKey);
        winrt::Windows::Web::Http::Headers::HttpRequestHeaderCollection SetHeader(winrt::Windows::Web::Http::Headers::HttpRequestHeaderCollection const& headers, hstring const& strAPI, time_t const& t, hstring const& method);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> Submit(winrt::Windows::Web::Http::HttpClient const& httpClient, winrt::Windows::Web::Http::HttpRequestMessage const& httpRequestMessage);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> GET(winrt::Windows::Foundation::Uri const& requestUri, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> POST(winrt::Windows::Foundation::Uri const& requestUri, winrt::Windows::Web::Http::HttpStringContent const& jsonContent, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonObject> PUT(winrt::Windows::Foundation::Uri const& requestUri, winrt::Windows::Web::Http::HttpStringContent const& jsonContent, hstring const& strAPI);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::LoginResponse> Login(hstring const& email, hstring const& password);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::UserResponse> PersonInfo();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::CategoriesResponse> Categories();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::KeywordsResponse> Keywords();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> Comics(int32_t const& page, hstring const& title, winrt::BikaClient::Utils::SortMode const& sort);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::BookInfoResponse> BookInfo(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::EpisodesResponse> Episodes(hstring const& bookId, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::PicturesResponse> Pictures(hstring const& bookId, int32_t const& epsId, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> PersonFavourite(winrt::BikaClient::Utils::SortMode const& sort, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> Recommend(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::CommentsResponse> PersonComment(int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> Search(int32_t const& page, hstring const& keywords, winrt::BikaClient::Utils::SortMode const& sort, winrt::Windows::Data::Json::JsonArray const& categories);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> Search(int32_t const& page, hstring const& keywords, winrt::BikaClient::Utils::SortMode const& sort);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ComicsResponse> Search(int32_t const& page, hstring const& keywords);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ActionResponse> Favourite(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ActionResponse> Like(hstring const& bookId);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::CommentsResponse> Comments(hstring const& bookId, int32_t const& page);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ActionResponse> SendComments(hstring const& bookId, hstring const& content);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ActionResponse> PunchIn();
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ActionResponse> SetSlogan(hstring const& slogan);
        winrt::Windows::Foundation::IAsyncOperation<BikaClient::Responses::ActionResponse> SetPassword(hstring const& oldPassword, hstring const& newPassword);
        winrt::Windows::Foundation::IAsyncOperation<hstring> ReplyComment(hstring const& commentId, hstring const& content);
        winrt::Windows::Foundation::IAsyncOperation<hstring> GetReplyComment(hstring const& commentId, int32_t const& page);
        const hstring ORIGINURL = L"https://picaapi.picacomic.com/";
    private:
		hstring m_token;
        BikaClient::ImageQualityMode m_imageQuality = BikaClient::ImageQualityMode::HIGH;
        hstring m_fileServer = DEFAULT_FILE_SERVER;
        hstring m_appVersion = L"2.2.1.2.3.4";
        int32_t m_appChannel = 3;
        winrt::Windows::Foundation::Diagnostics::LoggingChannel m_loggingChannel = winrt::Windows::Foundation::Diagnostics::LoggingChannel(to_hstring(winrt::Windows::Foundation::GuidHelper::CreateNewGuid()));
    };
}
namespace winrt::BikaClient::factory_implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient, implementation::BikaHttpClient>
    {
    };
}
