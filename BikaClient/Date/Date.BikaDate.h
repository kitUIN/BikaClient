#pragma once
#include "Date.BikaDate.g.h"

namespace winrt::BikaClient::Date::implementation
{
    struct BikaDate : BikaDateT<BikaDate>
    {
        BikaDate() = default;

        BikaDate(hstring const& date);
        BikaDate(hstring const& date, BikaClient::Date::TimeZone const& zone);
        hstring GetTime();
        hstring GetTimeZoneString();
        BikaClient::Date::TimeZone GetTimeZone();
        void SetTimeZone(BikaClient::Date::TimeZone const& zone);
        hstring GetDateTime();
        hstring GetDateTime(BikaClient::Date::TimeZone const& zone);
        hstring Raw();
    private:
        hstring m_raw = L"";
        BikaClient::Date::TimeZone m_zone = BikaClient::Date::TimeZone::UTC8;
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
