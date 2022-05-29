#pragma once

#include "GetReplyCommentPage.g.h"

namespace winrt::Demo::implementation
{
    struct GetReplyCommentPage : GetReplyCommentPageT<GetReplyCommentPage>
    {
        GetReplyCommentPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Demo::factory_implementation
{
    struct GetReplyCommentPage : GetReplyCommentPageT<GetReplyCommentPage, implementation::GetReplyCommentPage>
    {
    };
}
