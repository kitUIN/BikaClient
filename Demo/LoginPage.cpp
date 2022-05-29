#include "pch.h"
#include "LoginPage.h"
#if __has_include("LoginPage.g.cpp")
#include "LoginPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
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

    winrt::Windows::Foundation::IAsyncAction LoginPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        if (token().Text() != L"") rootPage.Bika().Token(token().Text());
        else
        {
            auto res = co_await rootPage.Bika().Login(email().Text(), password().Text());
            a.Append(res);
            RES().ItemsSource(box_value(a));
        }

    }
}
