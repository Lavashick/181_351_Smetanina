#pragma once
#include "Passport.h"
#include <string>
#include "Validation.h"

int Number::getNumber(Elements type)
{
	string inputText;
	do
	{
		cout << "Enter " << ((type == Number::NUMBER) ? "number" : "serial") << ": ";
		cin >> inputText;
	} while (!Validation::isNumberOfPassport(inputText, type));
	return stoi(inputText);
}

Number::Number()
{
	serial = getNumber(SERIAL);
	number = getNumber(NUMBER);
}