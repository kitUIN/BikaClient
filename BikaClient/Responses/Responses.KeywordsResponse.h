#pragma once
#include "Responses.KeywordsResponse.g.h"
#include "Blocks/Blocks.TagBlock.h"
namespace winrt::BikaClient::Responses::implementation
{
    struct KeywordsResponse : KeywordsResponseT<KeywordsResponse>
    {
        KeywordsResponse() = default;

        KeywordsResponse(winrt::Windows::Data::Json::JsonObject const& json);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Keywords();
        void Keywords(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);
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
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> m_keywords = winrt::single_threaded_observable_vector<winrt::BikaClient::Blocks::TagBlock>();
		int32_t m_code{ 0 };
		hstring m_message{ L"" };
		hstring m_error{ L"" };
		hstring m_detail{ L"" };
		hstring m_json{ L"" };

    };
}
namespace winrt::BikaClient::Responses::factory_implementation
{
    struct KeywordsResponse : KeywordsResponseT<KeywordsResponse, implementation::KeywordsResponse>
    {
    };
}
