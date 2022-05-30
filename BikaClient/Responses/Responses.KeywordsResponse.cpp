#include "pch.h"
#include "Responses.KeywordsResponse.h"
#include "Responses.KeywordsResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    KeywordsResponse::KeywordsResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data") && json.GetNamedObject(L"data").HasKey(L"keywords"))
        {
            for (auto x : json.GetNamedObject(L"data").GetNamedArray(L"keywords"))
            {
                m_keywords.Append(make<BikaClient::Blocks::implementation::TagBlock>(x.GetString()));
            }
        }
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> KeywordsResponse::Keywords()
    {
        return m_keywords;
    }
    void KeywordsResponse::Keywords(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value)
    {
        m_keywords = value;
    }
    int32_t KeywordsResponse::Code()
    {
        return m_code;
    }
    void KeywordsResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring KeywordsResponse::Message()
    {
        return m_message;
    }
    void KeywordsResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring KeywordsResponse::Error()
    {
        return m_error;
    }
    void KeywordsResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring KeywordsResponse::Detail()
    {
        return m_detail;
    }
    void KeywordsResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring KeywordsResponse::Json()
    {
        return m_json;
    }
}
