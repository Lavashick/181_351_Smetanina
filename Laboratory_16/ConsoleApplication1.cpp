#include "MyString.h"
#include <string>
#include <iostream>
using namespace std;


int main()
{
	string array = "Hello, world!";

	MyString* myStr = new MyString(array);
	myStr->print();
	myStr->insert(array, 5);
	myStr->print();
	myStr->cut(5, 5);
	myStr->print();
	myStr->clear();
	myStr->print();


	MyString* myStr2 = new MyString();
	myStr2->print();
	myStr2->insert(array, 0);
	myStr2->print();
	myStr2->cut(5, 5);
	myStr2->print();
	myStr2->clear();
	myStr2->print();




	

	system("pause");    
}

