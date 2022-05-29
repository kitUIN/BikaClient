#include "pch.h"
#include "ComicsPage.h"
#if __has_include("ComicsPage.g.cpp")
#include "ComicsPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    ComicsPage::ComicsPage()
    {
        InitializeComponent();
    }

    int32_t ComicsPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ComicsPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    BikaClient::Responses::ComicsResponse ComicsPage::Res()
    {
        return m_res;
    }
    winrt::Windows::Foundation::IAsyncAction ComicsPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        m_res = co_await rootPage.Bika().Comics(static_cast<int32_t>(page().Value()), c().Text(), BikaClient::Utils::SortMode::UA);
        ComicItem comics;
        comics.Comics(m_res);
        MainStackPanel().Children().Append(comics);
    }
}
