#include "pch.h"
#include "Blocks.UserBlock.h"
#include "Blocks.UserBlock.g.cpp"
#pragma warning( disable : 4244 )
namespace winrt::BikaClient::Blocks::implementation
{
	UserBlock::UserBlock(winrt::Windows::Data::Json::JsonObject const& json)
	{
		UserBlock(json, to_hstring(DEFAULT_FILE_SERVER));
	}
	UserBlock::UserBlock(winrt::Windows::Data::Json::JsonObject const& json,hstring const& fileServer)
	{
		m_json = json.Stringify();
		if (json.HasKey(L"name"))
			Name(json.GetNamedString(L"name"));
		if (json.HasKey(L"slogan"))
			Slogan(L"\"" + to_hstring(json.GetNamedString(L"slogan")) + L"\"");
		if (json.HasKey(L"title"))
			Title(json.GetNamedString(L"title"));
		if (json.HasKey(L"gender"))
			Gender(json.GetNamedString(L"gender"));
		if (json.HasKey(L"_id"))
			ID(json.GetNamedString(L"_id"));
		if (json.HasKey(L"email"))
			Email(json.GetNamedString(L"email"));
		if (json.HasKey(L"verified"))
			Verified(json.GetNamedBoolean(L"verified"));
		if (json.HasKey(L"isPunched"))
			IsPunched(json.GetNamedBoolean(L"isPunched"));
		if (json.HasKey(L"created_at"))
			CreatedAt(json.GetNamedString(L"created_at"));
		if (json.HasKey(L"birthday"))
			Birthday(json.GetNamedString(L"birthday"));
		if (json.HasKey(L"level"))
			Level(to_hstring(json.GetNamedNumber(L"level")));
		if (json.HasKey(L"exp") && json.HasKey(L"level"))
			LevelExp(L"(" + to_hstring(json.GetNamedNumber(L"exp")) + L" / " + to_hstring(GetEXP(json.GetNamedNumber(L"level"))) + L")");
		if (json.HasKey(L"role"))
			Role(json.GetNamedString(L"role"));
		if (json.HasKey(L"character"))
			Character(json.GetNamedString(L"character"));
		if (json.HasKey(L"characters"))
		{
			for (auto x : json.GetNamedArray(L"characters"))
			{
				m_characters.Append(TagBlock(x.GetString()));
				m_charactersString = m_charactersString + x.GetString() + L"  ";
			}
		}

		if (json.HasKey(L"avatar"))
		{
			m_thumb = winrt::BikaClient::Blocks::ThumbBlock(json.GetNamedObject(L"avatar"), fileServer);
			int32_t percent = (int32_t)json.GetNamedNumber(L"exp") * 100 / GetEXP(json.GetNamedNumber(L"level"));
			Percent(percent);
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
	hstring UserBlock::CreatedAt()
	{
		return m_createAt;
	}
	void UserBlock::CreatedAt(hstring const& value)
	{
		BikaClient::Date::BikaDate datetime{ value };
		m_createAt = datetime.GetDateTime();
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"CreatedAt" });
	}
	hstring UserBlock::Birthday()
	{
		return m_birthday;
	}
	void UserBlock::Birthday(hstring const& value)
	{
		BikaClient::Date::BikaDate datetime{ value };
		m_birthday = datetime.GetDateTime();
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
	bool UserBlock::IsPunched()
	{
		return m_isPunched;
	}
	void UserBlock::IsPunched(bool const& value)
	{
		m_isPunched = value;
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"IsPunched" });
	}
	bool UserBlock::Verified()
	{
		return m_verified;
	}
	void UserBlock::Verified(bool const& value)
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
		if (m_gender != value)
		{
			m_gender = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Gender" });
		}
	}
	winrt::BikaClient::Blocks::ThumbBlock UserBlock::Thumb()
	{
		return m_thumb;
	}
	void UserBlock::Thumb(winrt::BikaClient::Blocks::ThumbBlock const& value)
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
		if (m_slogan != value)
		{
			m_slogan = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Slogan" });
		}
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
	void UserBlock::Clear()
	{
		m_title = L"";
		m_gender = L"";
		m_id = L"";
		m_verified = false;
		m_isPunched = false;
		m_createAt = L"";
		m_birthday = L"";
		m_slogan = L"";
		m_levelExp = L"(? / ?)";
		m_exp = 0;
		m_percent = 100;
		m_name = L"Gentleman";
		m_email = L"";
		m_levelString = L"Lv.0";
		m_level = L"";
		m_role = L"";
		m_character = L"";
		m_charactersString = L"";
		m_characters.Clear();
		m_thumb = winrt::BikaClient::Blocks::ThumbBlock{ nullptr };
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"ID" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Name" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"CreatedAt" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Birthday" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Email" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"LevelString" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Gender" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Img" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Slogan" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"LevelExp" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Percent" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Character" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Role" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Characters" });
		m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"CharactersString" });
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
