#include "MyString.h"
#include <string>
#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
using namespace std;


int main()
{
	char* array = new char[3];
	array[0] = 'e';
	array[1] = 'l';
	array[2] = 'l';


	string str = "Hello, world!";

	MyString myStr = *new MyString(str);
	myStr.print();

	


	cout << "find() : " << endl;
	cout << myStr.find("wo") << endl;
	cout << myStr.find(array, 3) << endl;
	cout << myStr.find("wolll") << endl;


	cout << "insert() :  " << endl;
	myStr.insert(str, 5);
	myStr.print();

	

	cout << "cut() :  " << endl;
	myStr.cut(5, 5);
	myStr.print();

	MyString myStr2 = *new MyString();
	myStr2.print();
	myStr2.insert(str, 0);
	myStr2.print();
	myStr2.cut(5, 5);
	myStr2.print();


	cout << "Operator + : " <<  endl;
	MyString a = myStr + myStr2;
	cout << a << endl << endl;

	cout << "load() : " << endl;
	myStr.load("file_load.txt");
	cout << "save() : " << endl;
	myStr.save("file_save.txt");



	cout << "clear() :  " << endl;
	myStr.clear();
	myStr.print();

	

	cin >> myStr;
	cout << myStr;


	cout << "Encryption text: " << endl << endl;
	myStr.encrypt();
	myStr.print();

	myStr2.clear();
	myStr2.print();	

	

	system("pause");
}

