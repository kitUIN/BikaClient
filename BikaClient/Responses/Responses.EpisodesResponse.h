#pragma once
#include "Responses.EpisodesResponse.g.h"
#include "Blocks/Blocks.EpisodeBlock.h"
#include "Responses.IPage.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct EpisodesResponse : EpisodesResponseT<EpisodesResponse, BikaClient::Responses::implementation::IPage>
    {
        EpisodesResponse() = default;

        EpisodesResponse(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::EpisodeBlock> Episodes();
        void Episodes(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::EpisodeBlock> const& value);
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::EpisodeBlock> m_episodes = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::EpisodeBlock>();

    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct EpisodesResponse : EpisodesResponseT<EpisodesResponse, implementation::EpisodesResponse>
    {
    };
}
