#pragma once
#include "Responses.CategoriesResponse.g.h"
#include <Blocks/Blocks.CategoriesBlock.h>
namespace winrt::BikaClient::Responses::implementation
{
    struct CategoriesResponse : CategoriesResponseT<CategoriesResponse>
    {
        CategoriesResponse() = default;

        CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json);
        CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> Categories();
        void Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> const& value);
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
		winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> m_categories = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::CategoriesBlock>();
		int32_t m_code{ 0 };
		hstring m_message{ L"" };
		hstring m_error{ L"" };
		hstring m_detail{ L"" };
		hstring m_json{ L"" };
    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct CategoriesResponse : CategoriesResponseT<CategoriesResponse, implementation::CategoriesResponse>
    {
    };
}
