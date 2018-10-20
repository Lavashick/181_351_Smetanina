#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int Date::getDay(string s)
{
	string number = { s[0], s[1] };
	return stoi(number);
}

int Date::getMounth(string s)
{
	string number = { s[3], s[4] };
	return stoi(number);
}

int Date::getYear(string s)
{
	string number = { s[6], s[7], s[8], s[9] };
	return stoi(number);
}

Date::Date() { }

Date::Date(int day, int mounth, int year)
{
	this->day = day;
	this->mounth = mounth;
	this->year = year;
}