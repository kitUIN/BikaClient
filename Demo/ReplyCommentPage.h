#pragma once

#include "ReplyCommentPage.g.h"

namespace winrt::Demo::implementation
{
    struct ReplyCommentPage : ReplyCommentPageT<ReplyCommentPage>
    {
        ReplyCommentPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Demo::factory_implementation
{
    struct ReplyCommentPage : ReplyCommentPageT<ReplyCommentPage, implementation::ReplyCommentPage>
    {
    };
}
