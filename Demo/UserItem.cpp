#include "pch.h"
#include "UserItem.h"
#if __has_include("UserItem.g.cpp")
#include "UserItem.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    Windows::UI::Xaml::DependencyProperty UserItem::m_actionsProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Users",
            winrt::xaml_typename<winrt::BikaClient::Blocks::UserBlock>(),
            winrt::xaml_typename<Demo::UserItem>(),
            Windows::UI::Xaml::PropertyMetadata{ nullptr }
    );
    UserItem::UserItem()
    {
        DefaultStyleKey(winrt::box_value(L"Demo.UserItem"));
        InitializeComponent();
    }

    winrt::BikaClient::Blocks::UserBlock UserItem::Users()
    {
        return winrt::unbox_value<winrt::BikaClient::Blocks::UserBlock>(GetValue(m_actionsProperty));
    }

    void UserItem::Users(winrt::BikaClient::Blocks::UserBlock const& value)
    {
        SetValue(m_actionsProperty, winrt::box_value(value));
    }
}