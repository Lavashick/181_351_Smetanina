#pragma once

#include "Sex.h"
#include "Date.h"

class DepartCode
{
private:
	int firstCode;
	int lastCode;

public:
	int getValue();
	string getStringValue();
	void print();

	DepartCode(int firstCode, int lastCode);
	DepartCode();
};

class Number
{
public:
	int serial;
	int number;

	enum Elements
	{
		SERIAL, NUMBER
	};

	Number();

private:
	int getNumber(Elements type);
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
	DepartCode departCode;
	Number number;

	void printData();

	Passport();

private:
	string getName(string category);
	Sex getSex();
	string getPlaceOfBirth();
	string getIssuedBy();
	DepartCode getDepartCode();
};