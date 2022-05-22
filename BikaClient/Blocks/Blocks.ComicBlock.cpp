#include "pch.h"
#include "Blocks.ComicBlock.h"
#include "Blocks.ComicBlock.g.cpp"

using namespace winrt;
using namespace Windows::Data::Json;
using namespace Windows::UI::Xaml;

namespace winrt::BikaClient::Blocks::implementation
{
    ComicBlock::ComicBlock(winrt::Windows::Data::Json::JsonObject const& json)
    {
        ComicBlock(json, to_hstring(DEFAULT_FILE_SERVER));
    }
    ComicBlock::ComicBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_json = json.Stringify();
        if (json.HasKey(L"_id")) m_id = json.GetNamedString(L"_id");
        if (json.HasKey(L"title")) m_title = json.GetNamedString(L"title");
        if (json.HasKey(L"author")) m_author = json.GetNamedString(L"author");
        if (json.HasKey(L"likesCount"))
        {
            IJsonValue x = json.Lookup(L"likesCount");
            if (x.ValueType() == winrt::Windows::Data::Json::JsonValueType::Number)
                m_likesCount = static_cast<int32_t>(x.GetNumber());
            else if (x.ValueType() == winrt::Windows::Data::Json::JsonValueType::String)
                m_likesCount = atoi(to_string(x.GetString()).c_str());
        }
        if (json.HasKey(L"totalLikes"))
        {
            IJsonValue y = json.Lookup(L"totalLikes");
            if (y.ValueType() == JsonValueType::Number)
                m_totalLikes = static_cast<int32_t>(y.GetNumber());
            else if (y.ValueType() == JsonValueType::String)
                m_totalLikes = atoi(to_string(y.GetString()).c_str());
        }
        if (json.HasKey(L"totalViews"))
        {
            IJsonValue z = json.Lookup(L"totalViews");
            if (z.ValueType() == JsonValueType::Number)
                m_totalViews = static_cast<int32_t>(z.GetNumber());
            else if (z.ValueType() == JsonValueType::String)
                m_totalLikes = atoi(to_string(z.GetString()).c_str());
        }
        if (json.HasKey(L"pagesCount")) m_pagesCount = static_cast<int32_t>(json.GetNamedNumber(L"pagesCount"));
        if (json.HasKey(L"epsCount")) m_epsCount = static_cast<int32_t>(json.GetNamedNumber(L"epsCount"));
        if (json.HasKey(L"finished")) Finished(json.GetNamedBoolean(L"finished"));
        if (json.HasKey(L"categories"))
        {
            for (auto x : json.GetNamedArray(L"categories"))
            {
                m_categories.Append(winrt::make<winrt::BikaClient::Blocks::implementation::TagBlock>(x.GetString()));
                m_categoriesString = m_categoriesString + x.GetString() + L" ";
            }
        }
        if (json.HasKey(L"thumb"))  m_thumb = make<winrt::BikaClient::Blocks::implementation::ImageBlock>(json.GetNamedObject(L"thumb"),fileServer);

    }
    hstring ComicBlock::Id()
    {
        return m_id;
    }
    void ComicBlock::Id(hstring const& value)
    {
        m_id = value;
    }
    hstring ComicBlock::Title()
    {
        return m_title;
    }
    void ComicBlock::Title(hstring const& value)
    {
        m_title = value;
    }
    hstring ComicBlock::Author()
    {
        return m_author;
    }
    void ComicBlock::Author(hstring const& value)
    {
        m_author = value;
    }
    int32_t ComicBlock::TotalViews()
    {
        return m_totalViews;
    }
    void ComicBlock::TotalViews(int32_t const& value)
    {
        m_totalViews = value;
    }
    int32_t ComicBlock::TotalLikes()
    {
        return m_totalLikes;
    }
    void ComicBlock::TotalLikes(int32_t const& value)
    {
        m_totalLikes = value;
    }
    int32_t ComicBlock::LikesCount()
    {
        return m_likesCount;
    }
    void ComicBlock::LikesCount(int32_t const& value)
    {
        m_likesCount = value;
    }
    int32_t ComicBlock::PagesCount()
    {
        return m_pagesCount;
    }
    void ComicBlock::PagesCount(int32_t const& value)
    {
        m_pagesCount = value;
    }
    int32_t ComicBlock::EpsCount()
    {
        return m_epsCount;
    }
    void ComicBlock::EpsCount(int32_t const& value)
    {
        m_epsCount = value;
    }
    winrt::BikaClient::Blocks::ImageBlock ComicBlock::Thumb()
    {
        return m_thumb;
    }
    void ComicBlock::Thumb(winrt::BikaClient::Blocks::ImageBlock const& value)
    {
        m_thumb = value;
    }
    winrt::Windows::UI::Xaml::Visibility ComicBlock::FinishedVisibility()
    {
        return m_finishedVisibility;
    }
    void ComicBlock::FinishedVisibility(winrt::Windows::UI::Xaml::Visibility const& value)
    {
        m_finishedVisibility = value;
        if (value == Visibility::Collapsed) m_finished = false;
        else m_finished = true;
    }
    bool ComicBlock::Finished()
    {
        return m_finished;
    }
    void ComicBlock::Finished(bool const& value)
    {
        m_finished = value;
        if (value) m_finishedVisibility = Visibility::Collapsed;
        else m_finishedVisibility = Visibility::Visible;
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> ComicBlock::Categories()
    {
        return m_categories;
    }
    void ComicBlock::Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value)
    {
        m_categories = value;
    }
    hstring ComicBlock::CategoriesString()
    {
		return m_categoriesString;
    }

    void ComicBlock::CategoriesString(hstring const& value)
    {
        m_categoriesString = value;
    }
    winrt::event_token ComicBlock::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void ComicBlock::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
    hstring ComicBlock::Json()
    {
        return m_json;
    }
}
