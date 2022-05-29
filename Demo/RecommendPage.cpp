#include "pch.h"
#include "RecommendPage.h"
#if __has_include("RecommendPage.g.cpp")
#include "RecommendPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    RecommendPage::RecommendPage()
    {
        InitializeComponent();
    }

    int32_t RecommendPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void RecommendPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction RecommendPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Recommend(bookId().Text());
        ComicItem comics;
        comics.Comics(res);
        MainStackPanel().Children().Append(comics);
    }
}
