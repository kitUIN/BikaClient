#pragma once
#include "Responses.IPage.g.h"

#include "Responses.IResponse.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct IPage : IPageT<IPage, BikaClient::Responses::implementation::IResponse>
    {
        IPage() = default;

        int32_t Page();
        int32_t Pages();
        int32_t Total();
        int32_t Limit();
        int32_t m_page = 0;
        int32_t m_pages = 0;
        int32_t m_total = 0;
        int32_t m_limit = 0;
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct IPage : IPageT<IPage, implementation::IPage>
    {
    };
}
