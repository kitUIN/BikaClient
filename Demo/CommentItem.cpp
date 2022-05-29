#include "pch.h"
#include "CommentItem.h"
#if __has_include("CommentItem.g.cpp")
#include "CommentItem.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    Windows::UI::Xaml::DependencyProperty CommentItem::m_commentsProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Comments",
            winrt::xaml_typename<winrt::BikaClient::Responses::CommentsResponse>(),
            winrt::xaml_typename<Demo::CommentItem>(),
            Windows::UI::Xaml::PropertyMetadata{ nullptr }
    );
    
    CommentItem::CommentItem()
    {
        DefaultStyleKey(winrt::box_value(L"Demo.CommentItem"));
        InitializeComponent();
    }

    winrt::BikaClient::Responses::CommentsResponse CommentItem::Comments()
    {
        return winrt::unbox_value<winrt::BikaClient::Responses::CommentsResponse>(GetValue(m_commentsProperty));
    }

    void CommentItem::Comments(winrt::BikaClient::Responses::CommentsResponse const& value)
    {
        SetValue(m_commentsProperty, winrt::box_value(value));
    }

}
