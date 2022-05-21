#pragma once
#include "Responses.UserResponse.g.h"
#include "Blocks/Blocks.UserBlock.h"

namespace winrt::BikaClient::Responses::implementation
{
    struct UserResponse : UserResponseT<UserResponse>
    {
        UserResponse() = default;

        UserResponse(winrt::Windows::Data::Json::JsonObject const& json);
        UserResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        winrt::BikaClient::Blocks::UserBlock User();
        void User(winrt::BikaClient::Blocks::UserBlock const& value);
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
        int32_t m_code{ 0 };
        hstring m_message{ L"" };
        hstring m_error{ L"" };
        hstring m_detail{ L"" };
        hstring m_json{ L"" };
        winrt::BikaClient::Blocks::UserBlock m_user{ nullptr };
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct UserResponse : UserResponseT<UserResponse, implementation::UserResponse>
    {
    };
}
