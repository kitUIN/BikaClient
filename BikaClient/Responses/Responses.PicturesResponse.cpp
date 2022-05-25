#include "pch.h"
#include "Responses.PicturesResponse.h"
#include "Responses.PicturesResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    PicturesResponse::PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        PicturesResponse(json, DEFAULT_FILE_SERVER);
    }
    PicturesResponse::PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data"))
        {
            JsonObject data = json.GetNamedObject(L"data").GetNamedObject(L"pages");
            if (data.HasKey(L"total")) m_total = static_cast<int32_t>(data.GetNamedNumber(L"total"));
            if (data.HasKey(L"limit")) m_limit = static_cast<int32_t>(data.GetNamedNumber(L"limit"));
            if (data.HasKey(L"page")) m_page = static_cast<int32_t>(data.GetNamedNumber(L"page"));
            if (data.HasKey(L"pages")) m_pages = static_cast<int32_t>(data.GetNamedNumber(L"pages"));
            for (auto x : data.GetNamedArray(L"docs"))
            {
                m_pictures.Append(winrt::make<winrt::BikaClient::Blocks::implementation::ImageBlock>(x.GetObject(), fileServer));
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
    int32_t PicturesResponse::Page()
    {
        return m_page;
    }
    void PicturesResponse::Page(int32_t value)
    {
        m_page = value;
    }
    int32_t PicturesResponse::Pages()
    {
        return m_pages;
    }
    void PicturesResponse::Pages(int32_t value)
    {
        m_pages = value;
    }
    int32_t PicturesResponse::Total()
    {
        return m_total;
    }
    void PicturesResponse::Total(int32_t value)
    {
        m_total = value;
    }
    int32_t PicturesResponse::Limit()
    {
        return m_limit;
    }
    void PicturesResponse::Limit(int32_t value)
    {
        m_limit = value;
    }
    int32_t PicturesResponse::Code()
    {
        return m_code;
    }
    void PicturesResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring PicturesResponse::Message()
    {
        return m_message;
    }
    void PicturesResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring PicturesResponse::Error()
    {
        return m_error;
    }
    void PicturesResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring PicturesResponse::Detail()
    {
        return m_detail;
    }
    void PicturesResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring PicturesResponse::Json()
    {
        return m_json;
    }
}
