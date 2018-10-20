#pragma once

#include "Sex.h"
#include "Date.h"

class Passport
{
public:
	class Number
	{
	public:
		int serial;
		int number;
		Number();
		enum Elements
		{
			SERIAL, NUMBER
		};
		int getNumber(Passport::Number::Elements type);
	};

	Number number;

	string surname;
	string name;
	string patronymic;

	Sex sex;
	Date birthday;
	string placeOfBirth;


	string issuedBy;
	Date whenIssued;
	string departCode;

	string getName(string category);

	Passport();
};