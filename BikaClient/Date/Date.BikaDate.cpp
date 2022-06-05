/*****************************************************************//**
 * \file   BikaDate.cpp
 * \brief  内置不同时区的时间日期转换工具
 *
 * \author kulujun
 * \date   April 2022
 *********************************************************************/
#include "pch.h"
#include "Date.BikaDate.h"
#include "Date.BikaDate.g.cpp"
#pragma warning( disable : 4996 )
namespace winrt::BikaClient::Date::implementation
{
    BikaDate::BikaDate(hstring const& date)
    {
        m_raw = date;
        m_dateTime = GetTime();
    }
    BikaDate::BikaDate(hstring const& date,BikaClient::Date::TimeZone const& zone)
    {
        SetTimeZone(zone);
        m_raw = date;
        m_dateTime = GetTime();
    }
    hstring BikaDate::GetTime()
    {
        std::tm t;
        std::string dateTime = to_string(m_raw);
        hstring format = L"%Y-%b-%d %H:%M:%S";
        std::istringstream ss(dateTime.substr(0, 10) + " " + dateTime.substr(11, 8));
        ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S");
        time_t times = std::mktime(&t);
        times += 60 * 60 * m_times;
        std::wstringstream wss;
        wss << std::put_time(std::localtime(&times), L"%Y-%m-%d %H:%M:%S");
        return winrt::hstring{ wss.str() };

    }
    hstring BikaDate::GetTimeZoneString()
    {
        return m_timeZone;
    }
    BikaClient::Date::TimeZone BikaDate::GetTimeZone()
    {
        return m_zone;
    }
    void BikaDate::SetTimeZone(BikaClient::Date::TimeZone const& zone)
    {
        m_zone = zone;
        if (zone == BikaClient::Date::TimeZone::UTC12)         {  m_timeZone = L"UTC+12";    m_times = 12 ;}
        else if (zone == BikaClient::Date::TimeZone::UTC11  )  {  m_timeZone = L"UTC+11";    m_times = 11 ;}
        else if (zone == BikaClient::Date::TimeZone::UTC10  )  {  m_timeZone = L"UTC+10";    m_times = 10 ;}
        else if (zone == BikaClient::Date::TimeZone::UTC9   )  {  m_timeZone = L"UTC+9" ;    m_times = 9  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC8   )  {  m_timeZone = L"UTC+8" ;    m_times = 8  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC7   )  {  m_timeZone = L"UTC+7" ;    m_times = 7  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC6   )  {  m_timeZone = L"UTC+6" ;    m_times = 6  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC5   )  {  m_timeZone = L"UTC+5" ;    m_times = 5  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC4   )  {  m_timeZone = L"UTC+4" ;    m_times = 4  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC3   )  {  m_timeZone = L"UTC+3" ;    m_times = 3  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC2   )  {  m_timeZone = L"UTC+2" ;    m_times = 2  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC1   )  {  m_timeZone = L"UTC+1" ;    m_times = 1  ;}
        else if (zone == BikaClient::Date::TimeZone::UTC    )  {  m_timeZone = L"UTC"   ;    m_times = 0  ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN1  )  {  m_timeZone = L"UTC-1" ;    m_times = -1 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN2  )  {  m_timeZone = L"UTC-2" ;    m_times = -2 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN3  )  {  m_timeZone = L"UTC-3" ;    m_times = -3 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN4  )  {  m_timeZone = L"UTC-4" ;    m_times = -4 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN5  )  {  m_timeZone = L"UTC-5" ;    m_times = -5 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN6  )  {  m_timeZone = L"UTC-6" ;    m_times = -6 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN7  )  {  m_timeZone = L"UTC-7" ;    m_times = -7 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN8  )  {  m_timeZone = L"UTC-8" ;    m_times = -8 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN9  )  {  m_timeZone = L"UTC-9" ;    m_times = -9 ;}
        else if (zone == BikaClient::Date::TimeZone::UTCN10 )  {  m_timeZone = L"UTC-10";    m_times = -10;}
        else if (zone == BikaClient::Date::TimeZone::UTCN11 )  {  m_timeZone = L"UTC-11";    m_times = -11;}
        else if (zone == BikaClient::Date::TimeZone::UTCN12 )  {  m_timeZone = L"UTC-12";    m_times = -12;}
        m_dateTime = GetTime();
    }
    hstring BikaDate::GetDateTime()
    {
        return m_dateTime + L" (" + m_timeZone + L")";
    }
    hstring BikaDate::GetDateTime(BikaClient::Date::TimeZone const& zone)
    {
        SetTimeZone(zone);
        m_dateTime = GetTime();
        return m_dateTime;
    }
    hstring BikaDate::Raw()
    {
        return m_raw;
    }
}
