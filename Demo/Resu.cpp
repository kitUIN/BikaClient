#include "pch.h"
#include "Resu.h"
#include "Resu.g.cpp"


namespace winrt::Demo::implementation
{
    Resu::Resu(hstring const& res)
    {
        Message(res);

    }
    hstring Resu::Message()
    {
        throw hresult_not_implemented();
    }
    void Resu::Message(hstring const& value)
    {
        Code(value);
    }
}
