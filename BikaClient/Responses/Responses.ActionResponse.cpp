#include "pch.h"
#include "Responses.ActionResponse.h"
#include "Responses.ActionResponse.g.cpp"
using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    ActionResponse::ActionResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data")) {
            JsonObject data = json.GetNamedObject(L"data");
            if(data.HasKey(L"res")) m_action = data.GetNamedObject(L"res").GetNamedString(L"status");
            if(data.HasKey(L"action")) m_action = data.GetNamedString(L"action");
        }
    }
    hstring ActionResponse::Action()
    {
        return m_action;
    }
    void ActionResponse::Action(hstring const& value)
    {
        m_action = value;
    }
    int32_t ActionResponse::Code()
    {
        return m_code;
    }
    void ActionResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring ActionResponse::Message()
    {
        return m_message;
    }
    void ActionResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring ActionResponse::Error()
    {
        return m_error;
    }
    void ActionResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring ActionResponse::Detail()
    {
        return m_detail;
    }
    void ActionResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring ActionResponse::Json()
    {
        return m_json;
    }
}
