#pragma once
#include "Blocks.BookBlock.g.h"
#include "Blocks.ImageBlock.h"
#include "Blocks.UserBlock.h"
#include "Blocks.TagBlock.h"
#include "Date/Date.BikaDate.h"
#include "Utils/Utils.BikaBoolean.h"
namespace winrt::BikaClient::Blocks::implementation
{
    struct BookBlock : BookBlockT<BookBlock>
    {
        BookBlock() = default;

        BookBlock(winrt::Windows::Data::Json::JsonObject const& json);
        BookBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        hstring ID();
        void ID(hstring const& value);
        hstring Title();
        void Title(hstring const& value);
        winrt::BikaClient::Blocks::UserBlock Creater();
        void Creater(winrt::BikaClient::Blocks::UserBlock const& value);
        hstring Description();
        void Description(hstring const& value);
        winrt::BikaClient::Blocks::ImageBlock Thumb();
        void Thumb(winrt::BikaClient::Blocks::ImageBlock const& value);
        hstring Author();
        void Author(hstring const& value);
        hstring ChineseTeam();
        void ChineseTeam(hstring const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Categories();
        void Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);
        hstring CategoriesString();
        void CategoriesString(hstring const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Tags();
        void Tags(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);
        hstring TagsString();
        void TagsString(hstring const& value);
        int32_t PagesCount();
        void PagesCount(int32_t value);
        int32_t EpsCount();
        void EpsCount(int32_t value);
        winrt::BikaClient::Utils::BikaBoolean Finished();
        void Finished(winrt::BikaClient::Utils::BikaBoolean value);
        winrt::BikaClient::Date::BikaDate UpdatedAt();
        void UpdatedAt(winrt::BikaClient::Date::BikaDate const& value);
        winrt::BikaClient::Date::BikaDate CreatedAt();
        void CreatedAt(winrt::BikaClient::Date::BikaDate const& value);
        bool AllowDownload();
        void AllowDownload(bool value);
        bool AllowComment();
        void AllowComment(bool value);
        int32_t TotalLikes();
        void TotalLikes(int32_t value);
        int32_t TotalViews();
        void TotalViews(int32_t value);
        int32_t ViewsCount();
        void ViewsCount(int32_t value);
        int32_t LikesCount();
        void LikesCount(int32_t value);
        bool IsFavourite();
        void IsFavourite(bool value);
        bool IsLiked();
        void IsLiked(bool value);
        int32_t CommentsCount();
        void CommentsCount(int32_t value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    private:
		hstring m_id = L"";
		hstring m_title = L"";
        winrt::BikaClient::Blocks::UserBlock m_creater{ nullptr };
		hstring m_description = L"";
		winrt::BikaClient::Blocks::ImageBlock m_thumb{ nullptr };
		hstring m_author = L"";
		hstring m_chineseTeam = L"";
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> m_categories = winrt::single_threaded_observable_vector<BikaClient::Blocks::TagBlock>();
		hstring m_categoriesString = L"";
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> m_tags = winrt::single_threaded_observable_vector<BikaClient::Blocks::TagBlock>();
		hstring m_tagsString = L"";
		int32_t m_pagesCount = 0;
		int32_t m_epsCount = 0;
        winrt::BikaClient::Utils::BikaBoolean m_finished{ false };
		winrt::BikaClient::Date::BikaDate m_updatedAt{ nullptr };
		winrt::BikaClient::Date::BikaDate m_createdAt{ nullptr };
		bool m_allowDownload = false;
		bool m_allowComment = false;
		int32_t m_totalLikes = 0;
		int32_t m_totalViews = 0;
		int32_t m_viewsCount = 0;
		int32_t m_likesCount = 0;
		bool m_isFavourite = false;
		bool m_isLiked = false;
		int32_t m_commentsCount = 0;
		winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        hstring m_json = L"";
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct BookBlock : BookBlockT<BookBlock, implementation::BookBlock>
    {
    };
}
