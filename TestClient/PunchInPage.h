#pragma once

#include "PunchInPage.g.h"

namespace winrt::TestClient::implementation
{
    struct PunchInPage : PunchInPageT<PunchInPage>
    {
        PunchInPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        TestClient::MainPage rootPage{ MainPage::Current() };

    };
}

namespace winrt::TestClient::factory_implementation
{
    struct PunchInPage : PunchInPageT<PunchInPage, implementation::PunchInPage>
    {
    };
}
