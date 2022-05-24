#include "pch.h"
#include "Utils.BikaSort.h"
#include "Utils.BikaSort.g.cpp"


namespace winrt::BikaClient::Utils::implementation
{
    BikaSort::BikaSort(winrt::BikaClient::Utils::SortMode const& sort)
    {
        if (sort == winrt::BikaClient::Utils::SortMode::UA) m_sort = L"ua";
        else if (sort == winrt::BikaClient::Utils::SortMode::DD) m_sort = L"dd";
        else if (sort == winrt::BikaClient::Utils::SortMode::DA) m_sort = L"da";
        else if (sort == winrt::BikaClient::Utils::SortMode::LD) m_sort = L"ld";
        else if (sort == winrt::BikaClient::Utils::SortMode::VD) m_sort = L"vd";
    }
    hstring BikaSort::Sort()
    {
        return m_sort;
    }
}
