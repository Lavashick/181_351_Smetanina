#include "pch.h"
#include <iostream>
int main()
{
	int int4 = 0;
	int * ptr_int4 = &int4;
	double double8 = 0.0;
	double * ptr_double8 = &double8;
	char char1 = ' ';
	char * ptr_char1 = &char1;
	long long4 = 0;
	long * ptr_long4 = &long4;
	bool boolochka1 = false;
	bool * ptr_bool1 = &boolochka1;



	std::cout << "|_____\t|_____\t|" << std::endl;
	std::cout << "|Type\t|Size\t|" << std::endl;
	std::cout << "|_____\t|_____\t|" << std::endl;
	std::cout << "|int\t|" << sizeof(ptr_int4) << "\t|" << std::endl;
	std::cout << "|double\t|" << sizeof(ptr_double8) << "\t|" << std::endl;
	std::cout << "|char\t|" << sizeof(ptr_char1) << "\t|" << std::endl;
	std::cout << "|long\t|" << sizeof(ptr_long4) << "\t|" << std::endl;
	std::cout << "|bool\t|" << sizeof(ptr_bool1) << "\t|" << std::endl;
	std::cout << "|_____\t|_____\t|" << std::endl;
	return 0;
}
