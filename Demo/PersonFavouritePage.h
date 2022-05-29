#pragma once

#include "PersonFavouritePage.g.h"

namespace winrt::Demo::implementation
{
    struct PersonFavouritePage : PersonFavouritePageT<PersonFavouritePage>
    {
        PersonFavouritePage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::BookInfoResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::BookInfoResponse>();

    };
}

namespace winrt::Demo::factory_implementation
{
    struct PersonFavouritePage : PersonFavouritePageT<PersonFavouritePage, implementation::PersonFavouritePage>
    {
    };
}
