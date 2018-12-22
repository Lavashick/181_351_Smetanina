#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MyString {
public:
	char* array; // ������ ��������
	int length; // ����� ������� ��������

	// 2
	// ����������� ������� ����� ��� ����������
	MyString();

	// 3
	// �����������, ���������� ���������� �� string
	MyString(char* array, int lenght);

	// 4
	// �����������, ���������� ���������� �� ������� ����������� ������
	MyString(MyString* a); 


	// 5
	// �����������, ���������� ���������� �� string
	MyString(string str); 


	// 6
	// ��������
	void clear();

	// 7
	// ���������� ��������� ������ � ����������� char*
	void add(char* array, int lenght);
	// ���������� ��������� ������ � ����������� string
	void add(string str);

	// 8
	// ��������� � �������� ������� ������ ������ ������ char*
	void insert(char* array, int position, int length);
	// ��������� � �������� ������� ������ ������ ������ string
	void insert(string str, int position);


	// 9
	// ������� � �������� ������� �������� ���-�� �������� � ��������� ����� ������ �� ��������� ���-�� ��������
	void cut(int length, int position);

	/*
	// 16
	// ���������� ��� + � <<
	MyString operator +(const MyString & other);
	*/

	// ��������
	void print();
	 // 22
	// ������������ ����� ����������������� �������� *char ��� ������ � ������ ������
	int find(string str); 
	int find(char* array, int length);
};