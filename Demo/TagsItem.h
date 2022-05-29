#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "TagsItem.g.h"

namespace winrt::Demo::implementation
{
    struct TagsItem : TagsItemT<TagsItem>
    {
        TagsItem();
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Tags();
        void Tags(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);

        static Windows::UI::Xaml::DependencyProperty TagsProperty() { return m_tagsProperty; }

        static void OnActionsChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_tagsProperty;
    };
}

namespace winrt::Demo::factory_implementation
{
    struct TagsItem : TagsItemT<TagsItem, implementation::TagsItem>
    {
    };
}
