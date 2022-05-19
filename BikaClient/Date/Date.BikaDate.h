#pragma once
#include "Date.BikaDate.g.h"

namespace winrt::BikaClient::Date::implementation
{
    struct BikaDate : BikaDateT<BikaDate>
    {
        BikaDate() = default;

        BikaDate(hstring const& date);
        hstring SetTimeZone();
        void SetTimeZone(hstring const& value);
        hstring GetDateTime();
        hstring Raw();
    private:
        hstring m_raw = L"";
        hstring m_timeZone = L"UTC+8";
        int32_t m_times = 8;
        hstring m_dateTime;
    };
}
namespace winrt::BikaClient::Date::factory_implementation
{
    struct BikaDate : BikaDateT<BikaDate, implementation::BikaDate>
    {
    };
}
