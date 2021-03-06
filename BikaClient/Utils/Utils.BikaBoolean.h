#pragma once
#include "Utils.BikaBoolean.g.h"


namespace winrt::BikaClient::Utils::implementation
{
    struct BikaBoolean : BikaBooleanT<BikaBoolean>
    {
        BikaBoolean() = default;

        BikaBoolean(bool isValue);
        void Bool(bool value);
        bool Bool();
        winrt::Windows::UI::Xaml::Visibility Visibility();
        winrt::Windows::UI::Xaml::Visibility Reverse();
        void Visibility(winrt::Windows::UI::Xaml::Visibility const& value);
        void Reverse(winrt::Windows::UI::Xaml::Visibility const& value);
    private:
		bool m_isValue = false;
    };
}
namespace winrt::BikaClient::Utils::factory_implementation
{
    struct BikaBoolean : BikaBooleanT<BikaBoolean, implementation::BikaBoolean>
    {
    };
}
