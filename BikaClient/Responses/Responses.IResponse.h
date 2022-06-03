#pragma once
#include "Responses.IResponse.g.h"


namespace winrt::BikaClient::Responses::implementation
{
    struct IResponse : IResponseT<IResponse>
    {
        IResponse() = default;

        IResponse(winrt::Windows::Data::Json::JsonObject const& json);
        void IInit(winrt::Windows::Data::Json::JsonObject const& json);
        int32_t Code();
        hstring Message();
        hstring Error();
        hstring Detail();
        hstring Json();
        int32_t m_code = 0;
        hstring m_message = L"";
        hstring m_error = L"";
        hstring m_detail = L"";
        hstring m_json = L"";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct IResponse : IResponseT<IResponse, implementation::IResponse>
    {
    };
}
