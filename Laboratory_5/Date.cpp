#include <iostream>
#include <string>
#include "Date.h"
#include "Validation.h"
using namespace std;

int Date::getDay(string s)
{
	string number = { s[0], s[1] };
	return stoi(number);
}

int Date::getMounth(string s)
{
	string number = { s[3], s[4] };
	return stoi(number);
}

int Date::getYear(string s)
{
	string number = { s[6], s[7], s[8], s[9] };
	return stoi(number);
}

string Date::getDate(string category, bool isBirthday) // Метод получения даты
{
	string inputText;
	do
	{
		cout << "Enter " << category << ": ";
		cin >> inputText;
	} while (!Validation::isDate(inputText, category) || !(isBirthday && Validation::isBirthdayYear(inputText)));
	cout << "Your " << category << ": " << inputText << endl;

	return inputText;
}

Date::Date() { }

Date::Date(string category, bool isBirthday)
{
	string date = getDate(category, isBirthday);

	day = getDay(date);
	mounth = getMounth(date);
	year = getYear(date);
}