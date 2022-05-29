#include "pch.h"
#include "PersonFavouritePage.h"
#if __has_include("PersonFavouritePage.g.cpp")
#include "PersonFavouritePage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    PersonFavouritePage::PersonFavouritePage()
    {
        InitializeComponent();
    }

    int32_t PersonFavouritePage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PersonFavouritePage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction PersonFavouritePage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().PersonFavourite(BikaClient::Utils::SortMode::UA,page().Value());
        ComicItem comics;
        comics.Comics(res);
        MainStackPanel().Children().Append(comics);
    }
}
