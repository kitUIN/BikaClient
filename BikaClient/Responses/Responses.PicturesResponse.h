#pragma once
#include "Responses.PicturesResponse.g.h"
#include "Blocks/Blocks.ImageBlock.h"
#include "Blocks/Blocks.EpisodeBlock.h"

namespace winrt::BikaClient::Responses::implementation
{
    struct PicturesResponse : PicturesResponseT<PicturesResponse>
    {
        PicturesResponse() = default;

        PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json);
        PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> Pictures();
        void Pictures(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> const& value);
        winrt::BikaClient::Blocks::EpisodeBlock Episode();
        void Episode(winrt::BikaClient::Blocks::EpisodeBlock const& value);
        int32_t Page();
        void Page(int32_t value);
        int32_t Pages();
        void Pages(int32_t value);
        int32_t Total();
        void Total(int32_t value);
        int32_t Limit();
        void Limit(int32_t value);
        int32_t Code();
        void Code(int32_t value);
        hstring Message();
        void Message(hstring const& value);
        hstring Error();
        void Error(hstring const& value);
        hstring Detail();
        void Detail(hstring const& value);
        hstring Json();
    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> m_pictures = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::ImageBlock>();
		winrt::BikaClient::Blocks::EpisodeBlock m_episode{ nullptr };
		int32_t m_page{ 0 };
		int32_t m_pages{ 0 };
		int32_t m_total{ 0 };
		int32_t m_limit{ 0 };
		int32_t m_code{ 0 };
		hstring m_message{ L"" };
		hstring m_error{ L"" };
		hstring m_detail{ L"" };
		hstring m_json{ L"" };
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct PicturesResponse : PicturesResponseT<PicturesResponse, implementation::PicturesResponse>
    {
    };
}
