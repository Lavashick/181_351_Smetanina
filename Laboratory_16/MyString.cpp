#include "MyString.h"


MyString::MyString() {  
	this->array = new char[0]; // Создаем новый массив
	this->length = 0; // Обнуляем длину 
}


MyString::MyString(char* array, int lenght) { // Конструктор, копирующий содержимое из массива char*
	this->array = new char[lenght]; // Создаем новый массив
	for (int i = 0; i < lenght; i++)
		this->array[i] = array[i]; // Переприсваиваем массив
	this->length = lenght; // Переприсваеваем длину
}

MyString::MyString(MyString* a) { 
	this->array = new char[a->length]; // Создаем новый массив
	for (int i = 0; i < a->length; i++)  // Переприсваеваем массив
		this->array[i] = a->array[i];
	this->length = a->length; // Переприсваеваем длину
}

MyString::MyString(string str) {  
	int k = str.length(); // Ищем новую длину
	this->array = new char[k]; // Создаем новый массив 
	for (int i = 0; i < k; i++) // Переприсваеваем массив
		this->array[i] = str[i];
	this->length = k;  // Переприсваеваем длину
}

void MyString::clear() { 
	delete[] this->array; // Удаляем предыдущий массив
	this->array = new char[0]; // Создаем новый массив нулевой длины
	this->length = 0; // Обнуяем длину массива 
}


void MyString::add(char* array, int lenght) { 
	char* newArray = new char[this->length + lenght]; //Создаем новый массив, размера суммы старых
	for (int i = 0; i < this->length; i++)
		newArray[i] = this->array[i]; // Записываем в него первую часть
	for (int i = 0; i < lenght; i++) // Проходим по второму массиву, который надо дописать справа
		newArray[this->length + i] = array[i]; // Записываем вторую часть
	this->length += lenght; // Переприсваиваем длину нового массива
	delete[](this->array); // Удаляем старый массив
	this->array = newArray; // Переприсваиваем новый массив
}

void MyString::add(string str) { 
	char* newArray = new char[this->length + str.length()]; //Создаем новый массив, размера суммы старых
	for (int i = 0; i < this->length; i++)
		newArray[i] = this->array[i]; // Записываем в него первую часть
	for (int i = 0; i < str.length(); i++) // Проходим по второму массиву, который надо дописать справа
		newArray[this->length + i] = array[i]; // Записываем вторую часть
	this->length += str.length(); // Переприсваиваем длину нового массива
	delete[](this->array); // Удаляем старый массив
	this->array = newArray; // Переприсваиваем новый массив
}

void MyString::insert(char* array, int position, int length) {
	if (position > this->length) {
		cout << "Error" << endl;
		return;
	}
	char* newArray = new char[this->length + length]; // Создали новый массив длинной сложенных строк
	for (int i = 0; i < position; i++) // Заполняем массив до вставки
		newArray[i] = this->array[i]; // Переприсваиваем первую часть
	for (int i = 0; i < length; i++) // Заполняем массив вставкой
		newArray[i + position] = array[i]; // Переприсваиваем
	for (int i = position; i < this->length; i++) // Заполняем массив после вставки
		newArray[length + i] = this->array[i]; // Переприсваиваем
	this->length += length; // Заменила длину
	delete[] this->array; // Удялаем старый массив
	this->array = newArray; // Заменяем старый массив на новый
}
	
void MyString::insert(string str, int position) {
	if (position > this->length) {
		cout << "Error" << endl;
		return;
	}
	char* newArray = new char[this->length + str.length()]; // Создали новый массив длинной сложенных строк
	for (int i = 0; i < position; i++) // Заполняем массив до вставки
		newArray[i] = this->array[i]; // Переприсваиваем первую часть
	for (int i = 0; i < str.length(); i++) // Заполняем массив вставкой
		newArray[i + position] = str[i]; // Переприсваиваем
	for (int i = position; i < this->length; i++) // Заполняем массив после вставки
		newArray[str.length() + i] = this->array[i]; // Переприсваиваем
	this->length += str.length(); // Заменила длину
	delete[] this->array; // Удялаем старый массив
	this->array = newArray; // Заменяем старый массив на новый
}

void MyString::cut(int length, int position) {
	if (position + length > this->length) {
		cout << "Error" << endl;
		return;
	}
	char* newArray = new char[this->length - length]; // Создали новый массив с учетом выччтенной строки
	for (int i = 0; i < position; i++) // Заполняем первую часть нового массива
		newArray[i] = this->array[i];
	for (int i = position + length; i < this->length; i++) //
		newArray[i - length] = this->array[i];
	this->length -= length; // Изменяем длину
	delete[] this->array; // Удаляем старый массив
	this->array = newArray; // Заменяем старый массив новым 
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


	


	


	


