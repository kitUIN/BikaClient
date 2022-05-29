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
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
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
    int32_t ComicsResponse::Page()
    {
        return m_page;
    }
    void ComicsResponse::Page(int32_t value)
    {
        m_page = value;
    }
    int32_t ComicsResponse::Pages()
    {
        return m_pages;
    }
    void ComicsResponse::Pages(int32_t value)
    {
        m_pages = value;
    }
    int32_t ComicsResponse::Total()
    {
        return m_total;
    }
    void ComicsResponse::Total(int32_t value)
    {
        m_total = value;
    }
    int32_t ComicsResponse::Limit()
    {
        return m_limit;
    }
    void ComicsResponse::Limit(int32_t value)
    {
        m_limit = value;
    }
    int32_t ComicsResponse::Code()
    {
        return m_code;
    }
    void ComicsResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring ComicsResponse::Message()
    {
        return m_message;
    }
    void ComicsResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring ComicsResponse::Error()
    {
        return m_error;
    }
    void ComicsResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring ComicsResponse::Detail()
    {
        return m_detail;
    }
    void ComicsResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring ComicsResponse::Json()
    {
        return m_json;
    }
}
