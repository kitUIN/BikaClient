#pragma once

#include "LoginPage.g.h"

namespace winrt::TestClient::implementation
{
    struct LoginPage : LoginPageT<LoginPage>
    {
        LoginPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        TestClient::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::LoginResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::LoginResponse>();

    };
}

namespace winrt::TestClient::factory_implementation
{
    struct LoginPage : LoginPageT<LoginPage, implementation::LoginPage>
    {
    };
}
