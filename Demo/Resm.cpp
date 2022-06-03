#include "pch.h"
#include "Resm.h"
#include "Resm.g.cpp"


namespace winrt::Demo::implementation
{
    Resm::Resm(hstring const& res)
    {
        Code(res);
    }
    hstring Resm::Code()
    {
        return m_code;
    }
    void Resm::Code(hstring const& value)
    {
        m_code=value;
    }
}
