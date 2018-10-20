#include <iostream>
#include <string>
#include "Error.h"
#include "Date.h"
#include "Validation.h"
#include "Passport.h"
using namespace std;


// ПРОВЕРКИ



bool Validation::isLowChar(char c)  // Маленькая ли буква
{
	return (c >= 'a') && (c <= 'z');
}

bool Validation::isHighChar(char c) // Большая ли буква
{
	return (c >= 'A') && (c <= 'Z');
}

bool Validation::isNumber(string s)  // Число ли это
{
	for (int i = 0; i < s.length(); i++)
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
	return true;
}

bool Validation::isName(string s, string category) // Проверка ФИО 
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

bool Validation::isNumberOfPassport(string s, Number::Elements type) // Проверка номера паспорта
{
	int k = s.length();
	if (!((type == Number::Elements::NUMBER) ? k == 6 : k == 4) || !Validation::isNumber(s))
	{
		cout << "Error: enter your " << ((type ==Number::Elements::NUMBER) ? "number" : "serial") << " again..." << endl;
		return false;
	}
}


bool Validation::isDate(string s, string category) // Проверка даты  00.00.0000
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

bool Validation::isBirthdayYear(string s)
{
	if (!(Date::getYear(s) >= 1900 && Date::getYear(s) <= 2018))
	{
		printError("birthday");
		return false;
	}
	else {
		return true;
	}
}