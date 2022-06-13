#include "pch.h"
#include "Blocks.CategoriesBlock.h"
#include "Blocks.CategoriesBlock.g.cpp"

namespace winrt::BikaClient::Blocks::implementation
{
    CategoriesBlock::CategoriesBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    CategoriesBlock::CategoriesBlock(winrt::Windows::Data::Json::JsonObject const& json,hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void CategoriesBlock::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"_id")) ID(json.GetNamedString(L"_id"));
        if (json.HasKey(L"title")) Title(json.GetNamedString(L"title"));
        if (json.HasKey(L"description")) Description(json.GetNamedString(L"description"));
        if (json.HasKey(L"active")) Active(json.GetNamedBoolean(L"active"));
        if (json.HasKey(L"isWeb")) IsWeb(json.GetNamedBoolean(L"isWeb"));
        if (json.HasKey(L"link")) Link(json.GetNamedString(L"link"));
        if (json.HasKey(L"thumb"))
        {
            m_thumb = make<winrt::BikaClient::Blocks::implementation::ImageBlock>(json.GetNamedObject(L"thumb"), m_fileServer);
        }
    }
    hstring CategoriesBlock::Title()
    {
        return m_title;
    }
    void CategoriesBlock::Title(hstring const& value)
    {
        m_title = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
    }
    winrt::BikaClient::Blocks::ImageBlock CategoriesBlock::Thumb()
    {
        return m_thumb;
    }
    void CategoriesBlock::Thumb(winrt::BikaClient::Blocks::ImageBlock const& value)
    {
        m_thumb = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Thumb" });
    }
    hstring CategoriesBlock::ID()
    {
        return m_id;
    }
    void CategoriesBlock::ID(hstring const& value)
    {
        m_id = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Id" });
    }
    bool CategoriesBlock::IsWeb()
    {
        return m_isWeb;
    }
    void CategoriesBlock::IsWeb(bool const& value)
    {
        m_isWeb = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"IsWeb" });
    }
    bool CategoriesBlock::IsAuto()
    {
        return m_isAuto;
    }
    void CategoriesBlock::IsAuto(bool const& value)
    {
        m_isAuto = value;
    }
    bool CategoriesBlock::Active()
    {
        return m_active;
    }
    void CategoriesBlock::Active(bool const& value)
    {
        m_active = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Active" });
    }
    hstring CategoriesBlock::Link()
    {
        return m_link;
    }
    void CategoriesBlock::Link(hstring const& value)
    {
        m_link = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Link" });
    }
    hstring CategoriesBlock::Description()
    {
        return m_description;
    }
    void CategoriesBlock::Description(hstring const& value)
    {
        m_description = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Description" });
    }
    hstring CategoriesBlock::Json()
    {
        return m_json;
    }
    winrt::event_token CategoriesBlock::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void CategoriesBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
