#pragma once
#include "Responses.LoginResponse.g.h"

namespace winrt::BikaClient::Responses::implementation
{
    struct LoginResponse : LoginResponseT<LoginResponse>
    {
        LoginResponse() = default;

        LoginResponse(winrt::Windows::Data::Json::JsonObject const& json);
        hstring Token();
        int32_t Code();
        void Code(int32_t value);
        hstring Message();
        void Message(hstring const& value);
        hstring Error();
        void Error(hstring const& value);
        hstring Detail();
        void Detail(hstring const& value);
        hstring Json();
    private:
		hstring m_token = L"";
		int32_t m_code = 0;
		hstring m_message = L"";
		hstring m_error = L"";
		hstring m_detail = L"";
		hstring m_json = L"";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct LoginResponse : LoginResponseT<LoginResponse, implementation::LoginResponse>
    {
    };
}
