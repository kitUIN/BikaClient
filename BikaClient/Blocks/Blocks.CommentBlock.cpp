#include "pch.h"
#include "Blocks.CommentBlock.h"
#include "Blocks.CommentBlock.g.cpp"


namespace winrt::BikaClient::Blocks::implementation
{
    CommentBlock::CommentBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    CommentBlock::CommentBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void CommentBlock::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"_id")) ID(json.GetNamedString(L"_id"));
        if (json.HasKey(L"_comic")) Comic(json.GetNamedString(L"_comic"));
        if (json.HasKey(L"content")) Content(json.GetNamedString(L"content"));
        if (json.HasKey(L"created_at")) CreatedAt(winrt::BikaClient::Date::BikaDate{ json.GetNamedString(L"created_at") });
        if (json.HasKey(L"hide")) Hide(winrt::BikaClient::Utils::BikaBoolean{ json.GetNamedBoolean(L"hide") });
        if (json.HasKey(L"isLiked")) IsLiked(winrt::BikaClient::Utils::BikaBoolean{ json.GetNamedBoolean(L"isLiked") });
        if (json.HasKey(L"isTop")) IsTop(winrt::BikaClient::Utils::BikaBoolean{ json.GetNamedBoolean(L"isTop") });
        if (json.HasKey(L"commentsCount")) CommentsCount(static_cast<int32_t>(json.GetNamedNumber(L"commentsCount")));
        if (json.HasKey(L"likesCount")) LikesCount(static_cast<int32_t>(json.GetNamedNumber(L"likesCount")));
        if (json.HasKey(L"_user")) m_user = winrt::make<winrt::BikaClient::Blocks::implementation::UserBlock>(json.GetNamedObject(L"_user"), m_fileServer);
    }
    hstring CommentBlock::ID()
    {
        return m_id;
    }
    void CommentBlock::ID(hstring const& value)
    {
        m_id = value;
    }
    hstring CommentBlock::Content()
    {
        return m_content;
    }
    void CommentBlock::Content(hstring const& value)
    {
        m_content = value;
    }
    hstring CommentBlock::Comic()
    {
        return m_comic;
    }
    void CommentBlock::Comic(hstring const& value)
    {
        m_comic = value;
    }
    winrt::BikaClient::Blocks::UserBlock CommentBlock::User()
    {
        return m_user;
    }
    void CommentBlock::User(winrt::BikaClient::Blocks::UserBlock const& value)
    {
        m_user = value;
    }
    winrt::BikaClient::Date::BikaDate CommentBlock::CreatedAt()
    {
       return m_createdAt;
    }
    void CommentBlock::CreatedAt(winrt::BikaClient::Date::BikaDate const& value)
    {
        m_createdAt = value;
    }
    int32_t CommentBlock::LikesCount()
    {
        return m_likesCount;
    }
    void CommentBlock::LikesCount(int32_t value)
    {
        m_likesCount = value;
    }
    int32_t CommentBlock::CommentsCount()
    {
        return m_commentsCount;
    }
    void CommentBlock::CommentsCount(int32_t value)
    {
        m_commentsCount = value;
    }
    winrt::BikaClient::Utils::BikaBoolean CommentBlock::IsTop()
    {
        return m_isTop;
    }
    void CommentBlock::IsTop(winrt::BikaClient::Utils::BikaBoolean const& value)
    {
        m_isTop = value;
    }
    winrt::BikaClient::Utils::BikaBoolean CommentBlock::Hide()
    {
        return m_hide;
    }
    void CommentBlock::Hide(winrt::BikaClient::Utils::BikaBoolean const& value)
    {
        m_hide = value;
    }
    winrt::BikaClient::Utils::BikaBoolean CommentBlock::IsLiked()
    {
        return m_isLiked;
    }
    void CommentBlock::IsLiked(winrt::BikaClient::Utils::BikaBoolean const& value)
    {
        m_isLiked = value;
    }
    hstring CommentBlock::BookId()
    {
        return m_bookId;
    }
    void CommentBlock::BookId(hstring const& value)
    {
        m_bookId = value;
    }
    hstring CommentBlock::Json()
    {
        return m_json;
    }
    winrt::event_token CommentBlock::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void CommentBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
