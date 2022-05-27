#pragma once

#include "MainPage.g.h"

namespace winrt::TestClient::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        void MainList_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e);
    
    private:
        static TestClient::MainPage current;
    public:
        static TestClient::MainPage Current() { return current; }
    };
}

namespace winrt::TestClient::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
