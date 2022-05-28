#include "pch.h"
#include "ActionControl.h"
#if __has_include("ActionControl.g.cpp")
#include "ActionControl.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TestClient::implementation
{
    ActionControl::ActionControl()
    {
        InitializeComponent();
    }

    int32_t ActionControl::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ActionControl::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void ActionControl::ResSet(winrt::BikaClient::Responses::ActionResponse const& response)
    {
        m_Responses.Append(response);
        Resp().ItemsSource(box_value(m_Responses));
    }

}
