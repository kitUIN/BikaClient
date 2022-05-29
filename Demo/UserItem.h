#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "UserItem.g.h"

namespace winrt::Demo::implementation
{
    struct UserItem : UserItemT<UserItem>
    {
        UserItem();

        winrt::BikaClient::Blocks::UserBlock Users();
        void Users(winrt::BikaClient::Blocks::UserBlock const& value);

        static Windows::UI::Xaml::DependencyProperty UsersProperty() { return m_actionsProperty; }

        static void OnActionsChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_actionsProperty;
    };
}

namespace winrt::Demo::factory_implementation
{
    struct UserItem : UserItemT<UserItem, implementation::UserItem>
    {
    };
}
