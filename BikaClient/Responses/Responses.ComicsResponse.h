#pragma once
#include "Responses.ComicsResponse.g.h"
#include "Blocks/Blocks.ComicBlock.h"
#include "Responses.IPage.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct ComicsResponse : ComicsResponseT<ComicsResponse, BikaClient::Responses::implementation::IPage>
    {
        ComicsResponse() = default;

        ComicsResponse(winrt::Windows::Data::Json::JsonObject const& json);
        ComicsResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ComicBlock> Comics();
        void Comics(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ComicBlock> const& value);

    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::ComicBlock> m_comics=winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::ComicBlock>();
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct ComicsResponse : ComicsResponseT<ComicsResponse, implementation::ComicsResponse>
    {
    };
}
