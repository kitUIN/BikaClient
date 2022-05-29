#pragma once

#include "LoginPage.g.h"

namespace winrt::Demo::implementation
{
    struct LoginPage : LoginPageT<LoginPage>
    {
        LoginPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);


        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::LoginResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::LoginResponse>();

    };
}

namespace winrt::Demo::factory_implementation
{
    struct LoginPage : LoginPageT<LoginPage, implementation::LoginPage>
    {
    };
}
