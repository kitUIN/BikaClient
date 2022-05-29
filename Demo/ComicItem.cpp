#include "pch.h"
#include "ComicItem.h"
#if __has_include("ComicItem.g.cpp")
#include "ComicItem.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{

    Windows::UI::Xaml::DependencyProperty ComicItem::m_comicsProperty =
        Windows::UI::Xaml::DependencyProperty::Register(
            L"Comics",
            winrt::xaml_typename<winrt::BikaClient::Responses::ComicsResponse>(),
            winrt::xaml_typename<Demo::ComicItem>(),
            Windows::UI::Xaml::PropertyMetadata{ nullptr }
    );
    ComicItem::ComicItem()
    {
        DefaultStyleKey(winrt::box_value(L"Demo.ComicItem"));
        InitializeComponent();
    }

    winrt::BikaClient::Responses::ComicsResponse ComicItem::Comics()
    {
        return winrt::unbox_value<winrt::BikaClient::Responses::ComicsResponse>(GetValue(m_comicsProperty));
    }

    void ComicItem::Comics(winrt::BikaClient::Responses::ComicsResponse const& value)
    {
        SetValue(m_comicsProperty, winrt::box_value(value));
    }
}
