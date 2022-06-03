#include "pch.h"
#include "Responses.KeywordsResponse.h"
#include "Responses.KeywordsResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    KeywordsResponse::KeywordsResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
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
}
