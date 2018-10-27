#include <string>
#include <iostream>
#include "Validation.h"
#include "Passport.h"
#include "Sex.h"
#include <iomanip>

string Passport::getName(string category) // Метод получения ФИО
{
	string inputText;
	do
	{
		cout << "Enter " << category << ": ";
		cin >> inputText;
	} while (!Validation::isName(inputText, category));
	return inputText;
}

Sex Passport::getSex()
{
	string inputText;
	do
	{
		cout << "Enter your sex: ";
		cin >> inputText;
	} while (!Validation::isSex(inputText));
	if (inputText == "male")
		return Sex::MALE;
	else
		return Sex::FEMALE;
}

DepartCode Passport::getDepartCode()
{
	string inputText;
	do
	{
		cout << "Enter your depart code: ";
		cin >> inputText;
	} while (!Validation::isDepartCode(inputText));

	string code = { inputText[0], inputText[1], inputText[2] };
	int firstCode = stoi(code);

	code = { inputText[4], inputText[5], inputText[6] };
	int lastCode = stoi(code);

	return *new DepartCode(firstCode, lastCode);
}

string Passport::getIssuedBy()
{
	string inputText;
	do
	{
		cout << "Enter your issued by: ";
		cin >> inputText;
	} while (inputText.length() >= 300);

	return inputText;
}

string Passport::getPlaceOfBirth()
{
	string inputText;
	do
	{
		cout << "Enter your place of birth: ";
		cin >> inputText;
	} while (inputText.length() >= 30);

	return inputText;
}

const int firstWidth = 17;
const int secondWidth = 30;

void printTableElement(string first, string second)
{
	first = "| " + first;
	second = "| " + second;

	cout << left
		<< setw(firstWidth) << first
		<< setw(secondWidth) << second
		<< '|'
		<< endl;

	cout << '+';
	for (int i = 0; i < firstWidth - 1; i++)
		cout << '-';
	cout << '+';
	for (int i = 0; i < secondWidth - 1; i++)
		cout << '-';
	cout << '+' << endl;

}

void Passport::printData()
{

	cout << endl;

	cout << '+';
	for (int i = 0; i < firstWidth - 1; i++)
		cout << '-';
	cout << '+';
	for (int i = 0; i < secondWidth - 1; i++)
		cout << '-';
	cout << '+' << endl;

	printTableElement("DATA", "VALUE");

	string s = to_string(number.serial) + ' ' + to_string(number.number);
	printTableElement("Number", s);

	s = surname + ' ' + name + ' ' + patronymic;
	printTableElement("FIO", s);

	printTableElement("Sex", ((sex == Sex::MALE) ? "male" : "female"));

	s = to_string(birthday.day) + '.' + to_string(birthday.mounth) + '.' + to_string(birthday.year);
	printTableElement("Birthday", s);

	printTableElement("Place of birth", placeOfBirth);

	printTableElement("Issued by", issuedBy);

	s = to_string(whenIssued.day) + '.' + to_string(whenIssued.mounth) + '.' + to_string(whenIssued.year);
	printTableElement("When issued", s);

	printTableElement("Depart code", departCode.getStringValue());

	cout << endl;
}

Passport::Passport() // Констуктор
{
	surname = getName("surname");
	name = getName("name");
	patronymic = getName("patronymic");

	birthday = *new Date("birthday", true);
	whenIssued = *new Date("when issued", true);

	sex = getSex();
	departCode = getDepartCode();

	placeOfBirth = getPlaceOfBirth();
	issuedBy = getIssuedBy();
}