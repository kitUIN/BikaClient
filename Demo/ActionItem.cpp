﻿#include "pch.h"
#include "ActionItem.h"
#if __has_include("ActionItem.g.cpp")
#include "ActionItem.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
     Windows::UI::Xaml::DependencyProperty ActionItem::m_actionsProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Actions",
            winrt::xaml_typename<winrt::BikaClient::Responses::ActionResponse>(),
            winrt::xaml_typename<Demo::ActionItem>(),
            Windows::UI::Xaml::PropertyMetadata{ nullptr }
    );
    ActionItem::ActionItem()
    {
        DefaultStyleKey(winrt::box_value(L"Demo.ActionItem"));
        InitializeComponent();

    }

    winrt::BikaClient::Responses::ActionResponse ActionItem::Actions()
    {
        return winrt::unbox_value<winrt::BikaClient::Responses::ActionResponse>(GetValue(m_actionsProperty));
    }

    void ActionItem::Actions(winrt::BikaClient::Responses::ActionResponse const& value)
    {
        SetValue(m_actionsProperty, winrt::box_value(value));
        if (value.Action() == winrt::BikaClient::Responses::Actions::OK) Action().Text(L"OK");
        else if (value.Action() == winrt::BikaClient::Responses::Actions::Like) Action().Text(L"Like");
        else if (value.Action() == winrt::BikaClient::Responses::Actions::UnLike) Action().Text(L"UnLike");
        else if (value.Action() == winrt::BikaClient::Responses::Actions::Favourite) Action().Text(L"Favourite");
        else if (value.Action() == winrt::BikaClient::Responses::Actions::UnFavourite) Action().Text(L"UnFavourite");
        else if (value.Action() == winrt::BikaClient::Responses::Actions::Fail) Action().Text(L"Fail");
        else if (value.Action() == winrt::BikaClient::Responses::Actions::Success) Action().Text(L"Success");
        else Action().Text(L"Unknown");
    }
}
