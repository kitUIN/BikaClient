#include "pch.h"
#include "Responses.UserResponse.h"
#include "Responses.UserResponse.g.cpp"

namespace winrt::BikaClient::Responses::implementation
{
    UserResponse::UserResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    UserResponse::UserResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void UserResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
        if (json.HasKey(L"data"))
        {
            m_user = make<winrt::BikaClient::Blocks::implementation::UserBlock>(json.GetNamedObject(L"data").GetNamedObject(L"user"), m_fileServer);
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
}
