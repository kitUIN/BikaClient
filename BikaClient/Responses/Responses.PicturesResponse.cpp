#include "pch.h"
#include "Responses.PicturesResponse.h"
#include "Responses.PicturesResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    PicturesResponse::PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    PicturesResponse::PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void PicturesResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
        if (json.HasKey(L"data"))
        {
            JsonObject data = json.GetNamedObject(L"data").GetNamedObject(L"pages");
            if (data.HasKey(L"total")) m_total = static_cast<int32_t>(data.GetNamedNumber(L"total"));
            if (data.HasKey(L"limit")) m_limit = static_cast<int32_t>(data.GetNamedNumber(L"limit"));
            if (data.HasKey(L"page")) m_page = static_cast<int32_t>(data.GetNamedNumber(L"page"));
            if (data.HasKey(L"pages")) m_pages = static_cast<int32_t>(data.GetNamedNumber(L"pages"));
            for (auto x : data.GetNamedArray(L"docs"))
            {
                m_pictures.Append(winrt::make<winrt::BikaClient::Blocks::implementation::ImageBlock>(x.GetObject(), m_fileServer));
            }
            if (json.GetNamedObject(L"data").HasKey(L"ep")) m_episode = winrt::make < winrt::BikaClient::Blocks::implementation::EpisodeBlock>(json.GetNamedObject(L"data").GetNamedObject(L"ep"));
        }
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> PicturesResponse::Pictures()
    {
        return m_pictures;
    }
    void PicturesResponse::Pictures(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> const& value)
    {
        m_pictures = value;
    }
    winrt::BikaClient::Blocks::EpisodeBlock PicturesResponse::Episode()
    {
        return m_episode;
    }
    void PicturesResponse::Episode(winrt::BikaClient::Blocks::EpisodeBlock const& value)
    {
        m_episode = value;
    }

}
