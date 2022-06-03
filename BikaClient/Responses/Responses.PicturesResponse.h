#pragma once
#include "Responses.PicturesResponse.g.h"
#include "Blocks/Blocks.ImageBlock.h"
#include "Blocks/Blocks.EpisodeBlock.h"
#include "Responses.IResponse.h"
#include "Responses.IPage.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct PicturesResponse : PicturesResponseT<PicturesResponse, BikaClient::Responses::implementation::IPage>
    {
        PicturesResponse() = default;

        PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json);
        PicturesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> Pictures();
        void Pictures(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> const& value);
        winrt::BikaClient::Blocks::EpisodeBlock Episode();
        void Episode(winrt::BikaClient::Blocks::EpisodeBlock const& value);
    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ImageBlock> m_pictures = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::ImageBlock>();
		winrt::BikaClient::Blocks::EpisodeBlock m_episode{ nullptr };
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct PicturesResponse : PicturesResponseT<PicturesResponse, implementation::PicturesResponse>
    {
    };
}
