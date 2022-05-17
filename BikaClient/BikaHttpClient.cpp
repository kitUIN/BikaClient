#include "pch.h"
#include "BikaHttpClient.h"
#include "BikaHttpClient.g.cpp"


namespace winrt::BikaClient::implementation
{

    winrt::Windows::Foundation::IAsyncOperation<hstring> BikaHttpClient::Login(hstring account, hstring password)
    {
        OutputDebugStringW(L"hello");
        hstring a = L"asdfasdf";
        co_return a;
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
