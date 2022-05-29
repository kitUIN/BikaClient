#pragma once

#include "RecommendPage.g.h"

namespace winrt::Demo::implementation
{
    struct RecommendPage : RecommendPageT<RecommendPage>
    {
        RecommendPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
    };
}

namespace winrt::Demo::factory_implementation
{
    struct RecommendPage : RecommendPageT<RecommendPage, implementation::RecommendPage>
    {
    };
}
