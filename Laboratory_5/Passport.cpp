#include <string>
#include <iostream>
#include "Validation.h"
#include "Passport.h"

string Passport::getName(string category) // ����� ��������� ���
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

Passport::Passport() // ����������
{
	surname = getName("surname");
	name = getName("name");
	patronymic = getName("patronymic");

	birthday = *new Date("birthday", true);
	whenIssued = *new Date("when issued", true);

	number = *new Number();
}