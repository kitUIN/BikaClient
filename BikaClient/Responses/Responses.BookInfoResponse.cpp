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
        IInit(json);
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
}
