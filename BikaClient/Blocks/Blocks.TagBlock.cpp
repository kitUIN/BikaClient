#include "pch.h"
#include "Blocks.TagBlock.h"
#include "Blocks.TagBlock.g.cpp"


namespace winrt::BikaClient::Blocks::implementation
{
    TagBlock::TagBlock(hstring const& tag)
    {
        m_tag = tag;
    }
    hstring TagBlock::Tag()
    {
        return m_tag;
    }
    void TagBlock::Tag(hstring const& value)
    {
        m_tag = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Tag" });
    }
    hstring TagBlock::ID()
    {
        return m_id;
    }
    void TagBlock::ID(hstring const& value)
    {
        m_id = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"ID" });
    }
    winrt::event_token TagBlock::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void TagBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
