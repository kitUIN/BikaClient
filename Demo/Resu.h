#pragma once
#include "Resu.g.h"
#include "Resm.h"

namespace winrt::Demo::implementation
{
    struct Resu : ResuT<Resu, Demo::implementation::Resm>
    {
        Resu() = default;
        Resu(hstring const& res);
        hstring Message();
        void Message(hstring const& value);
    };
}
namespace winrt::Demo::factory_implementation
{
    struct Resu : ResuT<Resu, implementation::Resu>
    {

    };
}
