#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "BlankUserControl.g.h"

namespace winrt::Demo::implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl>
    {
        BlankUserControl() {
            DefaultStyleKey(winrt::box_value(L"Demo.BlankUserControl"));
            InitializeComponent();
        };

        winrt::hstring Label()
        {
            return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
        }

        void Label(winrt::hstring const& value)
        {
            SetValue(m_labelProperty, winrt::box_value(value));
            //m_property_changed(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs(L"Label"));
        }

        static Windows::UI::Xaml::DependencyProperty LabelProperty() { return m_labelProperty; }

        static void OnLabelChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);
        winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        static Windows::UI::Xaml::DependencyProperty m_labelProperty;
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_property_changed;

    };
}

namespace winrt::Demo::factory_implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl, implementation::BlankUserControl>
    {
    };
}
