#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "ImageItem.g.h"

namespace winrt::Demo::implementation
{
    struct ImageItem : ImageItemT<ImageItem>
    {
        ImageItem();
        winrt::BikaClient::Blocks::ImageBlock Thumb();
        void Thumb(winrt::BikaClient::Blocks::ImageBlock const& value);

        static Windows::UI::Xaml::DependencyProperty ThumbProperty() { return m_thumbProperty; }

        static void OnThumbChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_thumbProperty;
    };
}

namespace winrt::Demo::factory_implementation
{
    struct ImageItem : ImageItemT<ImageItem, implementation::ImageItem>
    {
    };
}
