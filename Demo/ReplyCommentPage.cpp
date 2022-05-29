#include "pch.h"
#include "ReplyCommentPage.h"
#if __has_include("ReplyCommentPage.g.cpp")
#include "ReplyCommentPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    ReplyCommentPage::ReplyCommentPage()
    {
        InitializeComponent();
    }

    int32_t ReplyCommentPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ReplyCommentPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void ReplyCommentPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
