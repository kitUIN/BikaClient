#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "CommentItem.g.h"

namespace winrt::Demo::implementation
{
    struct CommentItem : CommentItemT<CommentItem>
    {
        CommentItem();

        winrt::BikaClient::Responses::CommentsResponse Comments();
        void Comments(winrt::BikaClient::Responses::CommentsResponse const& value);

        static Windows::UI::Xaml::DependencyProperty CommentsProperty() { return m_commentsProperty; }

        static void OnActionsChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_commentsProperty;
    };
}

namespace winrt::Demo::factory_implementation
{
    struct CommentItem : CommentItemT<CommentItem, implementation::CommentItem>
    {
    };
}
