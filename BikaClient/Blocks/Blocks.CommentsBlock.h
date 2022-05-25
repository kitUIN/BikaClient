#pragma once
#include "Blocks.CommentsBlock.g.h"


namespace winrt::BikaClient::Blocks::implementation
{
    struct CommentsBlock : CommentsBlockT<CommentsBlock>
    {
        CommentsBlock() = default;

        CommentsBlock(winrt::Windows::Data::Json::JsonObject const& json);
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
        bool IsTop();
        void IsTop(bool value);
        bool Hide();
        void Hide(bool value);
        bool IsLiked();
        void IsLiked(bool value);
        hstring BookId();
        void BookId(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct CommentsBlock : CommentsBlockT<CommentsBlock, implementation::CommentsBlock>
    {
    };
}
