#pragma once

#include "BookInfoPage.g.h"

namespace winrt::TestClient::implementation
{
    struct BookInfoPage : BookInfoPageT<BookInfoPage>
    {
        BookInfoPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::TestClient::factory_implementation
{
    struct BookInfoPage : BookInfoPageT<BookInfoPage, implementation::BookInfoPage>
    {
    };
}
