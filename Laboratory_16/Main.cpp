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

	MyString* myStr = new MyString(str);
	myStr->print();
	cout << "find() : " << endl;
	cout << myStr->find("wo") << endl;
	cout << myStr->find(array, 3) << endl;
	cout << myStr->find("wolll") << endl;

	cout << "insert() :  " << endl;
	myStr->insert(str, 5);
	myStr->print();

	cout << "cut() :  " << endl;
	myStr->cut(5, 5);
	myStr->print();

	cout << "clear() :  " << endl;
	myStr->clear();
	myStr->print();


	MyString* myStr2 = new MyString();
	myStr2->print();
	myStr2->insert(str, 0);
	myStr2->print();
	myStr2->cut(5, 5);
	myStr2->print();
	myStr2->clear();
	myStr2->print();	

	system("pause");
}

