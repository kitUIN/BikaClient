#pragma once

#include "MainPage.g.h"
#include "BlankUserControl.h"
namespace winrt::Demo::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        BikaClient::BikaHttpClient Bika();

        void MainList_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e);

    private:
        static Demo::MainPage current;
        BikaClient::BikaHttpClient bika;

    public:
        static Demo::MainPage Current() { return current; }
    };
}

namespace winrt::Demo::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
