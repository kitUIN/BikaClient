﻿#include "pch.h"
#include "SendCommentPage.h"
#if __has_include("SendCommentPage.g.cpp")
#include "SendCommentPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    SendCommentPage::SendCommentPage()
    {
        InitializeComponent();
    }

    int32_t SendCommentPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SendCommentPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction SendCommentPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto m_res = co_await rootPage.Bika().SendComments(bookId().Text(), content().Text());
        ActionItem action;
        action.Actions(m_res);
        MainStackPanel().Children().Append(action);
    }
}
