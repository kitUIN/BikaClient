#pragma once
#include "Blocks.CategoriesBlock.g.h"
#include "Blocks.ImageBlock.h"

namespace winrt::BikaClient::Blocks::implementation
{
    struct CategoriesBlock : CategoriesBlockT<CategoriesBlock>
    {
        CategoriesBlock() = default;

        CategoriesBlock(winrt::Windows::Data::Json::JsonObject const& json);
        CategoriesBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        hstring Title();
        void Title(hstring const& value);
        winrt::BikaClient::Blocks::ImageBlock Thumb();
        void Thumb(winrt::BikaClient::Blocks::ImageBlock const& value);
        hstring ID();
        void ID(hstring const& value);
        bool IsWeb();
        void IsWeb(bool const& value);
        bool IsAuto();
        void IsAuto(bool const& value);
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
        bool m_isAuto = true;
        hstring m_json = L"";
        winrt::BikaClient::Blocks::ImageBlock m_thumb;
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct CategoriesBlock : CategoriesBlockT<CategoriesBlock, implementation::CategoriesBlock>
    {
    };
}
