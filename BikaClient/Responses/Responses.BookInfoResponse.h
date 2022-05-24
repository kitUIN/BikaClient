#pragma once
#include "Responses.BookInfoResponse.g.h"
#include "Blocks/Blocks.BookBlock.h"

namespace winrt::BikaClient::Responses::implementation
{
    struct BookInfoResponse : BookInfoResponseT<BookInfoResponse>
    {
        BookInfoResponse() = default;

        BookInfoResponse(winrt::Windows::Data::Json::JsonObject const& json);
        BookInfoResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        winrt::BikaClient::Blocks::BookBlock BookInfos();
        void BookInfos(winrt::BikaClient::Blocks::BookBlock const& value);
        int32_t Code();
        void Code(int32_t value);
        hstring Message();
        void Message(hstring const& value);
        hstring Error();
        void Error(hstring const& value);
        hstring Detail();
        void Detail(hstring const& value);
        hstring Json();
    private:
        winrt::BikaClient::Blocks::BookBlock m_bookInfos{ nullptr };
		int32_t m_code{ 0 };
        hstring m_message{ L"" };
        hstring m_error{ L"" };
        hstring m_detail{ L"" };
        hstring m_json{ L"" };
	};
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct BookInfoResponse : BookInfoResponseT<BookInfoResponse, implementation::BookInfoResponse>
    {
    };
}
