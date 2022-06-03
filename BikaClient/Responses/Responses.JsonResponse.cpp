#include "pch.h"
#include "Responses.JsonResponse.h"
#include "Responses.JsonResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    JsonResponse::JsonResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        IInit(json);
        if(json.HasKey(L"data")) m_data = json.GetNamedObject(L"data");
    }
    winrt::Windows::Data::Json::JsonObject JsonResponse::Data()
    {
        return m_data;
    }
    void JsonResponse::Data(winrt::Windows::Data::Json::JsonObject const& value)
    {
        m_data = value;
    }
}
