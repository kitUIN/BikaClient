#pragma once
#include "Blocks.ComicBlock.g.h"
#include "Blocks.TagBlock.h"
#include "Blocks.ImageBlock.h"
#include "Utils/Utils.BikaBoolean.h"
namespace winrt::BikaClient::Blocks::implementation
{
    struct ComicBlock : ComicBlockT<ComicBlock>
    {
        ComicBlock() = default;

        ComicBlock(winrt::Windows::Data::Json::JsonObject const& json);
        ComicBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        hstring Id();
        void Id(hstring const& value);
        hstring Title();
        void Title(hstring const& value);
        hstring Author();
        void Author(hstring const& value);
        int32_t TotalViews();
        void TotalViews(int32_t const& value);
        int32_t TotalLikes();
        void TotalLikes(int32_t const& value);
        int32_t LikesCount();
        void LikesCount(int32_t const& value);
        int32_t PagesCount();
        void PagesCount(int32_t const& value);
        int32_t EpsCount();
        void EpsCount(int32_t const& value);
        winrt::BikaClient::Utils::BikaBoolean Finished();
        void Finished(winrt::BikaClient::Utils::BikaBoolean const& value);
        winrt::BikaClient::Blocks::ImageBlock Thumb();
        void Thumb(winrt::BikaClient::Blocks::ImageBlock const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Categories();
        void Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);
        hstring CategoriesString();
        void CategoriesString(hstring const& value);
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
        hstring Json();
    private:
		hstring m_id = L"";
		hstring m_title = L"";
		hstring m_author = L"";
		int32_t m_totalViews = 0;
		int32_t m_totalLikes = 0;
		int32_t m_likesCount = 0;
		int32_t m_pagesCount = 0;
		int32_t m_epsCount = 0;
        winrt::BikaClient::Utils::BikaBoolean m_finished{ false };
        winrt::BikaClient::Blocks::ImageBlock m_thumb;
        winrt::Windows::Foundation::Collections::IObservableVector<BikaClient::Blocks::TagBlock> m_categories = winrt::single_threaded_observable_vector<BikaClient::Blocks::TagBlock>();
        hstring m_categoriesString = L"";
        winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		hstring m_json=L"";
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct ComicBlock : ComicBlockT<ComicBlock, implementation::ComicBlock>
    {
    };
}
