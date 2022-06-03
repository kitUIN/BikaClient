#pragma once
#include "Responses.KeywordsResponse.g.h"
#include "Blocks/Blocks.TagBlock.h"
#include "Responses.IResponse.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct KeywordsResponse : KeywordsResponseT<KeywordsResponse, BikaClient::Responses::implementation::IResponse>
    {
        KeywordsResponse() = default;

        KeywordsResponse(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Keywords();
        void Keywords(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> m_keywords = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::TagBlock>();

    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct KeywordsResponse : KeywordsResponseT<KeywordsResponse, implementation::KeywordsResponse>
    {
    };
}
