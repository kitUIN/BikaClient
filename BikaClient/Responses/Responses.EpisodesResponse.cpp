#include "pch.h"
#include "Responses.EpisodesResponse.h"
#include "Responses.EpisodesResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    EpisodesResponse::EpisodesResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
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


}
