#include "pch.h"
#include "GetReplyCommentPage.h"
#if __has_include("GetReplyCommentPage.g.cpp")
#include "GetReplyCommentPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    GetReplyCommentPage::GetReplyCommentPage()
    {
        InitializeComponent();
    }

    int32_t GetReplyCommentPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void GetReplyCommentPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void GetReplyCommentPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
