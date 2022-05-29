#include "pch.h"
#include "BookInfoPage.h"
#if __has_include("BookInfoPage.g.cpp")
#include "BookInfoPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    BookInfoPage::BookInfoPage()
    {
        InitializeComponent();
    }

    int32_t BookInfoPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void BookInfoPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }


    winrt::Windows::Foundation::IAsyncAction BookInfoPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().BookInfo(bookId().Text());
        a.Append(res);
        Res().ItemsSource(box_value(a));
    }
}
