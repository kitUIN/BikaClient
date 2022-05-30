#include "pch.h"
#include "KeywordsPage.h"
#if __has_include("KeywordsPage.g.cpp")
#include "KeywordsPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    KeywordsPage::KeywordsPage()
    {
        InitializeComponent();
    }

    int32_t KeywordsPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void KeywordsPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction KeywordsPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        
        auto res = co_await rootPage.Bika().Keywords();
        listView().ItemsSource(box_value(res.Keywords()));
    }
}
