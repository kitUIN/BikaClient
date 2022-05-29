#include "pch.h"
#include "Responses.BookInfoResponse.h"
#include "Responses.BookInfoResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    BookInfoResponse::BookInfoResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    BookInfoResponse::BookInfoResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
		m_fileServer = fileServer;
        Init(json);
    }
    void BookInfoResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data")) {
            m_bookInfos = make<winrt::BikaClient::Blocks::implementation::BookBlock>(json.GetNamedObject(L"data").GetNamedObject(L"comic"), m_fileServer);
        }
    }
    winrt::BikaClient::Blocks::BookBlock BookInfoResponse::BookInfos()
    {
        return m_bookInfos;
    }
    void BookInfoResponse::BookInfos(winrt::BikaClient::Blocks::BookBlock const& value)
    {
        m_bookInfos = value;
    }
    int32_t BookInfoResponse::Code()
    {
        return m_code;
    }
    void BookInfoResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring BookInfoResponse::Message()
    {
        return m_message;
    }
    void BookInfoResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring BookInfoResponse::Error()
    {
        return m_error;
    }
    void BookInfoResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring BookInfoResponse::Detail()
    {
        return m_detail;
    }
    void BookInfoResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring BookInfoResponse::Json()
    {
        return m_json;
    }
}
