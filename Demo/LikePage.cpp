#include "pch.h"
#include "LikePage.h"
#if __has_include("LikePage.g.cpp")
#include "LikePage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
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
        auto m_res = co_await rootPage.Bika().Like(bookId().Text());
        ActionItem action;
        action.Actions(m_res);
        MainStackPanel().Children().Append(action);
    }
}
