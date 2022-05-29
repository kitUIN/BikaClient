#include "pch.h"
#include "ImageItem.h"
#if __has_include("ImageItem.g.cpp")
#include "ImageItem.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    Windows::UI::Xaml::DependencyProperty ImageItem::m_thumbProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Thumb",
            winrt::xaml_typename<winrt::BikaClient::Blocks::ImageBlock>(),
            winrt::xaml_typename<Demo::ImageItem>(),
            Windows::UI::Xaml::PropertyMetadata{ nullptr }
    );
    ImageItem::ImageItem()
    {
        DefaultStyleKey(winrt::box_value(L"Demo.ImageItem"));
        InitializeComponent();
    }

    winrt::BikaClient::Blocks::ImageBlock ImageItem::Thumb()
    {
        return winrt::unbox_value<winrt::BikaClient::Blocks::ImageBlock>(GetValue(m_thumbProperty));

    }

    void ImageItem::Thumb(winrt::BikaClient::Blocks::ImageBlock const& value)
    {
        SetValue(m_thumbProperty, winrt::box_value(value));
    }
}
