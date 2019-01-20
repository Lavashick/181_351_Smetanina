#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
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
	char* array; // ������ ��������
	int length; // ����� ������� ��������
public:

	char* getArray();
	int getLength();
	void setArray(string str);

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

	// 23
	// ���������� � ���� load
	void save(string adress_file);

	// ������ �� �����
	void load(string adress_file);   

	// ���������� ��������� +
	MyString operator+(MyString s1);

	// ����� ��� ����������
	void encrypt();

	// ����� ��� ������������ 
	void decrypt();
};

// ���������� ��������� <<
ostream& operator<<(ostream &s, MyString &s1); // �������� ������ �� ����� � ��, ��� ���� ��������

// ���������� ��������� >>
istream& operator>>(istream &s, MyString &s1);