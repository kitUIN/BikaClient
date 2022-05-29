#pragma once

#include "LikePage.g.h"

namespace winrt::Demo::implementation
{
    struct LikePage : LikePageT<LikePage>
    {
        LikePage();

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
    struct LikePage : LikePageT<LikePage, implementation::LikePage>
    {
    };
}
