#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MyString {
public:
	char* array; // Массив символов
	int length; // Длина массива символов

	// 2
	// Конструктор нулевой длины без параметров
	MyString();

	// 3
	// Конструктор, копирующий содержимое из string
	MyString(char* array, int lenght);

	// 4
	// Конструктор, копирующий содержимое из объекта анаогичного класса
	MyString(MyString* a); 


	// 5
	// Конструктор, копирующий содержимое из string
	MyString(string str); 


	// 6
	// Удаление
	void clear();

	// 7
	// Складывает имеющуюся строку с принимаемой char*
	void add(char* array, int lenght);
	// Складывает имеющуюся строку с принимаемой string
	void add(string str);

	// 8
	// Вставляет в заданную позицию внутри строки строку char*
	void insert(char* array, int position, int length);
	// Вставляет в заданную позицию внутри строки строку string
	void insert(string str, int position);


	// 9
	// Удаляет с заданной позиции заданное кол-во символов и уменьшает длину строки на указанное кол-во символов
	void cut(int length, int position);

	/*
	// 16
	// Перегрузки для + и <<
	MyString operator +(const MyString & other);
	*/

	// Печатает
	void print();
	 // 22
	// Осуществляет поиск последоватеьности символов *char или строку в строке класса
	int find(string str); 
	int find(char* array, int length);
};