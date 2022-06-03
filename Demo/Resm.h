#pragma once
#include "Resm.g.h"


namespace winrt::Demo::implementation
{
    struct Resm : ResmT<Resm>
    {
        Resm() = default;
        Resm(hstring const& res);
        hstring Code();
        void Code(hstring const& value);
        hstring m_code =L"assssss";
    };
}
namespace winrt::Demo::factory_implementation
{
    struct Resm : ResmT<Resm, implementation::Resm>
    {
    };
}
