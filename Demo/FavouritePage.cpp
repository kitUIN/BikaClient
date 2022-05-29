#include "pch.h"
#include "FavouritePage.h"
#if __has_include("FavouritePage.g.cpp")
#include "FavouritePage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    FavouritePage::FavouritePage()
    {
        InitializeComponent();
    }

    int32_t FavouritePage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void FavouritePage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction FavouritePage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto m_res = co_await rootPage.Bika().Favourite(bookId().Text());
        ActionItem action;
        action.Actions(m_res);
        MainStackPanel().Children().Append(action);
    }
}
