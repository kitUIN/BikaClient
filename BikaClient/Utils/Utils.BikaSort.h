#pragma once
#include "Utils.BikaSort.g.h"


namespace winrt::BikaClient::Utils::implementation
{
    struct BikaSort : BikaSortT<BikaSort>
    {
        BikaSort() = default;

        BikaSort(winrt::BikaClient::Utils::SortMode const& sort);
        hstring Sort();
        hstring SortResource();
        hstring SortName(winrt::Windows::ApplicationModel::Resources::ResourceLoader resourceLoader);
    private:
        hstring m_sortString = L"ua";
        winrt::BikaClient::Utils::SortMode m_sort = winrt::BikaClient::Utils::SortMode::UA;
    };
}
namespace winrt::BikaClient::Utils::factory_implementation
{
    struct BikaSort : BikaSortT<BikaSort, implementation::BikaSort>
    {
    };
}
