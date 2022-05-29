#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "ComicItem.g.h"

namespace winrt::Demo::implementation
{
    struct ComicItem : ComicItemT<ComicItem>
    {
        ComicItem();
        winrt::BikaClient::Responses::ComicsResponse Comics();
        void Comics(winrt::BikaClient::Responses::ComicsResponse const& value);

        static Windows::UI::Xaml::DependencyProperty ComicsProperty() { return m_comicsProperty; }

        static void OnThumbChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_comicsProperty;
    };
}

namespace winrt::Demo::factory_implementation
{
    struct ComicItem : ComicItemT<ComicItem, implementation::ComicItem>
    {
    };
}
