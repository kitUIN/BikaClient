#include "pch.h"
#include "SearchPage.h"
#if __has_include("SearchPage.g.cpp")
#include "SearchPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    SearchPage::SearchPage()
    {
        InitializeComponent();
    }

    int32_t SearchPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SearchPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction SearchPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Search(static_cast<int32_t>(page().Value()), keyword().Text());
        ComicItem comics;
        comics.Comics(res);
        MainStackPanel().Children().Append(comics);
    }
}
