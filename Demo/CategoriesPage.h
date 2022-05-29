#pragma once

#include "CategoriesPage.g.h"

namespace winrt::Demo::implementation
{
    struct CategoriesPage : CategoriesPageT<CategoriesPage>
    {
        CategoriesPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::CategoriesResponse> a = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::CategoriesResponse>();

    };
}

namespace winrt::Demo::factory_implementation
{
    struct CategoriesPage : CategoriesPageT<CategoriesPage, implementation::CategoriesPage>
    {
    };
}
