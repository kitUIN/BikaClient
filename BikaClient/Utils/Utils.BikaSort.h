#pragma once
#include "Utils.BikaSort.g.h"


namespace winrt::BikaClient::Utils::implementation
{
    struct BikaSort : BikaSortT<BikaSort>
    {
        BikaSort() = default;

        BikaSort(winrt::BikaClient::Utils::SortMode const& sort);
        hstring Sort();
        winrt::BikaClient::Utils::SortMode SortMode();
        hstring SortResource();
        static hstring ToSort(winrt::BikaClient::Utils::SortMode const& sort);
        static hstring GetResource(winrt::BikaClient::Utils::SortMode const& sort);
        static hstring ToString(winrt::BikaClient::Utils::SortMode const& sort, winrt::Windows::ApplicationModel::Resources::ResourceLoader resourceLoader);
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
