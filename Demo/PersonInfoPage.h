#pragma once

#include "PersonInfoPage.g.h"

namespace winrt::Demo::implementation
{
    struct PersonInfoPage : PersonInfoPageT<PersonInfoPage>
    {
        PersonInfoPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::UserResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::UserResponse>();

    };
}

namespace winrt::Demo::factory_implementation
{
    struct PersonInfoPage : PersonInfoPageT<PersonInfoPage, implementation::PersonInfoPage>
    {
    };
}
