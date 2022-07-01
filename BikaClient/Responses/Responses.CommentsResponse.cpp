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
        IInit(json);
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
            if (comments.HasKey(L"total")) m_total = static_cast<int32_t>(comments.GetNamedNumber(L"total"));
            if (comments.HasKey(L"limit")) m_limit = static_cast<int32_t>(comments.GetNamedNumber(L"limit"));
            if (comments.HasKey(L"page")) m_page = atoi(to_string(comments.GetNamedString(L"page")).c_str());
            if (comments.HasKey(L"pages")) m_pages = static_cast<int32_t>(comments.GetNamedNumber(L"pages"));
            int32_t order = m_total;

            for (auto y : comments.GetNamedArray(L"docs"))
            {
                auto _comment = winrt::make<winrt::BikaClient::Blocks::implementation::CommentBlock>(y.GetObject(), m_fileServer);
                _comment.Order(order--);
                m_comments.Append(_comment);
            }

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

}
