#pragma once

#include "Sex.h"
#include "Date.h"


class Number
{
public:
	int serial;
	int number;

	enum Elements
	{
		SERIAL, NUMBER
	};

	int getNumber(Elements type);

	Number();
};

class Passport
{
public:
	

	

	string surname;
	string name;
	string patronymic;

	Sex sex;
	Date birthday;
	string placeOfBirth;


	string issuedBy;
	Date whenIssued;
	string departCode;
	Number number;
	string getName(string category);

	Passport();
};