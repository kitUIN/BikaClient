#include "pch.h"
#include "CommentsPage.h"
#if __has_include("CommentsPage.g.cpp")
#include "CommentsPage.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::Demo::implementation
{
    CommentsPage::CommentsPage()
    {
        InitializeComponent();
    }

    int32_t CommentsPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void CommentsPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    winrt::Windows::Foundation::IAsyncAction CommentsPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        auto res = co_await rootPage.Bika().Comments(bookId().Text(),page().Value());
        OutputDebugStringW(res.Comments().GetAt(1).User().Slogan().c_str());
        OutputDebugStringW(res.Comments().GetAt(1).User().Json().c_str());
        CommentItem comics;
        comics.Comments(res);
        MainStackPanel().Children().Append(comics);
    }
}
