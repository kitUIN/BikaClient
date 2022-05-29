#pragma once

#include "EpisodesPage.g.h"

namespace winrt::Demo::implementation
{
    struct EpisodesPage : EpisodesPageT<EpisodesPage>
    {
        EpisodesPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::EpisodesResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::EpisodesResponse>();

    };
}

namespace winrt::Demo::factory_implementation
{
    struct EpisodesPage : EpisodesPageT<EpisodesPage, implementation::EpisodesPage>
    {
    };
}
