#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
namespace winrt::TestClient::implementation
{
    TestClient::MainPage MainPage::current{ nullptr };

    MainPage::MainPage()
    {
        InitializeComponent();
        MainPage::current = *this;
    }

    BikaClient::BikaHttpClient MainPage::Bika()
    {
        return bika;
    }


}


void winrt::TestClient::implementation::MainPage::MainList_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
{
    auto lsit = sender.as<ListView>().SelectedItem().as<hstring>();
    OutputDebugStringW(lsit.c_str());
    if (lsit == L"Login") mainFrame().Navigate(winrt::xaml_typename<TestClient::LoginPage>());
    else if (lsit == L"Comics") mainFrame().Navigate(winrt::xaml_typename<TestClient::ComicsPage>());
    else if (lsit == L"SendComments") mainFrame().Navigate(winrt::xaml_typename<TestClient::SendCommentPage>());
    else if (lsit == L"Favourite") mainFrame().Navigate(winrt::xaml_typename<TestClient::FavouritePage>());
    else if (lsit == L"Like") mainFrame().Navigate(winrt::xaml_typename<TestClient::LikePage>());
    else if (lsit == L"PunchIn") mainFrame().Navigate(winrt::xaml_typename<TestClient::PunchInPage>());
    else if (lsit == L"SetSlogan") mainFrame().Navigate(winrt::xaml_typename<TestClient::SetSloganPage>());
    else if (lsit == L"SetPassword") mainFrame().Navigate(winrt::xaml_typename<TestClient::SetPasswordPage>());
}
