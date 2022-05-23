#include "pch.h"
#include "Blocks.BookBlock.h"
#include "Blocks.BookBlock.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;
using namespace Windows::UI::Xaml;

namespace winrt::BikaClient::Blocks::implementation
{
    BookBlock::BookBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {
        BookBlock(json, DEFAULT_FILE_SERVER);
    }
    BookBlock::BookBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"_id")) m_id = json.GetNamedString(L"_id");
        if (json.HasKey(L"title")) m_title = json.GetNamedString(L"title");
        if(json.HasKey(L"_creator")) m_creater = winrt::make<winrt::BikaClient::Blocks::implementation::UserBlock>(json.GetNamedObject(L"_creator"), fileServer);
        if (json.HasKey(L"description")) m_description = json.GetNamedString(L"description");
        if (json.HasKey(L"author")) m_author = json.GetNamedString(L"author");
        if (json.HasKey(L"chineseTeam")) m_chineseTeam = json.GetNamedString(L"chineseTeam");
        if (json.HasKey(L"categories"))
        {
            for (auto x : json.GetNamedArray(L"categories"))
            {
                m_categories.Append(winrt::make<winrt::BikaClient::Blocks::implementation::TagBlock>(x.GetString()));
                m_categoriesString = m_categoriesString + x.GetString() + L"  ";
            }
        }
        if (json.HasKey(L"chineseTeam")) m_pagesCount =static_cast<int32_t>(json.GetNamedNumber(L"pagesCount"));
        if (json.HasKey(L"chineseTeam")) m_epsCount = static_cast<int32_t>(json.GetNamedNumber(L"epsCount"));
        if (json.HasKey(L"finished")) Finished(json.GetNamedBoolean(L"finished"));
        if (json.HasKey(L"updated_at")) m_updatedAt = winrt::BikaClient::Date::BikaDate(json.GetNamedString(L"updated_at"));
        if (json.HasKey(L"created_at")) m_createdAt = winrt::BikaClient::Date::BikaDate(json.GetNamedString(L"created_at"));
        if (json.HasKey(L"allowDownload")) m_allowDownload = json.GetNamedBoolean(L"allowDownload");
        if (json.HasKey(L"allowComment")) m_allowComment = json.GetNamedBoolean(L"allowComment");
        if (json.HasKey(L"totalLikes")) m_totalLikes = static_cast<int32_t>(json.GetNamedNumber(L"totalLikes"));
        if (json.HasKey(L"totalViews"))  m_totalViews = static_cast<int32_t>(json.GetNamedNumber(L"totalViews"));
        if (json.HasKey(L"viewsCount")) m_viewsCount = static_cast<int32_t>(json.GetNamedNumber(L"viewsCount"));
        if (json.HasKey(L"likesCount")) m_likesCount = static_cast<int32_t>(json.GetNamedNumber(L"likesCount"));
        if (json.HasKey(L"isFavourite")) m_isFavourite = json.GetNamedBoolean(L"isFavourite");
        if (json.HasKey(L"isLiked")) m_isLiked = json.GetNamedBoolean(L"isLiked");
        if (json.HasKey(L"commentsCount")) m_commentsCount = static_cast<int32_t>(json.GetNamedNumber(L"commentsCount"));
        if (json.HasKey(L"thumb")) m_thumb = make<winrt::BikaClient::Blocks::implementation::ImageBlock>(json.GetNamedObject(L"thumb"), fileServer);
    }
    hstring BookBlock::ID()
    {
        return m_id;
    }
    void BookBlock::ID(hstring const& value)
    {
        m_id = value;
    }
    hstring BookBlock::Title()
    {
        return m_title;
    }
    void BookBlock::Title(hstring const& value)
    {
        m_title = value;
    }
    winrt::BikaClient::Blocks::UserBlock BookBlock::Creater()
    {
        return m_creater;
    }
    void BookBlock::Creater(winrt::BikaClient::Blocks::UserBlock const& value)
    {
        m_creater = value;
    }
    hstring BookBlock::Description()
    {
        return m_description;
    }
    void BookBlock::Description(hstring const& value)
    {
        m_description = value;
    }
    winrt::BikaClient::Blocks::ImageBlock BookBlock::Thumb()
    {
        return m_thumb;
    }
    void BookBlock::Thumb(winrt::BikaClient::Blocks::ImageBlock const& value)
    {
        m_thumb = value;
    }
    hstring BookBlock::Author()
    {
        return m_author;
    }
    void BookBlock::Author(hstring const& value)
    {
        m_author = value;
    }
    hstring BookBlock::ChineseTeam()
    {
        return m_chineseTeam;
    }
    void BookBlock::ChineseTeam(hstring const& value)
    {
        m_chineseTeam = value;
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> BookBlock::Categories()
    {
        return m_categories;
    }
    void BookBlock::Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value)
    {
        m_categories = value;
    }
    hstring BookBlock::CategoriesString()
    {
        return m_categoriesString;
    }
    void BookBlock::CategoriesString(hstring const& value)
    {
        m_categoriesString = value;
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> BookBlock::Tags()
    {
        return m_tags;
    }
    void BookBlock::Tags(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value)
    {
        m_tags = value;
    }
    hstring BookBlock::TagsString()
    {
        return m_tagsString;
    }
    void BookBlock::TagsString(hstring const& value)
    {
        m_tagsString = value;
    }
    int32_t BookBlock::PagesCount()
    {
        return m_pagesCount;
    }
    void BookBlock::PagesCount(int32_t value)
    {
        m_pagesCount = value;
    }
    int32_t BookBlock::EpsCount()
    {
        return m_epsCount;
    }
    void BookBlock::EpsCount(int32_t value)
    {
        m_epsCount = value;
    }
    winrt::Windows::UI::Xaml::Visibility BookBlock::FinishedVisibility()
    {
        return m_finishedVisibility;
    }
    void BookBlock::FinishedVisibility(winrt::Windows::UI::Xaml::Visibility const& value)
    {
        m_finishedVisibility = value;
        if (value == Visibility::Collapsed) m_finished = false;
        else m_finished = true;
    }
    bool BookBlock::Finished()
    {
        return m_finished;
    }
    void BookBlock::Finished(bool value)
    {
        m_finished = value;
        if (value) m_finishedVisibility = Visibility::Collapsed;
        else m_finishedVisibility = Visibility::Visible;
    }
    winrt::BikaClient::Date::BikaDate BookBlock::UpdatedAt()
    {
        return m_updatedAt;
    }
    void BookBlock::UpdatedAt(winrt::BikaClient::Date::BikaDate const& value)
    {
        m_updatedAt = value;
    }
    winrt::BikaClient::Date::BikaDate BookBlock::CreatedAt()
    {
        return m_createdAt;
    }
    void BookBlock::CreatedAt(winrt::BikaClient::Date::BikaDate const& value)
    {
        m_createdAt = value;
    }
    bool BookBlock::AllowDownload()
    {
        return m_allowDownload;
    }
    void BookBlock::AllowDownload(bool value)
    {
        m_allowDownload = value;
    }
    bool BookBlock::AllowComment()
    {
        return m_allowComment;
    }
    void BookBlock::AllowComment(bool value)
    {
        m_allowComment = value;
    }
    int32_t BookBlock::TotalLikes()
    {
        return m_totalLikes;
    }
    void BookBlock::TotalLikes(int32_t value)
    {
        m_totalLikes = value;
    }
    int32_t BookBlock::TotalViews()
    {
        return m_totalViews;
    }
    void BookBlock::TotalViews(int32_t value)
    {
        m_totalViews = value;
    }
    int32_t BookBlock::ViewsCount()
    {
        return m_viewsCount;
    }
    void BookBlock::ViewsCount(int32_t value)
    {
        m_viewsCount = value;
    }
    int32_t BookBlock::LikesCount()
    {
        return m_likesCount;
    }
    void BookBlock::LikesCount(int32_t value)
    {
        m_likesCount = value;
    }
    bool BookBlock::IsFavourite()
    {
        return m_isFavourite;
    }
    void BookBlock::IsFavourite(bool value)
    {
        m_isFavourite = value;
    }
    bool BookBlock::IsLiked()
    {
        return m_isLiked;
    }
    void BookBlock::IsLiked(bool value)
    {
        m_isLiked = value;
    }
    int32_t BookBlock::CommentsCount()
    {
        return m_commentsCount;
    }
    void BookBlock::CommentsCount(int32_t value)
    {
        m_commentsCount = value;

    }
    hstring BookBlock::Json()
    {
        return m_json;
    }
    winrt::event_token BookBlock::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void BookBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
