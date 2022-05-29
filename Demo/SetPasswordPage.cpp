#include "pch.h"
#include "SetPasswordPage.h"
#if __has_include("SetPasswordPage.g.cpp")
#include "SetPasswordPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    SetPasswordPage::SetPasswordPage()
    {
        InitializeComponent();
    }

    int32_t SetPasswordPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SetPasswordPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction SetPasswordPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {

        auto m_res = co_await rootPage.Bika().SetPassword(old().Text(), New().Text());
        ActionItem action;
        action.Actions(m_res);
        MainStackPanel().Children().Append(action);
    }
}
