#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "ActionItem.g.h"

namespace winrt::Demo::implementation
{
    struct ActionItem : ActionItemT<ActionItem>
    {
        ActionItem();

        winrt::BikaClient::Responses::ActionResponse Actions();
        void Actions(winrt::BikaClient::Responses::ActionResponse const& value);

        static Windows::UI::Xaml::DependencyProperty ActionsProperty() { return m_actionsProperty; }

        static void OnActionsChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

    private:
        static Windows::UI::Xaml::DependencyProperty m_actionsProperty;
    };
}

namespace winrt::Demo::factory_implementation
{
    struct ActionItem : ActionItemT<ActionItem, implementation::ActionItem>
    {
    };
}
