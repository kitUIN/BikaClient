#pragma once
#include "Blocks.CommentBlock.g.h"
#include "Utils/Utils.BikaBoolean.h"
#include "Blocks/Blocks.UserBlock.h"
#include "Date/Date.BikaDate.h"
namespace winrt::BikaClient::Blocks::implementation
{
    struct CommentBlock : CommentBlockT<CommentBlock>
    {
        CommentBlock() = default;

        CommentBlock(winrt::Windows::Data::Json::JsonObject const& json);
        CommentBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        hstring ID();
        void ID(hstring const& value);
        hstring Content();
        void Content(hstring const& value);
        hstring Comic();
        void Comic(hstring const& value);
        winrt::BikaClient::Blocks::UserBlock User();
        void User(winrt::BikaClient::Blocks::UserBlock const& value);
        winrt::BikaClient::Date::BikaDate CreatedAt();
        void CreatedAt(winrt::BikaClient::Date::BikaDate const& value);
        int32_t LikesCount();
        void LikesCount(int32_t value);
        int32_t CommentsCount();
        void CommentsCount(int32_t value);

        winrt::BikaClient::Utils::BikaBoolean IsTop();
        void IsTop(winrt::BikaClient::Utils::BikaBoolean const& value);
        winrt::BikaClient::Utils::BikaBoolean Hide();
        void Hide(winrt::BikaClient::Utils::BikaBoolean const& value);
        winrt::BikaClient::Utils::BikaBoolean IsLiked();
        void IsLiked(winrt::BikaClient::Utils::BikaBoolean const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> ReplyComments();
        void ReplyComments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value);
        hstring BookId();
        int32_t Order();
        void Order(int32_t value);
        void BookId(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    private:
		hstring m_id = L"";
		hstring m_content = L"";
        hstring m_comic = L"";
		winrt::BikaClient::Blocks::UserBlock m_user;
		winrt::BikaClient::Date::BikaDate m_createdAt;
		int32_t m_likesCount = 0;
		int32_t m_order = 0;
		int32_t m_commentsCount = 0;
        winrt::BikaClient::Utils::BikaBoolean m_isTop;
		winrt::BikaClient::Utils::BikaBoolean m_hide;
		winrt::BikaClient::Utils::BikaBoolean m_isLiked;
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> m_replyComments = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CommentBlock>();
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
		hstring m_bookId = L"";
		winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		hstring m_json = L"";
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct CommentBlock : CommentBlockT<CommentBlock, implementation::CommentBlock>
    {
    };
}
