﻿#include "pch.h"
#include "SetSloganPage.h"
#if __has_include("SetSloganPage.g.cpp")
#include "SetSloganPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TestClient::implementation
{
    SetSloganPage::SetSloganPage()
    {
        InitializeComponent();
    }

    int32_t SetSloganPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SetSloganPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction SetSloganPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().SetSlogan(Slogan().Text());
        ActionControl resp;
        resp.ResSet(res);
        MainStackPanel().Children().Append(resp);
    }
}
