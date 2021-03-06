#include <iostream>
#include <iomanip>

int main()
{
	// Создать целочисленные переменные а = 300
	// b = 560
	// Вывести на экран a * a * b * b
	// b / a
	// символ_A + a
	int a = 300, b = 560;
	std::cout << "a * a * b * b = " << a * a * b * b << std::endl;
	int max_int = 0b01111111111111111111111111111111;
	std::cout << "SizeOfInt = " << sizeof(int) << std::endl;

	std::cout << "b / a = " << b / a << std::endl;
	std::cout << "A+" << a << std::endl;
	/*
	 Вывести таблицу на экран
	 тип данных - занимаемый размер - минимальное значение - максимальное значение
	 bool
	 char
	 int
	 short
	 long
	 long long
	 double
	 */

	std::cout << std::left
		<< std::setw(10) << "TYPE"
		<< std::setw(10) << "SIZE"
		<< std::setw(30) << "MIN"
		<< std::setw(30) << "MAX"
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "bool"
		<< std::setw(10) << sizeof(bool)
		<< std::setw(30) << 0
		<< std::setw(30) << 128
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "int"
		<< std::setw(10) << sizeof(int)
		<< std::setw(30) << INT_MIN
		<< std::setw(30) << INT_MAX
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "char"
		<< std::setw(10) << sizeof(char)
		<< std::setw(30) << CHAR_MIN
		<< std::setw(30) << CHAR_MAX
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "short"
		<< std::setw(10) << sizeof(short)
		<< std::setw(30) << SHRT_MIN
		<< std::setw(30) << SHRT_MAX
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "long"
		<< std::setw(10) << sizeof(long)
		<< std::setw(30) << LONG_MIN
		<< std::setw(30) << LONG_MAX
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "double"
		<< std::setw(10) << sizeof(double)
		<< std::setw(30) << DBL_MIN
		<< std::setw(30) << DBL_MAX
		<< std::endl;

	std::cout << std::left
		<< std::setw(10) << "long long"
		<< std::setw(10) << sizeof(long long)
		<< std::setw(30) << LLONG_MIN
		<< std::setw(30) << LLONG_MAX
		<< std::endl;

	system("pause");
}