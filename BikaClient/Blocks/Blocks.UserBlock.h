#pragma once
#include "Blocks.UserBlock.g.h"
#include "Date/Date.BikaDate.h"

namespace winrt::BikaClient::Blocks::implementation
{
    struct UserBlock : UserBlockT<UserBlock>
    {
        UserBlock() = default;

        UserBlock(winrt::Windows::Data::Json::JsonObject const& json);
        UserBlock(winrt::Windows::Data::Json::JsonObject const& json,hstring const& fileServer);
        int32_t GetEXP(int32_t const& level);
        hstring ID();
        void ID(hstring const& value);
        hstring Name();
        void Name(hstring const& value);
        hstring CreatedAt();
        void CreatedAt(hstring const& value);
        hstring Birthday();
        void Birthday(hstring const& value);
        hstring Email();
        void Email(hstring const& value);
        hstring Level();
        void Level(hstring const& value);
        hstring LevelString();
        void LevelString(hstring const& value);
        bool IsPunched();
        void IsPunched(bool const& value);
        bool Verified();
        void Verified(bool const& value);
        hstring Gender();
        void Gender(hstring const& value);
        winrt::BikaClient::Blocks::ThumbBlock Thumb();
        void Thumb(winrt::BikaClient::Blocks::ThumbBlock const& value);
        hstring Slogan();
        void Slogan(hstring const& value);
        int32_t Exp();
        void Exp(int32_t const& value);
        int32_t Percent();
        void Percent(int32_t const& value);
        hstring Title();
        void Title(hstring const& value);
        hstring Role();
        void Role(hstring const& value);
        hstring Character();
        void Character(hstring const& value);
        winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> Characters();
        void Characters(winrt::Windows::Foundation::Collections::IObservableVector<winrt::BikaClient::Blocks::TagBlock> const& value);
        hstring CharactersString();
        void CharactersString(hstring const& value);
        hstring LevelExp();
        void LevelExp(hstring const& value);
        void Clear();
        hstring Json();
        winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        winrt::hstring m_title = L"";
        winrt::hstring m_gender = L"";
        winrt::hstring m_role = L"";
        winrt::hstring m_character = L"";
        winrt::hstring m_id = L"";
        bool m_verified = false;
        winrt::hstring m_verifiedString = L"";
        bool m_isPunched = false;
        winrt::hstring m_isPunchedString = L"";
        winrt::hstring m_createAt = L"";
        winrt::hstring m_birthday = L"";
        winrt::hstring m_slogan = L"";
        winrt::hstring m_levelExp = L"(? / ?)";
        int32_t m_exp = 0;
        int32_t m_percent = 100;
        winrt::hstring m_name = L"Gentleman";
        winrt::hstring m_email = L"";
        winrt::hstring m_levelString = L"Lv.0";
        hstring  m_level = L"";
        winrt::Windows::Foundation::Collections::IObservableVector<BikaClient::Blocks::TagBlock> m_characters = winrt::single_threaded_observable_vector<BikaClient::Blocks::TagBlock>();
        hstring m_charactersString = L"";
        winrt::BikaClient::Blocks::ThumbBlock m_thumb{ nullptr };
        hstring m_json = L"";
    };
}
namespace winrt::BikaClient::Blocks::factory_implementation
{
    struct UserBlock : UserBlockT<UserBlock, implementation::UserBlock>
    {
    };
}
