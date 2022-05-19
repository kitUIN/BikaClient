#include "pch.h"
#include "Blocks.ThumbBlock.h"
#include "Blocks.ThumbBlock.g.cpp"
using namespace winrt;
using namespace winrt::Windows::Data::Json;
namespace winrt::BikaClient::Blocks::implementation
{
    ThumbBlock::ThumbBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {
        if(json.HasKey(L"path")) m_path = json.GetNamedString(L"path");
        if(json.HasKey(L"originalName")) m_originalName = json.GetNamedString(L"originalName");
        if(json.HasKey(L"fileServer")) m_fileServer = json.GetNamedString(L"fileServer");
        Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage{ Windows::Foundation::Uri{ m_fileServer + m_path} });
    }
    ThumbBlock::ThumbBlock(winrt::Windows::Data::Json::JsonObject const& json,hstring const& fileServer)
    {
        if (json.HasKey(L"path")) m_path = json.GetNamedString(L"path");
        if (json.HasKey(L"originalName")) m_originalName = json.GetNamedString(L"originalName");
        m_fileServer = fileServer;
        Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage{ Windows::Foundation::Uri{ m_fileServer + m_path} });
    }
    hstring ThumbBlock::FileServer()
    {
        return m_fileServer;
    }
    void ThumbBlock::FileServer(hstring const& value)
    {
        m_fileServer = value;
        Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage{ Windows::Foundation::Uri{ m_fileServer + m_path} });
    }
    winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage ThumbBlock::Img()
    {
        return m_img;
    }
    void ThumbBlock::Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage const& value)
    {
        m_img = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Tag" });
    }
    hstring ThumbBlock::Path()
    {
        return m_path;
    }
    void ThumbBlock::Path(hstring const& value)
    {
        m_path = value;
    }
    hstring ThumbBlock::Url()
    {
        return m_fileServer + m_path;
    }
    hstring ThumbBlock::OriginalName()
    {
        return m_originalName;
    }
    void ThumbBlock::OriginalName(hstring const& value)
    {
        m_originalName = value;
    }
    winrt::event_token ThumbBlock::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
       return m_propertyChanged.add(handler);
    }
    void ThumbBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
    hstring ThumbBlock::Json()
    {
        JsonObject json;
        json.Insert(L"fileServer",JsonValue::CreateStringValue(m_fileServer));
        json.Insert(L"path", JsonValue::CreateStringValue(m_path));
        json.Insert(L"originalName", JsonValue::CreateStringValue(m_originalName));
        return json.Stringify();
    }
}
