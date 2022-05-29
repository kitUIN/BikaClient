#pragma once
#include "Responses.CommentsResponse.g.h"
#include "Blocks/Blocks.CommentBlock.h"

namespace winrt::BikaClient::Responses::implementation
{
    struct CommentsResponse : CommentsResponseT<CommentsResponse>
    {
        CommentsResponse() = default;

        CommentsResponse(winrt::Windows::Data::Json::JsonObject const& json);
        CommentsResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> Comments();
        void Comments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> TopComments();
        void TopComments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value);
        int32_t Page();
        void Page(int32_t value);
        int32_t Pages();
        void Pages(int32_t value);
        int32_t Total();
        void Total(int32_t value);
        int32_t Limit();
        void Limit(int32_t value);
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
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> m_comments = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CommentBlock>();
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> m_topComments = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CommentBlock>();
		int32_t m_page{ 0 };
		int32_t m_pages{ 0 };
		int32_t m_total{ 0 };
		int32_t m_limit{ 0 };
		int32_t m_code{ 0 };
		hstring m_message{ L"" };
		hstring m_error{ L"" };
		hstring m_detail{ L"" };
		hstring m_json{ L"" };
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct CommentsResponse : CommentsResponseT<CommentsResponse, implementation::CommentsResponse>
    {
    };
}
