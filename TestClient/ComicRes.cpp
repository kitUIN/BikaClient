#include "pch.h"
#include "ComicRes.h"
#if __has_include("ComicRes.g.cpp")
#include "ComicRes.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TestClient::implementation
{
    ComicRes::ComicRes()
    {
        InitializeComponent();
    }

    void ComicRes::ResSet(winrt::BikaClient::Responses::ComicsResponse const& response)
    {
        m_comicsResponses.Append(response);
        ComicItems().ItemsSource(box_value(m_comicsResponses));
    }

    int32_t ComicRes::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ComicRes::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

}
