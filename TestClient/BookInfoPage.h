#pragma once

#include "BookInfoPage.g.h"

namespace winrt::TestClient::implementation
{
    struct BookInfoPage : BookInfoPageT<BookInfoPage>
    {
        BookInfoPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        TestClient::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::BookInfoResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::BookInfoResponse>();

    };
}

namespace winrt::TestClient::factory_implementation
{
    struct BookInfoPage : BookInfoPageT<BookInfoPage, implementation::BookInfoPage>
    {
    };
}
