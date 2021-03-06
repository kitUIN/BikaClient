#include "pch.h"
#include "Blocks.UserBlock.h"
#include "Blocks.UserBlock.g.cpp"
#pragma warning( disable : 4244 )
namespace winrt::BikaClient::Blocks::implementation
{

	UserBlock::UserBlock(winrt::Windows::Data::Json::JsonObject const& json)
	{
		Init(json);
	}
	UserBlock::UserBlock(winrt::Windows::Data::Json::JsonObject const& json, hstring const& fileServer)
	{
		m_fileServer = fileServer;
		Init(json);
	}
	void UserBlock::Init(winrt::Windows::Data::Json::JsonObject const& json)
	{
		m_json = json.Stringify();
		if (json.HasKey(L"name"))
			Name(json.GetNamedString(L"name"));
		if (json.HasKey(L"slogan"))
		{
			Slogan(L"\"" + to_hstring(json.GetNamedString(L"slogan")) + L"\"");
			m_sloganOmit = m_slogan;
		}
		if (json.HasKey(L"title"))
			Title(json.GetNamedString(L"title"));
		if (json.HasKey(L"gender"))
			Gender(json.GetNamedString(L"gender"));
		if (json.HasKey(L"_id"))
			ID(json.GetNamedString(L"_id"));
		if (json.HasKey(L"email"))
			Email(json.GetNamedString(L"email"));
		if (json.HasKey(L"verified"))
			Verified(winrt::BikaClient::Utils::BikaBoolean{ json.GetNamedBoolean(L"verified") });
		if (json.HasKey(L"isPunched"))
			IsPunched(winrt::BikaClient::Utils::BikaBoolean{ json.GetNamedBoolean(L"isPunched") });
		if (json.HasKey(L"created_at"))
			CreatedAt(winrt::BikaClient::Date::BikaDate{ json.GetNamedString(L"created_at") });
		if (json.HasKey(L"birthday"))
			Birthday(winrt::BikaClient::Date::BikaDate{ json.GetNamedString(L"birthday") });
		if (json.HasKey(L"level"))
			Level(to_hstring(json.GetNamedNumber(L"level")));
		if (json.HasKey(L"exp") && json.HasKey(L"level"))
		{
			int32_t exp = json.GetNamedNumber(L"exp");
			int32_t level = GetEXP(json.GetNamedNumber(L"level"));
			LevelExp(L"(" + to_hstring(exp) + L" / " + to_hstring(level) + L")");
			Percent(static_cast<int32_t>(exp * 100 / level));
		}

		if (json.HasKey(L"role"))
			Role(json.GetNamedString(L"role"));
		if (json.HasKey(L"character"))
			Character(json.GetNamedString(L"character"));
		if (json.HasKey(L"characters"))
		{
			for (auto x : json.GetNamedArray(L"characters"))
			{
				m_characters.Append(make<winrt::BikaClient::Blocks::implementation::TagBlock>(x.GetString()));
				m_charactersString = m_charactersString + x.GetString() + L"  ";
			}
		}

		if (json.HasKey(L"avatar"))
		{
			m_thumb = make<winrt::BikaClient::Blocks::implementation::ImageBlock>(json.GetNamedObject(L"avatar"), m_fileServer);
		}
	}
	int32_t UserBlock::GetEXP(int32_t const& level)
	{
		int32_t temp = (level + 1) * 2 - 1;
		return (temp * temp - 1) * 25;
	}
	hstring UserBlock::Name()
	{
		return m_name;
	}
	void UserBlock::Name(hstring const& value)
	{
		if (m_name != value)
		{
			m_name = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Name" });
		}

	}
	winrt::BikaClient::Date::BikaDate UserBlock::CreatedAt()
	{
		return m_createAt;
	}
	void UserBlock::CreatedAt(winrt::BikaClient::Date::BikaDate const& value)
	{
		m_createAt = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"CreatedAt" });
	}
	winrt::BikaClient::Date::BikaDate UserBlock::Birthday()
	{
		return m_birthday;
	}
	void UserBlock::Birthday(winrt::BikaClient::Date::BikaDate const& value)
	{
		m_birthday = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Birthday" });
	}
	hstring UserBlock::Email()
	{
		return m_email;
	}
	void UserBlock::Email(hstring const& value)
	{
		if (m_email != value)
		{
			m_email = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Email" });
		}
	}
	hstring UserBlock::Level()
	{
		return m_level;
	}
	void UserBlock::Level(hstring const& value)
	{
		if (m_level != value)
		{
			m_level = value;
			m_levelString = L"Lv." + value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"LevelString" });
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Level" });
		}
	}
	winrt::BikaClient::Utils::BikaBoolean UserBlock::IsPunched()
	{
		return m_isPunched;
	}
	void UserBlock::IsPunched(winrt::BikaClient::Utils::BikaBoolean const& value)
	{
		m_isPunched = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"IsPunched" });
	}
	winrt::BikaClient::Utils::BikaBoolean UserBlock::Verified()
	{
		return m_verified;
	}
	void UserBlock::Verified(winrt::BikaClient::Utils::BikaBoolean const& value)
	{
		m_verified = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Verified" });
	}
	hstring UserBlock::ID()
	{
		return m_id;
	}
	void UserBlock::ID(hstring const& value)
	{
		if (m_id != value)
		{
			m_id = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"ID" });
		}
	}
	hstring UserBlock::Gender()
	{
		return m_gender;
	}
	void UserBlock::Gender(hstring const& value)
	{
		m_gender = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Gender" });
	}
	winrt::BikaClient::Blocks::ImageBlock UserBlock::Thumb()
	{
		return m_thumb;
	}
	void UserBlock::Thumb(winrt::BikaClient::Blocks::ImageBlock const& value)
	{
		m_thumb = value;
	}
	hstring UserBlock::LevelString()
	{
		return m_levelString;
	}
	void UserBlock::LevelString(hstring const& value)
	{
		if (m_levelString != value)
		{
			m_levelString = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"LevelString" });
		}
	}
	hstring UserBlock::Slogan()
	{
		return m_slogan;
	}
	void UserBlock::Slogan(hstring const& value)
	{
		m_slogan = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Slogan" });
	}
	hstring UserBlock::SloganOmit()
	{
		return m_sloganOmit;
	}
	void UserBlock::SloganOmit(hstring const& value)
	{
		m_sloganOmit = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"SloganOmit" });
	}
	int32_t UserBlock::Exp()
	{
		return m_exp;
	}
	void UserBlock::Exp(int32_t const& value)
	{
		m_exp = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Exp" });
	}
	int32_t UserBlock::Percent()
	{
		return m_percent;
	}
	void UserBlock::Percent(int32_t const& value)
	{
		m_percent = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Percent" });
	}
	hstring UserBlock::Character()
	{
		return m_character;
	}
	void UserBlock::Character(hstring const& value)
	{
		if (m_character != value)
		{
			m_character = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Character" });
		}
	}
	hstring UserBlock::LevelExp()
	{
		return m_levelExp;
	}
	void UserBlock::LevelExp(hstring const& value)
	{
		if (m_levelExp != value)
		{
			m_levelExp = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"LevelExp" });
		}
	}
	BikaClient::Date::TimeZone UserBlock::TimeZone()
	{
		return m_zone;
	}
	winrt::Windows::Foundation::Collections::IObservableVector<BikaClient::Blocks::TagBlock> UserBlock::Characters()
	{
		return m_characters;
	}
	void UserBlock::Characters(winrt::Windows::Foundation::Collections::IObservableVector<BikaClient::Blocks::TagBlock> const& value)
	{
		if (m_characters != value) {
			m_characters = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Characters" });
		}
	}
	hstring UserBlock::CharactersString()
	{
		return m_charactersString;
	}
	void UserBlock::CharactersString(hstring const& value)
	{
		if (m_charactersString != value) {
			m_charactersString = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"CharactersString" });
		}
	}
	hstring UserBlock::Title()
	{
		return m_title;
	}
	void UserBlock::Title(hstring const& value)
	{
		if (m_title != value)
		{
			m_title = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
		}
	}
	hstring UserBlock::Role()
	{
		return m_role;
	}
	void UserBlock::Role(hstring const& value)
	{
		if (m_role != value)
		{
			m_role = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Role" });
		}
	}
	void UserBlock::TimeZone(BikaClient::Date::TimeZone const& value)
	{
		m_zone = value;
		m_birthday.SetTimeZone(m_zone);
	}
	hstring UserBlock::Json()
	{
		return m_json;
	}
	winrt::event_token UserBlock::PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void UserBlock::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
}
