#include "pch.h"
#include "PersonInfoPage.h"
#if __has_include("PersonInfoPage.g.cpp")
#include "PersonInfoPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    PersonInfoPage::PersonInfoPage()
    {
        InitializeComponent();
    }

    int32_t PersonInfoPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PersonInfoPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction PersonInfoPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().PersonInfo();
        a.Append(res);
        Res().ItemsSource(box_value(a));
    }
}
