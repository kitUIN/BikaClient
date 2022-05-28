#include "pch.h"
#include "LikePage.h"
#if __has_include("LikePage.g.cpp")
#include "LikePage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TestClient::implementation
{
    LikePage::LikePage()
    {
        InitializeComponent();
    }

    int32_t LikePage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void LikePage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction LikePage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Like(bookId().Text());
        ActionControl resp;
        resp.ResSet(res);
        MainStackPanel().Children().Append(resp);
    }
}
