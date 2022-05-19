#pragma once
#include "Blocks.CategoriesBlock.g.h"


namespace winrt::BikaClient::Blocks::implementation
{
    struct CategoriesBlock : CategoriesBlockT<CategoriesBlock>
    {
        CategoriesBlock() = default;

        CategoriesBlock(winrt::Windows::Data::Json::JsonObject const& json);
        CategoriesBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        hstring Title();
        void Title(hstring const& value);
        winrt::BikaClient::Blocks::ThumbBlock Thumb();
        void Thumb(winrt::BikaClient::Blocks::ThumbBlock const& value);
        hstring Id();
        void Id(hstring const& value);
        bool IsWeb();
        void IsWeb(bool const& value);
        bool Active();
        void Active(bool const& value);
        hstring Link();
        void Link(hstring const& value);
        hstring Description();
        void Description(hstring const& value);
        hstring Json();
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        hstring m_title = L"";
        hstring m_id = L"";
        hstring m_link = L"";
        hstring m_description = L"";
        bool m_isWeb = false;
        bool m_active = false;
        hstring m_json = L"";
        winrt::BikaClient::Blocks::ThumbBlock m_thumb{ nullptr };
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct CategoriesBlock : CategoriesBlockT<CategoriesBlock, implementation::CategoriesBlock>
    {
    };
}
