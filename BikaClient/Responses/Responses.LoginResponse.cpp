#include "pch.h"
#include "Responses.LoginResponse.h"
#include "Responses.LoginResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    LoginResponse::LoginResponse(JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data") && json.GetNamedObject(L"data").HasKey(L"token"))
        {
            m_token = json.GetNamedObject(L"data").GetNamedString(L"token");
        }

    }
    hstring LoginResponse::Token()
    {
        return m_token;
    }
    int32_t LoginResponse::Code()
    {
        return m_code;
    }
    void LoginResponse::Code(int32_t value)
    {
		m_code = value;
    }
    hstring LoginResponse::Message()
    {
        return m_message;
    }
    void LoginResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring LoginResponse::Error()
    {
        return m_error;
    }
    void LoginResponse::Error(hstring const& value)
    {
		m_error = value;
    }
    hstring LoginResponse::Detail()
    {
        return m_detail;
    }
    void LoginResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring LoginResponse::Json()
    {
        return m_json;
    }
}
