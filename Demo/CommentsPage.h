#pragma once

#include "CommentsPage.g.h"

namespace winrt::Demo::implementation
{
    struct CommentsPage : CommentsPageT<CommentsPage>
    {
        CommentsPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
    };
}

namespace winrt::Demo::factory_implementation
{
    struct CommentsPage : CommentsPageT<CommentsPage, implementation::CommentsPage>
    {
    };
}
