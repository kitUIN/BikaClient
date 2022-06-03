#include "pch.h"
#include "Responses.CategoriesResponse.h"
#include "Responses.CategoriesResponse.g.cpp"


namespace winrt::BikaClient::Responses::implementation
{
    CategoriesResponse::CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json)
    {
        Init(json);
    }
    CategoriesResponse::CategoriesResponse(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
    {
        m_fileServer = fileServer;
        Init(json);
    }
    void CategoriesResponse::Init(winrt::Windows::Data::Json::JsonObject const& json)
    {

        IInit(json);
        if (json.HasKey(L"data")) {
            for (auto x : json.GetNamedObject(L"data").GetNamedArray(L"categories"))
            {
                m_categories.Append(winrt::make<winrt::BikaClient::Blocks::implementation::CategoriesBlock>(x.GetObject(), m_fileServer));
            }
        }
    }
    winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> CategoriesResponse::Categories()
    {
        return m_categories;
    }
    void CategoriesResponse::Categories(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::CategoriesBlock> const& value)
    {
        m_categories = value;
    }
}
