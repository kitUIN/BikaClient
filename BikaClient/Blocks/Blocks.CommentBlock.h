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
        hstring BookId();
        void BookId(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    private:
		hstring m_id = L"";
		hstring m_content = L"";
        hstring m_comic = L"";
		winrt::BikaClient::Blocks::UserBlock m_user{ nullptr };
		winrt::BikaClient::Date::BikaDate m_createdAt{ nullptr };
		int32_t m_likesCount = 0;
		int32_t m_commentsCount = 0;
        winrt::BikaClient::Utils::BikaBoolean m_isTop{ nullptr };
		winrt::BikaClient::Utils::BikaBoolean m_hide{ nullptr };
		winrt::BikaClient::Utils::BikaBoolean m_isLiked{ nullptr };
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
