#pragma once

#include "PicturesPage.g.h"

namespace winrt::Demo::implementation
{
    struct PicturesPage : PicturesPageT<PicturesPage>
    {
        PicturesPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::PicturesResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::PicturesResponse>();

    };
}

namespace winrt::Demo::factory_implementation
{
    struct PicturesPage : PicturesPageT<PicturesPage, implementation::PicturesPage>
    {
    };
}
