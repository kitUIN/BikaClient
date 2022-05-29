#include "pch.h"
#include "EpisodesPage.h"
#if __has_include("EpisodesPage.g.cpp")
#include "EpisodesPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    EpisodesPage::EpisodesPage()
    {
        InitializeComponent();
    }

    int32_t EpisodesPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void EpisodesPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction EpisodesPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Episodes(bookId().Text(),page().Value());
        a.Append(res);
        Res().ItemsSource(box_value(a));
    }
}
