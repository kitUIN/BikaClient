#pragma once
#include "Responses.CategoriesResponse.g.h"
#include <Blocks/Blocks.CategoriesBlock.h>
#include "Responses.IResponse.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct CategoriesResponse : CategoriesResponseT<CategoriesResponse, BikaClient::Responses::implementation::IResponse>
    {
        CategoriesResponse() = default;

        CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json);
        CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        void Init(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> Categories();
        void Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> const& value);

    private:
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> m_categories = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CategoriesBlock>();
        hstring m_fileServer = L"https://storage1.picacomic.com/static/";
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct CategoriesResponse : CategoriesResponseT<CategoriesResponse, implementation::CategoriesResponse>
    {
    };
}
