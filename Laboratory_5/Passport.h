#pragma once

#include "Sex.h"
#include "Date.h"

class Passport
{
public:
	int serial;
	int number;

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

	Date getDate(string category);

	Passport();
};