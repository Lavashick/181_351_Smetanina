#include "MyString.h"
#include <string>
#include <iostream>
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

	cout << "load() : " << endl;
	myStr.load("file_load.txt");
	cout << "save() : " << endl;
	myStr.save("file_save.txt");

	cout << "clear() :  " << endl;
	myStr.clear();
	myStr.print();


	MyString* myStr2 = new MyString();
	myStr.print();
	myStr.insert(str, 0);
	myStr.print();
	myStr.cut(5, 5);
	myStr.print();
	myStr.clear();
	myStr.print();	


	system("pause");
}

