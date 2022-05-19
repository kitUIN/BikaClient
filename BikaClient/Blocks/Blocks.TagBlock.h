#pragma once
#include "Blocks.TagBlock.g.h"


namespace winrt::BikaClient::Blocks::implementation
{
    struct TagBlock : TagBlockT<TagBlock>
    {
        TagBlock() = default;

        TagBlock(hstring const& tag);
        hstring Tag();
        void Tag(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        hstring m_tag;
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct TagBlock : TagBlockT<TagBlock, implementation::TagBlock>
    {
    };
}
