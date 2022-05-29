#include "pch.h"
#include "Responses.CommentsResponse.h"
#include "Responses.CommentsResponse.g.cpp"


using namespace winrt;
using namespace Windows::Data::Json;

namespace winrt::BikaClient::Responses::implementation
{
    CommentsResponse::CommentsResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    CommentsResponse::CommentsResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void CommentsResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"code")) m_code = static_cast<int32_t>(json.GetNamedNumber(L"code"));
        if (json.HasKey(L"message")) m_message = json.GetNamedString(L"message");
        if (json.HasKey(L"error")) m_error = json.GetNamedString(L"error");
        if (json.HasKey(L"detail")) m_detail = json.GetNamedString(L"detail");
        if (json.HasKey(L"data"))
        {
            JsonObject data = json.GetNamedObject(L"data");
            if (data.HasKey(L"topComments"))
            {
                for (auto x : data.GetNamedArray(L"topComments"))
                {
                    m_topComments.Append(winrt::make<winrt::BikaClient::Blocks::implementation::CommentBlock>(x.GetObject(), m_fileServer));
                }
            }
            JsonObject comments = data.GetNamedObject(L"comments");
            for (auto y : comments.GetNamedArray(L"docs"))
            {
                m_comments.Append(winrt::make<winrt::BikaClient::Blocks::implementation::CommentBlock>(y.GetObject(), m_fileServer));
            }
            if (comments.HasKey(L"total")) m_total = static_cast<int32_t>(comments.GetNamedNumber(L"total"));
            if (comments.HasKey(L"limit")) m_limit = static_cast<int32_t>(comments.GetNamedNumber(L"limit"));
            if (comments.HasKey(L"page")) m_page = atoi(to_string(comments.GetNamedString(L"page")).c_str());
            if (comments.HasKey(L"pages")) m_pages = static_cast<int32_t>(comments.GetNamedNumber(L"pages"));
        }
    }

    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> CommentsResponse::Comments()
    {
        return m_comments;
    }
    void CommentsResponse::Comments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value)
    {
        m_comments = value;
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> CommentsResponse::TopComments()
    {
        return m_topComments;
    }
    void CommentsResponse::TopComments(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CommentBlock> const& value)
    {
        m_topComments = value;
    }
    int32_t CommentsResponse::Page()
    {
        return m_page;
    }
    void CommentsResponse::Page(int32_t value)
    {
        m_page = value;
    }
    int32_t CommentsResponse::Pages()
    {
        return m_pages;
    }
    void CommentsResponse::Pages(int32_t value)
    {
        m_pages = value;
    }
    int32_t CommentsResponse::Total()
    {
        return m_total;
    }
    void CommentsResponse::Total(int32_t value)
    {
        m_total = value;
    }
    int32_t CommentsResponse::Limit()
    {
        return m_limit;
    }
    void CommentsResponse::Limit(int32_t value)
    {
        m_limit = value;
    }
    int32_t CommentsResponse::Code()
    {
        return m_code;
    }
    void CommentsResponse::Code(int32_t value)
    {
        m_code = value;
    }
    hstring CommentsResponse::Message()
    {
        return m_message;
    }
    void CommentsResponse::Message(hstring const& value)
    {
        m_message = value;
    }
    hstring CommentsResponse::Error()
    {
        return m_error;
    }
    void CommentsResponse::Error(hstring const& value)
    {
        m_error = value;
    }
    hstring CommentsResponse::Detail()
    {
        return m_detail;
    }
    void CommentsResponse::Detail(hstring const& value)
    {
        m_detail = value;
    }
    hstring CommentsResponse::Json()
    {
        return m_json;
    }
}
