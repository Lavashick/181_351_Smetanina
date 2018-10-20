#pragma once
#include <iostream>
#include "Passport.h"
using namespace std;

class Validation
{
public:
	static bool isLowChar(char c);

	static bool isHighChar(char c);

	static bool isNumber(string s);

	static bool isName(string s, string category);

	static bool isNumberOfPassport(string s, Passport::Number::Elements type);

	static bool isDate(string s, string category);

	static bool isBirthdayYear(string s);
};