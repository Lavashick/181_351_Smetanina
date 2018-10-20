#include <string>
#include <iostream>
#include "Validation.h"
#include "Date.h"
#include "Sex.h"
#include "Passport.h"

string Passport::getName(string category) // Метод получения ФИО
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

Date Passport::getDate(string category) // Метод получения даты
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

Passport::Passport() // Констуктор
{
	surname = getName("surname");
	name = getName("name");
	patronymic = getName("patronymic");

	birthday = getDate("birthday");
}