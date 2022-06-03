#include "pch.h"
#include "Responses.LoginResponse.h"
#include "Responses.LoginResponse.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    LoginResponse::LoginResponse(JsonObject const& json)
    {
        IInit(json);
        if (json.HasKey(L"data") && json.GetNamedObject(L"data").HasKey(L"token"))
        {
            m_token = json.GetNamedObject(L"data").GetNamedString(L"token");
        }

    }
    hstring LoginResponse::Token()
    {
        return m_token;
    }

}
