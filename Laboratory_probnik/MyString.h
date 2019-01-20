#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")
using namespace std;


class MyString {
private:
	char* array; // Массив символов
	int length; // Длина массива символов
public:

	char* getArray();
	int getLength();
	void setArray(string str);

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

	// 23
	// Записывает в файл load
	void save(string adress_file);

	// Читает из файла
	void load(string adress_file);   

	// Перегрузка оператора +
	MyString operator+(MyString s1);

	// Метод для шифрования
	void encrypt();

	// Метод для дешифрования 
	void decrypt();
};

// Перегрузка оператора <<
ostream& operator<<(ostream &s, MyString &s1); // Передаем ссылку на поток и то, что надо печатать

// Перегрузка оператора >>
istream& operator>>(istream &s, MyString &s1);