#include "pch.h"
#include "PersonCommentPage.h"
#if __has_include("PersonCommentPage.g.cpp")
#include "PersonCommentPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    PersonCommentPage::PersonCommentPage()
    {
        InitializeComponent();
    }

    int32_t PersonCommentPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PersonCommentPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction PersonCommentPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().PersonComment(page().Value());
        CommentItem comics;
        comics.Comments(res);
        MainStackPanel().Children().Append(comics);
    }
}
