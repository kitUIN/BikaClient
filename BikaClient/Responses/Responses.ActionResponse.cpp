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
        else
        {
            m_action = m_message;
        }
    }
    winrt::BikaClient::Responses::Actions ActionResponse::Action()
    {
        return ToAction(m_action);
    }
    winrt::BikaClient::Responses::Actions ActionResponse::ToAction(hstring const& action)
	{
		if(action == L"OK") return winrt::BikaClient::Responses::Actions::OK;
		else if(action == L"like") return winrt::BikaClient::Responses::Actions::Like;
		else if(action == L"un_like") return winrt::BikaClient::Responses::Actions::UnLike;
		else if(action == L"favourite") return winrt::BikaClient::Responses::Actions::Favourite;
		else if(action == L"un_favourite") return winrt::BikaClient::Responses::Actions::UnFavourite;
		else if(action == L"fail") return winrt::BikaClient::Responses::Actions::Fail;
		else if(action == L"success") return winrt::BikaClient::Responses::Actions::Success;
        else return winrt::BikaClient::Responses::Actions::Unknown;
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
