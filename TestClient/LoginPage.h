#pragma once

#include "LoginPage.g.h"

namespace winrt::TestClient::implementation
{
    struct LoginPage : LoginPageT<LoginPage>
    {
        LoginPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::TestClient::factory_implementation
{
    struct LoginPage : LoginPageT<LoginPage, implementation::LoginPage>
    {
    };
}
