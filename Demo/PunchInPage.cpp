#include "pch.h"
#include "PunchInPage.h"
#if __has_include("PunchInPage.g.cpp")
#include "PunchInPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    PunchInPage::PunchInPage()
    {
        InitializeComponent();
    }

    int32_t PunchInPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PunchInPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction PunchInPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto m_res = co_await rootPage.Bika().PunchIn();
        ActionItem action;
        action.Actions(m_res);
        MainStackPanel().Children().Append(action);
    }
}
