#include "pch.h"
#include "Blocks.ImageBlock.h"
#include "Blocks.ImageBlock.g.cpp"
using namespace winrt;
using namespace winrt::Windows::Data::Json;
namespace winrt::BikaClient::Blocks::implementation
{
    BikaClient::Blocks::ImageBlock ImageBlock::CreateImageBlock(winrt::Windows::Foundation::Uri const& uri)
    {
        ImageBlock imageBlock;
        imageBlock.Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage{ uri });
        return imageBlock;
    }
    ImageBlock::ImageBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {
        if (json.HasKey(L"_id"))
        {
            ID(json.GetNamedString(L"_id"));
            Init(json.GetNamedObject(L"media"));
        }
        else
        {
            Init(json);
        }
    }
    ImageBlock::ImageBlock(winrt::Windows::Data::Json::JsonObject const& json,hstring const& fileServer)
    {

        if (json.HasKey(L"_id"))
        {
            ID(json.GetNamedString(L"_id"));
            Init(json.GetNamedObject(L"media"), fileServer);
        }
        else
        {
            Init(json, fileServer);
        }
    }
    void ImageBlock::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json, L"https://storage1.picacomic.com/static/");
    }
    void ImageBlock::Init(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        if (json.HasKey(L"path")) Path(json.GetNamedString(L"path"));
        if (json.HasKey(L"originalName")) OriginalName(json.GetNamedString(L"originalName"));
        m_fileServer = fileServer;
        Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage{ Windows::Foundation::Uri{ m_fileServer + m_path} });
    }
    hstring ImageBlock::FileServer()
    {
        return m_fileServer;
    }
    void ImageBlock::FileServer(hstring const& value)
    {
        m_fileServer = value;
        Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage{ Windows::Foundation::Uri{ m_fileServer + m_path} });
    }
    hstring ImageBlock::ID()
    {
        return m_id;
    }
    void ImageBlock::ID(hstring const& value)
    {
        m_id = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"ID" });
    }
    winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage ImageBlock::Img()
    {
        return m_img;
    }
    void ImageBlock::Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage const& value)
    {
        m_img = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Img" });
    }
    hstring ImageBlock::Path()
    {
        return m_path;
    }
    void ImageBlock::Path(hstring const& value)
    {
        m_path = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Path" });
    }
    hstring ImageBlock::Url()
    {
        return m_fileServer + m_path;
    }
    hstring ImageBlock::OriginalName()
    {
        return m_originalName;
    }
    void ImageBlock::OriginalName(hstring const& value)
    {
        m_originalName = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"OriginalName" });
    }
    winrt::event_token ImageBlock::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
       return m_propertyChanged.add(handler);
    }
    void ImageBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
    hstring ImageBlock::Json()
    {
        JsonObject json;
        json.Insert(L"fileServer",JsonValue::CreateStringValue(m_fileServer));
        json.Insert(L"path", JsonValue::CreateStringValue(m_path));
        json.Insert(L"originalName", JsonValue::CreateStringValue(m_originalName));
        return json.Stringify();
    }
}
