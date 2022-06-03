#pragma once
#include "Responses.ActionResponse.g.h"
#include "Responses.IResponse.h"

namespace winrt::BikaClient::Responses::implementation
{
    struct ActionResponse : ActionResponseT<ActionResponse, BikaClient::Responses::implementation::IResponse>
    {
        ActionResponse() = default;

        ActionResponse(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::BikaClient::Responses::Actions Action();
        winrt::BikaClient::Responses::Actions ToAction(hstring const& action);
    private:
		hstring m_action{ L"" };
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct ActionResponse : ActionResponseT<ActionResponse, implementation::ActionResponse>
    {
    };
}
