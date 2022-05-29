#include "pch.h"
#include "TagsItem.h"
#if __has_include("TagsItem.g.cpp")
#include "TagsItem.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    Windows::UI::Xaml::DependencyProperty TagsItem::m_tagsProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Tags",
            winrt::xaml_typename<winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock>>(),
            winrt::xaml_typename<Demo::TagsItem>(),
            Windows::UI::Xaml::PropertyMetadata{ nullptr }
    );
    TagsItem::TagsItem()
    {
        DefaultStyleKey(winrt::box_value(L"Demo.TagsItem"));
        InitializeComponent();
    }

    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> TagsItem::Tags()
    {
        return winrt::unbox_value<winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock>>(GetValue(m_tagsProperty));
    }

    void TagsItem::Tags(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value)
    {
        SetValue(m_tagsProperty, winrt::box_value(value));
    }
}
