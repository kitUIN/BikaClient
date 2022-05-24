#include "pch.h"
#include "Responses.UserResponse.h"
#include "Responses.UserResponse.g.cpp"

namespace winrt::BikaClient::Responses::implementation
{
    UserResponse::UserResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        UserResponse(json, DEFAULT_FILE_SERVER);
    }
    UserResponse::UserResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data"))
        {
            m_user = make<winrt::BikaClient::Blocks::implementation::UserBlock>(json.GetNamedObject(L"data").GetNamedObject(L"user"), fileServer);
        }
    }
    winrt::BikaClient::Blocks::UserBlock UserResponse::User()
    {
        return m_user;
    }
    void UserResponse::User(winrt::BikaClient::Blocks::UserBlock const& value)
    {
        m_user = value;
    }
    int32_t UserResponse::Code()
    {
        return m_code;
    }
    void UserResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring UserResponse::Message()
    {
        return m_message;
    }
    void UserResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring UserResponse::Error()
    {
        return m_error;
    }
    void UserResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring UserResponse::Detail()
    {
        return m_detail;
    }
    void UserResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring UserResponse::Json()
    {
        return m_json;
    }
}
