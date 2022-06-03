#pragma once
#include "Responses.CommentsResponse.g.h"
#include "Blocks/Blocks.CommentBlock.h"
#include "Responses.IPage.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct CommentsResponse : CommentsResponseT<CommentsResponse, BikaClient::Responses::implementation::IPage>
    {
        CommentsResponse() = default;

        CommentsResponse(winrt::Windows::Data::Json::JsonObject const& json);
        CommentsResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> Comments();
        void Comments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> TopComments();
        void TopComments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value);

    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> m_comments = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CommentBlock>();
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> m_topComments = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CommentBlock>();
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct CommentsResponse : CommentsResponseT<CommentsResponse, implementation::CommentsResponse>
    {
    };
}
