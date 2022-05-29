#pragma once

#include "SetPasswordPage.g.h"

namespace winrt::Demo::implementation
{
    struct SetPasswordPage : SetPasswordPageT<SetPasswordPage>
    {
        SetPasswordPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    private:
        Demo::MainPage rootPage{ MainPage::Current() };
        BikaClient::Responses::ComicsResponse m_res{ nullptr };
    };
}

namespace winrt::Demo::factory_implementation
{
    struct SetPasswordPage : SetPasswordPageT<SetPasswordPage, implementation::SetPasswordPage>
    {
    };
}
