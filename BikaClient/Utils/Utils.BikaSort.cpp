#include "pch.h"
#include "Utils.BikaSort.h"
#include "Utils.BikaSort.g.cpp"


namespace winrt::BikaClient::Utils::implementation
{
    BikaSort::BikaSort(winrt::BikaClient::Utils::SortMode const& sort)
    {
        m_sort = sort;
        m_sortString = ToSort(sort);
    }
    /// <summary>
    /// 获取原始文字
    /// </summary>
    /// <returns>原始</returns>
    hstring BikaSort::Sort()
    {
        return m_sortString;
    }
    hstring BikaSort::ToSort(winrt::BikaClient::Utils::SortMode const& sort)
    {
        if (sort == winrt::BikaClient::Utils::SortMode::DD) return L"dd";
        else if (sort == winrt::BikaClient::Utils::SortMode::DA) return L"da";
        else if (sort == winrt::BikaClient::Utils::SortMode::LD) return L"ld";
        else if (sort == winrt::BikaClient::Utils::SortMode::VD) return L"vd";
        else return L"ua";
    }
    winrt::BikaClient::Utils::SortMode BikaSort::SortMode()
    {
        return m_sort;
    }
    hstring BikaSort::SortResource()
    {
        return GetResource(m_sort);
    }
    hstring BikaSort::GetResource(winrt::BikaClient::Utils::SortMode const& sort)
    {
        if (sort == winrt::BikaClient::Utils::SortMode::DD) return L"sort/dd";
        else if (sort == winrt::BikaClient::Utils::SortMode::DA) return L"sort/da";
        else if (sort == winrt::BikaClient::Utils::SortMode::LD) return L"sort/ld";
        else if (sort == winrt::BikaClient::Utils::SortMode::VD) return L"sort/vd";
        else return L"sort/ua";
    }
    hstring BikaSort::SortName(winrt::Windows::ApplicationModel::Resources::ResourceLoader resourceLoader)
    {
        return resourceLoader.GetString(SortResource());
    }
    hstring BikaSort::ToString(winrt::BikaClient::Utils::SortMode const& sort,winrt::Windows::ApplicationModel::Resources::ResourceLoader resourceLoader)
    {
        return resourceLoader.GetString(GetResource(sort));
    }
}
