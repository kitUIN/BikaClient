#include "pch.h"
#include "LoginPage.h"
#if __has_include("LoginPage.g.cpp")
#include "LoginPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TestClient::implementation
{
    LoginPage::LoginPage()
    {
        InitializeComponent();
    }

    int32_t LoginPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void LoginPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void LoginPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
