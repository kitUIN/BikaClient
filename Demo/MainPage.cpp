#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
namespace winrt::Demo::implementation
{
    Demo::MainPage MainPage::current{ nullptr };

    MainPage::MainPage()
    {
        InitializeComponent();
        MainPage::current = *this;
    }

    BikaClient::BikaHttpClient MainPage::Bika()
    {
        return bika;
    }



    void winrt::Demo::implementation::MainPage::MainList_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
    {
        auto lsit = sender.as<ListView>().SelectedItem().as<hstring>();
        OutputDebugStringW(lsit.c_str());
        if (lsit == L"Login") mainFrame().Navigate(winrt::xaml_typename<Demo::LoginPage>());
        else if (lsit == L"Comics") mainFrame().Navigate(winrt::xaml_typename<Demo::ComicsPage>());
        else if (lsit == L"SendComments") mainFrame().Navigate(winrt::xaml_typename<Demo::SendCommentPage>());
        else if (lsit == L"Favourite") mainFrame().Navigate(winrt::xaml_typename<Demo::FavouritePage>());
        else if (lsit == L"Like") mainFrame().Navigate(winrt::xaml_typename<Demo::LikePage>());
        else if (lsit == L"PunchIn") mainFrame().Navigate(winrt::xaml_typename<Demo::PunchInPage>());
        else if (lsit == L"SetSlogan") mainFrame().Navigate(winrt::xaml_typename<Demo::SetSloganPage>());
        else if (lsit == L"SetPassword") mainFrame().Navigate(winrt::xaml_typename<Demo::SetPasswordPage>());
        else if (lsit == L"BookInfo") mainFrame().Navigate(winrt::xaml_typename<Demo::BookInfoPage>());
        else if (lsit == L"PersonInfo") mainFrame().Navigate(winrt::xaml_typename<Demo::PersonInfoPage>());
        else if (lsit == L"Categories") mainFrame().Navigate(winrt::xaml_typename<Demo::CategoriesPage>());
        else if (lsit == L"Keywords") mainFrame().Navigate(winrt::xaml_typename<Demo::KeywordsPage>());
        else if (lsit == L"Episodes") mainFrame().Navigate(winrt::xaml_typename<Demo::EpisodesPage>());
    }



}
