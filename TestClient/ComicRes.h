#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "ComicRes.g.h"
#include "winrt/BikaClient.Responses.h"

namespace winrt::TestClient::implementation
{
    struct ComicRes : ComicResT<ComicRes>
    {
        ComicRes();


        int32_t MyProperty();
        void MyProperty(int32_t value);
        void ResSet(winrt::BikaClient::Responses::ComicsResponse const& response);
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::ComicsResponse> m_comicsResponses = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::ComicsResponse>();


    };
}

namespace winrt::TestClient::factory_implementation
{
    struct ComicRes : ComicResT<ComicRes, implementation::ComicRes>
    {
    };
}
