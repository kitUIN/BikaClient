#pragma once

#include "PersonInfoPage.g.h"

namespace winrt::Demo::implementation
{
    struct PersonInfoPage : PersonInfoPageT<PersonInfoPage>
    {
        PersonInfoPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        BikaClient::Blocks::UserBlock User();
        void User(BikaClient::Blocks::UserBlock const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::UserResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::UserResponse>();
        BikaClient::Blocks::UserBlock m_user{ nullptr };
    };
}

namespace winrt::Demo::factory_implementation
{
    struct PersonInfoPage : PersonInfoPageT<PersonInfoPage, implementation::PersonInfoPage>
    {
    };
}
