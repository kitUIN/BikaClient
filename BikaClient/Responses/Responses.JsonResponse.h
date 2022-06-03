#pragma once
#include "Responses.JsonResponse.g.h"
#include "Responses.IResponse.h"


namespace winrt::BikaClient::Responses::implementation
{
    struct JsonResponse : JsonResponseT<JsonResponse, BikaClient::Responses::implementation::IResponse>
    {
        JsonResponse() = default;

        JsonResponse(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Data::Json::JsonObject Data();
        void Data(winrt::Windows::Data::Json::JsonObject const& value);
    private:
        winrt::Windows::Data::Json::JsonObject m_data;
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct JsonResponse : JsonResponseT<JsonResponse, implementation::JsonResponse>
    {
    };
}
