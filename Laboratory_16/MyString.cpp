#include "MyString.h"


MyString::MyString() {  
	this->array = new char[0]; // ������� ����� ������
	this->length = 0; // �������� ����� 
}


MyString::MyString(char* array, int lenght) { // �����������, ���������� ���������� �� ������� char*
	this->array = new char[lenght]; // ������� ����� ������
	for (int i = 0; i < lenght; i++)
		this->array[i] = array[i]; // ��������������� ������
	this->length = lenght; // ��������������� �����
}

MyString::MyString(MyString* a) { 
	this->array = new char[a->length]; // ������� ����� ������
	for (int i = 0; i < a->length; i++)  // ��������������� ������
		this->array[i] = a->array[i];
	this->length = a->length; // ��������������� �����
}

MyString::MyString(string str) {  
	int k = str.length(); // ���� ����� �����
	this->array = new char[k]; // ������� ����� ������ 
	for (int i = 0; i < k; i++) // ��������������� ������
		this->array[i] = str[i];
	this->length = k;  // ��������������� �����
}

void MyString::clear() { 
	delete[] this->array; // ������� ���������� ������
	this->array = new char[0]; // ������� ����� ������ ������� �����
	this->length = 0; // ������� ����� ������� 
}


void MyString::add(char* array, int lenght) { 
	char* newArray = new char[this->length + lenght]; //������� ����� ������, ������� ����� ������
	for (int i = 0; i < this->length; i++)
		newArray[i] = this->array[i]; // ���������� � ���� ������ �����
	for (int i = 0; i < lenght; i++) // �������� �� ������� �������, ������� ���� �������� ������
		newArray[this->length + i] = array[i]; // ���������� ������ �����
	this->length += lenght; // ��������������� ����� ������ �������
	delete[](this->array); // ������� ������ ������
	this->array = newArray; // ��������������� ����� ������
}

void MyString::add(string str) { 
	char* newArray = new char[this->length + str.length()]; //������� ����� ������, ������� ����� ������
	for (int i = 0; i < this->length; i++)
		newArray[i] = this->array[i]; // ���������� � ���� ������ �����
	for (int i = 0; i < str.length(); i++) // �������� �� ������� �������, ������� ���� �������� ������
		newArray[this->length + i] = array[i]; // ���������� ������ �����
	this->length += str.length(); // ��������������� ����� ������ �������
	delete[](this->array); // ������� ������ ������
	this->array = newArray; // ��������������� ����� ������
}

void MyString::insert(char* array, int position, int length) {
	if (position > this->length) {
		cout << "Error" << endl;
		return;
	}
	char* newArray = new char[this->length + length]; // ������� ����� ������ ������� ��������� �����
	for (int i = 0; i < position; i++) // ��������� ������ �� �������
		newArray[i] = this->array[i]; // ��������������� ������ �����
	for (int i = 0; i < length; i++) // ��������� ������ ��������
		newArray[i + position] = array[i]; // ���������������
	for (int i = position; i < this->length; i++) // ��������� ������ ����� �������
		newArray[length + i] = this->array[i]; // ���������������
	this->length += length; // �������� �����
	delete[] this->array; // ������� ������ ������
	this->array = newArray; // �������� ������ ������ �� �����
}
	
void MyString::insert(string str, int position) {
	if (position > this->length) {
		cout << "Error" << endl;
		return;
	}
	char* newArray = new char[this->length + str.length()]; // ������� ����� ������ ������� ��������� �����
	for (int i = 0; i < position; i++) // ��������� ������ �� �������
		newArray[i] = this->array[i]; // ��������������� ������ �����
	for (int i = 0; i < str.length(); i++) // ��������� ������ ��������
		newArray[i + position] = str[i]; // ���������������
	for (int i = position; i < this->length; i++) // ��������� ������ ����� �������
		newArray[str.length() + i] = this->array[i]; // ���������������
	this->length += str.length(); // �������� �����
	delete[] this->array; // ������� ������ ������
	this->array = newArray; // �������� ������ ������ �� �����
}

void MyString::cut(int length, int position) {
	if (position + length > this->length) {
		cout << "Error" << endl;
		return;
	}
	char* newArray = new char[this->length - length]; // ������� ����� ������ � ������ ���������� ������
	for (int i = 0; i < position; i++) // ��������� ������ ����� ������ �������
		newArray[i] = this->array[i];
	for (int i = position + length; i < this->length; i++) //
		newArray[i - length] = this->array[i];
	this->length -= length; // �������� �����
	delete[] this->array; // ������� ������ ������
	this->array = newArray; // �������� ������ ������ ����� 
}
	
void MyString::print() {
	for (int i = 0; i < length; i++)
		cout << array[i];
	cout << endl;
}

/*
MyString MyString::operator+(const MyString & other) {
	MyString 
}
*/

bool MyString::find(char* array) {

}


	


	


	


