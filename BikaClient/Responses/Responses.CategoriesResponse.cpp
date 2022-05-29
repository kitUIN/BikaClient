#include "pch.h"
#include "Responses.CategoriesResponse.h"
#include "Responses.CategoriesResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    CategoriesResponse::CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    CategoriesResponse::CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void CategoriesResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {

        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data")) {
            for (auto x : json.GetNamedObject(L"data").GetNamedArray(L"categories"))
            {
                m_categories.Append(winrt::make<winrt::BikaClient::Blocks::implementation::CategoriesBlock>(x.GetObject(), m_fileServer));
            }
        }
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> CategoriesResponse::Categories()
    {
        return m_categories;
    }
    void CategoriesResponse::Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> const& value)
    {
        m_categories = value;
    }
    int32_t CategoriesResponse::Code()
    {
        return m_code;
    }
    void CategoriesResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring CategoriesResponse::Message()
    {
        return m_message;
    }
    void CategoriesResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring CategoriesResponse::Error()
    {
        return m_error;
    }
    void CategoriesResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring CategoriesResponse::Detail()
    {
        return m_detail;
    }
    void CategoriesResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring CategoriesResponse::Json()
    {
        return m_json;
    }
}
