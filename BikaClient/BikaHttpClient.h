#pragma once
#include "BikaHttpClient.g.h"


namespace winrt::BikaClient::implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient>
    {
        BikaHttpClient() = default;
        /// <summary> login
        /// </summary>
        /// <param name="a" >函数需要输入的第一个int变量.</param>
        /// <param name="b" >函数需要输入的第二个int变量.</param>
        /// <returns>Returns zero.</returns>
        winrt::Windows::Foundation::IAsyncOperation<hstring> Login(hstring account, hstring password);
        winrt::Windows::Foundation::IAsyncOperation<hstring> PersonInfo();
        winrt::Windows::Foundation::IAsyncOperation<hstring> Categories();
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
    };
}
namespace winrt::BikaClient::factory_implementation
{
    struct BikaHttpClient : BikaHttpClientT<BikaHttpClient, implementation::BikaHttpClient>
    {
    };
}
