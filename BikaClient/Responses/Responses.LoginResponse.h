#pragma once
#include "Responses.LoginResponse.g.h"
#include "Responses.IResponse.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct LoginResponse : LoginResponseT<LoginResponse, BikaClient::Responses::implementation::IResponse>
    {
        LoginResponse() = default;

        LoginResponse(winrt::Windows::Data::Json::JsonObject const& json);
        hstring Token();
    private:
        hstring m_token{ L"" };
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct LoginResponse : LoginResponseT<LoginResponse, implementation::LoginResponse>
    {
    };
}
