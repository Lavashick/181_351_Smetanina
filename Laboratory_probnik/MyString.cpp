#include "MyString.h"



MyString::MyString() {  
	this->array = new char[0]; // Создаем новый массив
	this->length = 0; // Обнуляем длину 
}

char* MyString::getArray() {
	return this->array;
}

int MyString::getLength() {
	return this->length;
}


MyString::MyString(char* array, int lenght) { // Конструктор, копирующий содержимое из массива char*
	this->array = new char[lenght]; // Создаем новый массив
	for (int i = 0; i < lenght; i++)
		this->array[i] = array[i]; // Переприсваиваем массив
	this->length = lenght; // Переприсваеваем длину
}

void MyString::setArray(string str) {
	delete[] this->array;
	this->array = new char[str.length()];
	this->length = str.length();
	for (int i = 0; i < this->length; i++)
		this->array[i] = str[i];
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
	this->length += strlen(array); // Заменила длину
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
	char* newArray = new char[this->length - length]; // Создали новый массив с учетом вычтенной строки
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


int MyString::find(char* array, int length) {
	int count = 0;
	int index = 0;
	for (int i = 0; i < this->length; i++) {
		if (this->array[i] == array[count]) {
			if (count == 0)
				index = i;
			count++;
			if (count == length)
				return index;			
		}
		else {
			count = 0;
		}
	}
	cout << "String isn't find" << endl;
	return -1;
}

int MyString::find(string str) {
	int count = 0;
	int index = 0;
	for (int i = 0; i < this->length; i++) {
		if (this->array[i] == str[count]) {
			if (count == 0)
				index = i;
			count++;
			if (count == str.length())
				return index;
		}
		else {
			count = 0;
		}
	}
	cout << "String isn't find" << endl;
	return -1;
	}


void MyString::save(string address_file) {
	fstream file_save;
	file_save.open(address_file, fstream::out);
	if (!file_save.is_open()) {
		cout << "File is not open" << endl;
		return;
	}
	else {
		cout << "File is open" << endl;
	}
	for (int i = 0; i < this->length; i++)
		file_save << array[i];
	file_save.close();
}



void MyString::load(string address_file) { // Не забыть создать новый массив!!!
	fstream file_load;
	file_load.open(address_file, fstream::in);
	if (!file_load.is_open()) {
		cout << "File is not open" << endl;
		return;
	}
	else {
		cout << "File is open" << endl;
	}
	string text;
	getline(file_load, text);
	cout << "Text from file: " << text << endl;
	this->length = text.length();
	char* newArray = new char[this->length];
	for (int i = 0; i < this->length; i++) 
		newArray[i] = text[i];
	delete[] this->array;
	this->array = newArray;
	file_load.close();
}
	
MyString MyString::operator+(MyString s1) {
	char* newArray = new char[this->length + s1.length];
	for (int i = 0; i < this->length; i++) 
		newArray[i] = this->array[i];
	for (int i = 0; i < s1.length; i++)
		newArray[i + this->length] = s1.array[i];

	MyString newStr = *new MyString(newArray, this->length + s1.length);
	return newStr;
}

ostream& operator<<(ostream &s, MyString &s1) {
	for (int i = 0; i < s1.getLength(); i++)
		s << s1.getArray()[i];
	return s;
}
	
istream& operator>>(istream &s, MyString &s1) {
	string str;
	s >> str;
	s1.setArray(str);
	return s;
}


void MyString::encrypt() {
	unsigned char *plaintext = (unsigned char*)this->array;
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	EVP_CIPHER_CTX *ctx; 
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); 
	// Процесс шифрования
	int len;
	EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len); 
	int cryptedtext_len = len;
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;
	this->length = cryptedtext_len;
	EVP_CIPHER_CTX_free(ctx); // Удаление структуры
	// присваивание зашифрованных данных
	for (int i = 0; i < cryptedtext_len; i++)
	{
		this->array[i] = cryptedtext[i];
	}
	cout << endl;
}




/*
void MyString::decrypt() {
	unsigned char *plaintext = (unsigned char*)this->array;
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	// Процесс шифрования
	int len;
	EVP_EncryptUpdate(ctx, cryptedtext, &len, plaintext, plaintext_len);
	int cryptedtext_len = len;
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;
	EVP_CIPHER_CTX_free(ctx); // Удаление структуры



	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;
}
*/