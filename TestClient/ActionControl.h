#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "ActionControl.g.h"

namespace winrt::TestClient::implementation
{
    struct ActionControl : ActionControlT<ActionControl>
    {
        ActionControl();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ResSet(winrt::BikaClient::Responses::ActionResponse const& response);
    private:
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Responses::ActionResponse> m_Responses = winrt::single_threaded_observable_vector<winrt::BikaClient::Responses::ActionResponse>();


    };
}

namespace winrt::TestClient::factory_implementation
{
    struct ActionControl : ActionControlT<ActionControl, implementation::ActionControl>
    {
    };
}
