#pragma once

#include "ComicsPage.g.h"

namespace winrt::Demo::implementation
{
    struct ComicsPage : ComicsPageT<ComicsPage>
    {
        ComicsPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        BikaClient::Responses::ComicsResponse Res();
        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        BikaClient::Responses::ComicsResponse m_res{ nullptr };
    };
}

namespace winrt::Demo::factory_implementation
{
    struct ComicsPage : ComicsPageT<ComicsPage, implementation::ComicsPage>
    {
    };
}
