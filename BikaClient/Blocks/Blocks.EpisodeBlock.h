#pragma once
#include "Blocks.EpisodeBlock.g.h"
#include "Date/Date.BikaDate.h"

namespace winrt::BikaClient::Blocks::implementation
{
    struct EpisodeBlock : EpisodeBlockT<EpisodeBlock>
    {
        EpisodeBlock() = default;

        EpisodeBlock(winrt::Windows::Data::Json::JsonObject const& json);
        hstring ID();
        void ID(hstring const& value);
        winrt::BikaClient::Date::BikaDate UpdatedAt();
        void UpdatedAt(winrt::BikaClient::Date::BikaDate const& value);
        int32_t Order();
        void Order(int32_t value);
        hstring Title();
        void Title(hstring const& value);
        hstring BookId();
        void BookId(hstring const& value);
        int32_t Total();
        void Total(int32_t value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    private:
		hstring m_id = L"";
        winrt::BikaClient::Date::BikaDate m_updatedAt;
		int32_t m_order = 0;
		hstring m_title = L"";
		hstring m_bookId = L"";
		int32_t m_total = 0;
		winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		hstring m_json = L"";
	};
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct EpisodeBlock : EpisodeBlockT<EpisodeBlock, implementation::EpisodeBlock>
    {
    };
}
