#include "pch.h"
#include "Responses.EpisodesResponse.h"
#include "Responses.EpisodesResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    EpisodesResponse::EpisodesResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data"))
        {
            JsonObject data = json.GetNamedObject(L"data").GetNamedObject(L"eps");
            if (data.HasKey(L"total")) m_total = static_cast<int32_t>(data.GetNamedNumber(L"total"));
            if (data.HasKey(L"limit")) m_limit = static_cast<int32_t>(data.GetNamedNumber(L"limit"));
            if (data.HasKey(L"page")) m_page = static_cast<int32_t>(data.GetNamedNumber(L"page"));
            if (data.HasKey(L"pages")) m_pages = static_cast<int32_t>(data.GetNamedNumber(L"pages"));
            for (auto x : data.GetNamedArray(L"docs"))
            {
                m_episodes.Append(winrt::make<winrt::BikaClient::Blocks::implementation::EpisodeBlock>(x.GetObject()));
            }
        }
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::EpisodeBlock> EpisodesResponse::Episodes()
    {
        return m_episodes;
    }
    void EpisodesResponse::Episodes(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::EpisodeBlock> const& value)
    {
        m_episodes = value;
    }
    int32_t EpisodesResponse::Page()
    {
        return m_page;
    }
    void EpisodesResponse::Page(int32_t value)
    {
        m_page = value;
    }
    int32_t EpisodesResponse::Pages()
    {
        return m_pages;
    }
    void EpisodesResponse::Pages(int32_t value)
    {
        m_pages = value;
    }
    int32_t EpisodesResponse::Total()
    {
        return m_total;
    }
    void EpisodesResponse::Total(int32_t value)
    {
        m_total = value;
    }
    int32_t EpisodesResponse::Limit()
    {
        return m_limit;
    }
    void EpisodesResponse::Limit(int32_t value)
    {
        m_limit = value;
    }
    int32_t EpisodesResponse::Code()
    {
        return m_code;
    }
    void EpisodesResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring EpisodesResponse::Message()
    {
        return m_message;
    }
    void EpisodesResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring EpisodesResponse::Error()
    {
        return m_error;
    }
    void EpisodesResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring EpisodesResponse::Detail()
    {
        return m_detail;
    }
    void EpisodesResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring EpisodesResponse::Json()
    {
        return m_json;
    }
}
