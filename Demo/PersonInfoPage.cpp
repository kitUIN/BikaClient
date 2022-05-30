#include "pch.h"
#include "PersonInfoPage.h"
#if __has_include("PersonInfoPage.g.cpp")
#include "PersonInfoPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::Foundation;

using namespace winrt::Windows::UI::Xaml::Media::Imaging;
namespace winrt::Demo::implementation
{
    PersonInfoPage::PersonInfoPage()
    {
        InitializeComponent();
    }

    int32_t PersonInfoPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PersonInfoPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    BikaClient::Blocks::UserBlock PersonInfoPage::User()
    {
        return m_user;
    }

    void PersonInfoPage::User(BikaClient::Blocks::UserBlock const& value)
    {
        m_user = value;
        m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"User" });
    }

    winrt::Windows::Foundation::IAsyncAction PersonInfoPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().PersonInfo();
        a.Append(res);
        Res().ItemsSource(box_value(a));
        User(res.User());
        //m_user.Thumb().Img(BitmapImage{ Uri{ L"ms-appx:///Assets//Picacgs//icon_unknown_error.png" } });
    }
    winrt::event_token PersonInfoPage::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void PersonInfoPage::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
