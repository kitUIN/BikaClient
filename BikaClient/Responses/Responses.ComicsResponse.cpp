#include "pch.h"
#include "Responses.ComicsResponse.h"
#include "Responses.ComicsResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    ComicsResponse::ComicsResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    ComicsResponse::ComicsResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void ComicsResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
        if (json.HasKey(L"data"))
        {
            JsonObject data = json.GetNamedObject(L"data");
            IJsonValue comics = data.Lookup(L"comics");
            if (comics.ValueType() == JsonValueType::Array)
            {
                for (auto x : comics.GetArray())
                {
                    m_comics.Append(winrt::make<winrt::BikaClient::Blocks::implementation::ComicBlock>(x.GetObject(), m_fileServer));
                }
            }
            else
            {
                JsonObject comic = comics.GetObject();
                if (comic.HasKey(L"total")) m_total = static_cast<int32_t>(comic.GetNamedNumber(L"total"));
                if (comic.HasKey(L"limit")) m_limit = static_cast<int32_t>(comic.GetNamedNumber(L"limit"));
                if (comic.HasKey(L"page")) m_page = static_cast<int32_t>(comic.GetNamedNumber(L"page"));
                if (comic.HasKey(L"pages")) m_pages = static_cast<int32_t>(comic.GetNamedNumber(L"pages"));
                for (auto x : comic.GetNamedArray(L"docs"))
                {
                    m_comics.Append(winrt::make<winrt::BikaClient::Blocks::implementation::ComicBlock>(x.GetObject(), m_fileServer));
                }
            }
        }
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ComicBlock> ComicsResponse::Comics()
    {
        return m_comics;
    }
    void ComicsResponse::Comics(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ComicBlock> const& value)
    {
        m_comics = value;
    }


}
