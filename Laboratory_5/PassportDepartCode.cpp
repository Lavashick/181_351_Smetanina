#include "Passport.h"
#include <string>

int DepartCode::getValue()
{
	return firstCode * 1000 + lastCode;
}

string DepartCode::getStringValue()
{
	return to_string(firstCode) + '-' + to_string(lastCode);
}

void DepartCode::print()
{
	cout << firstCode << "-" << lastCode;
}

DepartCode::DepartCode(int firstCode, int lastCode)
{
	this->firstCode = firstCode;
	this->lastCode = lastCode;
}

DepartCode::DepartCode() { }