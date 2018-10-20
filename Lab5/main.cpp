#include <string>
#include <iostream>
using namespace std;

void printError(string category)
{
	cout << "Error: enter your " << category << " again..." << endl;
}

static class Validation // Статический класс валидации
{
public:
	static bool isLowChar(char c)  // Маленькая ли буква
	{
		return (c >= 'a') && (c <= 'z');
	}

	static bool isHighChar(char c) // Большая ли буква
	{
		return (c >= 'A') && (c <= 'Z');
	}

	static bool isNumber(string s)  // Число ли это
	{
		for (int i = 0; i < s.length(); i++)
			if (!(s[i] >= '0' && s[i] <= '9'))
				return false;
		return true;
	}


	static bool isName(string s, string category) // Проверка ФИО 
	{
		if (s.length() < 2)
		{
			printError(category);
			return false;
		}
		if (!Validation::isHighChar(s[0]))
		{
			printError(category);
			return false;
		}
		for (int i = 1; i < s.length(); i++)
			if (!Validation::isLowChar(s[i]) && !(s[i] == '-' && i != s.length() - 1))
			{
				printError(category);
				return false;
			}
		return true;
	}


	static bool isSerial(string s) // Проверка серии паспорта
	{ // КОСЯЯЯК

		int k = s.length();
		if (!(k == 4) && !Validation::isNumber(s))
		{
			cout << "Error: enter your serial again..." << endl;
			return false;
		}
	}

	static bool isDate(string s, string category) // Проверка даты  00.00.0000
	{
		if (s.length() != 10)
		{
			printError(category);
			return false;
		}
		if (!(s[2] == '.' && s[5] == '.'))
		{
			printError(category);
			return false;
		}

		if (!Validation::isNumber({ s[0], s[1], s[3], s[4], s[6], s[7], s[8], s[9] }))
		{
			printError(category);
			return false;
		}

		string number = { s[0], s[1] };
		int day = stoi(number);
		number = { s[3], s[4] };
		int mounth = stoi(number);
		
		if (!(day >= 1 && day <= 31) || !(mounth >= 1 && mounth <= 12))
		{
			printError(category);
			return false;
		}
	};

	static bool isBirthdayYear(string s)
	{
		return Date::getYear(s) >= 1900 && Date::getYear(s) <= 2018;
	}
};

	enum Sex
	{
		male, female
	};

	class Date
	{
	public:
		int day;
		int mounth;
		int year;

		static int getDay(string s)
		{
			string number = { s[0], s[1] };
			return stoi(number);
		}

		static int getMounth(string s)
		{
			string number = { s[3], s[4] };
			return stoi(number);
		}

		static int getYear(string s)
		{
			string number = { s[6], s[7], s[8], s[9] };
			return stoi(number);
		}

		Date(int day, int mounth, int year)
		{
			this->day = day;
			this->mounth = mounth;
			this->year = year;
		}
	};

	class Passport
	{
	public:
		int serial; // 1234
		int number; // 123456

		string surname; // Ivanov
		string name; // Ivan
		string patronymic; // Ivanovich

		Sex sex; // м/ж
		Date birthday; // 01.01.1970
		string placeOfBirth; // c. Moscow


		string issuedBy; // Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam...
		Date whenIssued; // 01.01.1970
		string departCode; // 123-456



	/*	string getNumberPass(string s) // Метод получения номера
		{
			string inputText;  // КОСЯЯЯК С НОМЕРАМИ
			do
			{
				cout << "Enter " << s << ": ";
				cin >> inputText;
			} while (!(Validation::isSerial(inputText)));
			cout << "Your " << s << ": " << inputText << endl;
			return inputText;
		}*/


		string getName(string category) // Метод получения ФИО
		{
			string inputText;
			do
			{
				cout << "Enter " << category << ": ";
				cin >> inputText;
			} while (!Validation::isName(inputText, category));
			cout << "Your " << category << ": " << inputText << endl;
			return inputText;
		}

		Date getDate(string category) // Метод получения даты
		{
			string inputText;
			do
			{
				cout << "Enter " << category << ": ";
				cin >> inputText;
			} while (!Validation::isDate(inputText, category) || !Validation::isBirthdayYear(inputText));
			cout << "Your " << category << ": " << inputText << endl;

			Date birthday = *new Date(Date::getDay(inputText),
				Date::getMounth(inputText),
				Date::getYear(inputText));

			return birthday;
		}


		Passport()
		{

		}

		Passport() // Констуктор
		{
			surname = getName("surname");
			name = getName("name");
			patronymic = getName("patronymic");

			birthday = getDate("birthday");
		}
	};





	int main()
	{
		Passport pass = *new Passport();
	}
