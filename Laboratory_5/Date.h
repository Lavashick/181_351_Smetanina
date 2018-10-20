#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int day;
	int mounth;
	int year;

	static int getDay(string s);

	static int getMounth(string s);

	static int getYear(string s);

	string getDate(string category, bool isBirthday);

	Date();
	Date(string category, bool isBirthday);
};