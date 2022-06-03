#pragma once
#include "Responses.BookInfoResponse.g.h"
#include "Blocks/Blocks.BookBlock.h"
#include "Responses.IResponse.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct BookInfoResponse : BookInfoResponseT<BookInfoResponse, BikaClient::Responses::implementation::IResponse>
    {
        BookInfoResponse() = default;

        BookInfoResponse(winrt::Windows::Data::Json::JsonObject const& json);
        BookInfoResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::BikaClient::Blocks::BookBlock BookInfos();
        void BookInfos(winrt::BikaClient::Blocks::BookBlock const& value);
    private:
        winrt::BikaClient::Blocks::BookBlock m_bookInfos{ nullptr };
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
	};
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct BookInfoResponse : BookInfoResponseT<BookInfoResponse, implementation::BookInfoResponse>
    {
    };
}
