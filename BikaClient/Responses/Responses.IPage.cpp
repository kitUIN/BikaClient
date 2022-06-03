#include "pch.h"
#include "Responses.IPage.h"
#include "Responses.IPage.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    int32_t IPage::Page()
    {
        return m_page;
    }
    int32_t IPage::Pages()
    {
        return m_pages;
    }
    int32_t IPage::Total()
    {
        return m_total;
    }
    int32_t IPage::Limit()
    {
        return m_limit;
    }

}
