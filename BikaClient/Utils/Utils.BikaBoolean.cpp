#include "pch.h"
#include "Utils.BikaBoolean.h"
#include "Utils.BikaBoolean.g.cpp"


namespace winrt::BikaClient::Utils::implementation
{
    BikaBoolean::BikaBoolean(bool isValue)
    {
        m_isValue = isValue;
    }
    void BikaBoolean::Bool(bool value)
    {
        m_isValue = value;
    }
    bool BikaBoolean::Bool()
    {
        return m_isValue;
    }
    winrt::Windows::UI::Xaml::Visibility BikaBoolean::Visibility()
    {
        if(m_isValue) return winrt::Windows::UI::Xaml::Visibility::Visible;
		else return winrt::Windows::UI::Xaml::Visibility::Collapsed;
    }

}
