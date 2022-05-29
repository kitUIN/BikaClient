#include "pch.h"
#include "BlankUserControl.h"
#if __has_include("BlankUserControl.g.cpp")
#include "BlankUserControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    Windows::UI::Xaml::DependencyProperty BlankUserControl::m_labelProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Label",
            winrt::xaml_typename<winrt::hstring>(),
            winrt::xaml_typename<Demo::BlankUserControl>(),
            Windows::UI::Xaml::PropertyMetadata{ winrt::box_value(L"default label"), Windows::UI::Xaml::PropertyChangedCallback{ &BlankUserControl::OnLabelChanged } }
    );
    void BlankUserControl::OnLabelChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&)
    {
    }
    winrt::event_token BlankUserControl::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_property_changed.add(handler);
    }
    void BlankUserControl::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_property_changed.remove(token);
    }
}
