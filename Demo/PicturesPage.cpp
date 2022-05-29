#include "pch.h"
#include "PicturesPage.h"
#if __has_include("PicturesPage.g.cpp")
#include "PicturesPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    PicturesPage::PicturesPage()
    {
        InitializeComponent();
    }

    int32_t PicturesPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PicturesPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction PicturesPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Pictures(bookId().Text(), epsId().Value(), page().Value());
        OutputDebugStringW(L"\n\n");
        OutputDebugStringW(to_hstring(res.Code()).c_str());
        OutputDebugStringW(res.Message().c_str());
        a.Append(res);
        Res().ItemsSource(box_value(a));
    }
}
