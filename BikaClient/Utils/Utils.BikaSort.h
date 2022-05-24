#pragma once
#include "Utils.BikaSort.g.h"


namespace winrt::BikaClient::Utils::implementation
{
    struct BikaSort : BikaSortT<BikaSort>
    {
        BikaSort() = default;

        BikaSort(winrt::BikaClient::Utils::SortMode const& sort);
        hstring Sort();
    private:
        hstring m_sort = L"ua";
    };
}
namespace winrt::BikaClient::Utils::factory_implementation
{
    struct BikaSort : BikaSortT<BikaSort, implementation::BikaSort>
    {
    };
}
