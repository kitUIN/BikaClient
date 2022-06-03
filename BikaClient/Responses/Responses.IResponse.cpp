#include "pch.h"
#include "Responses.IResponse.h"
#include "Responses.IResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    IResponse::IResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
    }
    void IResponse::IInit(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
    }
    int32_t IResponse::Code()
    {
        return m_code;
    }
    hstring IResponse::Message()
    {
        return m_message;
    }
    hstring IResponse::Error()
    {
        return m_error;
    }
    hstring IResponse::Detail()
    {
        return m_detail;
    }
    hstring IResponse::Json()
    {
        return m_json;
    }
}
