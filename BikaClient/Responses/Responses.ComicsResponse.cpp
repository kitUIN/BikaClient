#include "pch.h"
#include "Responses.ComicsResponse.h"
#include "Responses.ComicsResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    ComicsResponse::ComicsResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        ComicsResponse(json, DEFAULT_FILE_SERVER);
    }
    ComicsResponse::ComicsResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data")) {
            JsonObject comics = json.GetNamedObject(L"data").GetNamedObject(L"comics");
            if (json.HasKey(L"total")) m_total = static_cast<int32_t>(json.GetNamedNumber(L"total"));
            if (json.HasKey(L"limit")) m_limit = static_cast<int32_t>(json.GetNamedNumber(L"limit"));
            if (json.HasKey(L"page")) m_page = static_cast<int32_t>(json.GetNamedNumber(L"page"));
            if (json.HasKey(L"pages")) m_pages = static_cast<int32_t>(json.GetNamedNumber(L"pages"));
            for (auto x : comics.GetNamedArray(L"docs"))
            {
                m_comics.Append(winrt::make<winrt::BikaClient::Blocks::implementation::ComicBlock>(x.GetObject(), fileServer));
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
