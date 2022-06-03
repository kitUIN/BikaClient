#include "pch.h"
#include "Utils.BikaSort.h"
#include "Utils.BikaSort.g.cpp"


namespace winrt::BikaClient::Utils::implementation
{
    BikaSort::BikaSort(winrt::BikaClient::Utils::SortMode const& sort)
    {
        m_sort = sort;
        if (sort == winrt::BikaClient::Utils::SortMode::DD) m_sortString = L"dd";
        else if (sort == winrt::BikaClient::Utils::SortMode::DA) m_sortString = L"da";
        else if (sort == winrt::BikaClient::Utils::SortMode::LD) m_sortString = L"ld";
        else if (sort == winrt::BikaClient::Utils::SortMode::VD) m_sortString = L"vd";
        else m_sortString = L"ua";
    }
    /// <summary>
    /// 获取原始文字
    /// </summary>
    /// <returns>原始</returns>
    hstring BikaSort::Sort()
    {
        return m_sortString;
    }
    winrt::BikaClient::Utils::SortMode BikaSort::SortMode()
    {
        return m_sort;
    }
    hstring BikaSort::SortResource()
    {
        if (m_sort == winrt::BikaClient::Utils::SortMode::DD) return L"sort/dd";
        else if (m_sort == winrt::BikaClient::Utils::SortMode::DA) return L"sort/da";
        else if (m_sort == winrt::BikaClient::Utils::SortMode::LD) return L"sort/ld";
        else if (m_sort == winrt::BikaClient::Utils::SortMode::VD) return L"sort/vd";
        else return L"sort/ua";

    }
    hstring BikaSort::SortName(winrt::Windows::ApplicationModel::Resources::ResourceLoader resourceLoader)
    {
        return resourceLoader.GetString(SortResource());
    }
}
