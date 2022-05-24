#include "pch.h"
#include "Blocks.EpisodeBlock.h"
#include "Blocks.EpisodeBlock.g.cpp"


namespace winrt::BikaClient::Blocks::implementation
{
    EpisodeBlock::EpisodeBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {

        if (json.HasKey(L"_id")) m_id = json.GetNamedString(L"_id");
        if (json.HasKey(L"updatedAt")) m_updatedAt = winrt::BikaClient::Date::BikaDate(json.GetNamedString(L"updatedAt"));
        if (json.HasKey(L"order")) m_order = static_cast<int32_t>(json.GetNamedNumber(L"_id"));
        if (json.HasKey(L"title")) m_title = json.GetNamedString(L"title");
    }
    hstring EpisodeBlock::ID()
    {
        return m_id;
    }
    void EpisodeBlock::ID(hstring const& value)
    {
        m_id = value;
    }
    winrt::BikaClient::Date::BikaDate EpisodeBlock::UpdatedAt()
    {
        return m_updatedAt;
    }
    void EpisodeBlock::UpdatedAt(winrt::BikaClient::Date::BikaDate const& value)
    {
        m_updatedAt = value;
    }
    int32_t EpisodeBlock::Order()
    {
        return m_order;
    }
    void EpisodeBlock::Order(int32_t value)
    {
        m_order = value;
    }
    hstring EpisodeBlock::Title()
    {
        return m_title;
    }
    void EpisodeBlock::Title(hstring const& value)
    {
        m_title = value;
    }
    hstring EpisodeBlock::BookId()
    {
        return m_bookId;
    }
    void EpisodeBlock::BookId(hstring const& value)
    {
        m_bookId = value;
    }
    int32_t EpisodeBlock::Total()
    {
        return m_total;
    }
    void EpisodeBlock::Total(int32_t value)
    {
        m_total = value;
    }
    hstring EpisodeBlock::Json()
    {
        return m_json;
    }
    winrt::event_token EpisodeBlock::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void EpisodeBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
