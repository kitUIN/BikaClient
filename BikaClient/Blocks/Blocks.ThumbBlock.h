#pragma once
#include "Blocks.ThumbBlock.g.h"

namespace winrt::BikaClient::Blocks::implementation
{
    struct ThumbBlock : ThumbBlockT<ThumbBlock>
    {
        ThumbBlock() = default;

        ThumbBlock(winrt::Windows::Data::Json::JsonObject const& json);
        ThumbBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        hstring FileServer();
        void FileServer(hstring const& value);
        winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage Img();
        void Img(winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage const& value);
        hstring Path();
        void Path(hstring const& value);
        hstring Url();
        hstring OriginalName();
        void OriginalName(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    private:
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
		winrt::Windows::UI::Xaml::Media::Imaging::BitmapImage m_img;
        hstring m_path = L"";
		hstring m_originalName = L"";
		hstring m_url = L"";
	};
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct ThumbBlock : ThumbBlockT<ThumbBlock, implementation::ThumbBlock>
    {
    };
}
