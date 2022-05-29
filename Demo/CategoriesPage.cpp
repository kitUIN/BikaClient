#include "pch.h"
#include "CategoriesPage.h"
#if __has_include("CategoriesPage.g.cpp")
#include "CategoriesPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    CategoriesPage::CategoriesPage()
    {
        InitializeComponent();
    }

    int32_t CategoriesPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void CategoriesPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction CategoriesPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Categories();
        a.Append(res);
        Res().ItemsSource(box_value(a));
    }
}
