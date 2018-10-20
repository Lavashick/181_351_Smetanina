#pragma once
#include "Passport.h"
#include <string>
#include "Validation.h"

int Passport::Number::getNumber(Elements type)
{
	string inputText;
	do
	{
		cout << "Enter : " << (type == NUMBER) ? "number" : "serial";
		cin >> inputText;
	} while (!Validation::isNumberOfPassport(inputText, type));
	cout << "Your number: " << inputText << endl;
	return stoi(inputText);
}

Passport::Number::Number()
{
	number = getNumber(NUMBER);
	serial = getNumber(SERIAL);
}