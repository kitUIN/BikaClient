#pragma once

#include "KeywordsPage.g.h"

namespace winrt::Demo::implementation
{
    struct KeywordsPage : KeywordsPageT<KeywordsPage>
    {
        KeywordsPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Demo::factory_implementation
{
    struct KeywordsPage : KeywordsPageT<KeywordsPage, implementation::KeywordsPage>
    {
    };
}
