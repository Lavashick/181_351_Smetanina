#include "Passport.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Passport pass = *new Passport();
	pass.printData();

	system("pause");
}