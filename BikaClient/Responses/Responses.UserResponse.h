#pragma once
#include "Responses.UserResponse.g.h"
#include "Blocks/Blocks.UserBlock.h"
#include "Responses.IResponse.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct UserResponse : UserResponseT<UserResponse, BikaClient::Responses::implementation::IResponse>
    {
        UserResponse() = default;

        UserResponse(winrt::Windows::Data::Json::JsonObject const& json);
        UserResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::BikaClient::Blocks::UserBlock User();
        void User(winrt::BikaClient::Blocks::UserBlock const& value);
    private:
        winrt::BikaClient::Blocks::UserBlock m_user{ nullptr };
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct UserResponse : UserResponseT<UserResponse, implementation::UserResponse>
    {
    };
}
