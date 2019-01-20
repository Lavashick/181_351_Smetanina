#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

using namespace std;

int main()
{
	// работа с криптофункциями OpenSSL:
	// 1) создание объекта с настройками
	// 2) собственно, шифрование
	// 3) финализация
	// 4) и вывод зашифрованных данных

	// как правило, в литературе, структуры используются для хранения только данных
	// ни слова о методах и конструкторах/деструкторах
	struct name_of_my_struct // сродни классу
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};

	unsigned char *plaintext =
		(unsigned char *)"EVP_EncryptUpdate() encrypts inl bytes from the buffer in and writes the encrypted version to out";// исходный текст
	int plaintext_len = strlen((char *)plaintext); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

	// 1. Создаётся указатель на несуществующую структуру
	// структура - тип данных в C++, близка к КЛАССУ, различия минимальны
	EVP_CIPHER_CTX *ctx; // structure

	// 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv); // рандомайзер (случайный начальный вектор)

	// 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate
	int len;
	EVP_EncryptUpdate(ctx, // объект с настройками
		cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
		&len, // выходной параметр: длина полученного шифра
		plaintext, // входной параметр: что шифровать
		plaintext_len); // входной параметр : длина входных данных
	int cryptedtext_len = len;

	// 5. Финализация процесса шифрования
	// необходима, если последний блок заполнен данными не полностью
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	// 6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);

	// вывод зашифрованных данных
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;

	// РАСШИФРОВКА

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором

	// 3.
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;
	cout << cryptedtext << endl;

	// --- шифрование файла
	// производится точно так же, но порциями, в цикле
	// в цикле
	/*
		1) открытие файлов и настройка параметров OpenSSL
		2) считывание первого блока
		3) while(считанный_фрагмент > 0)
		{
			4) шифрование считанного
			5) запись зашифрованного массива в файл
			6) считывание следующего фрагмента
		}
		7) применение финализирующей фукнции
		8) запись финализирующего блока в файл
		9) закрытие файлов
	*/


	/*
	ifstream для чтения файлов
	ofstream для записи файлов
	fstream для модификации файлов
	*/





	// Делаем шифрование по маленьким кусочкам, ибо нельзя делать большие файлы разом
	ifstream file_text; // Файл для шифрования. ofstream
	ofstream file_cryption; // Файл для дешифрования. ifstream

	file_text.open("test.txt", std::fstream::in | std::fstream::binary); // Открытие в бинарном виде
	file_cryption.open("file_cryption.txt", std::fstream::out | std::fstream::binary); // Открытие файла тоже в бинарном виде
	if (!file_text) {
		std::cout << "Ошибка файла" << std::endl; // Обработка ошибки открытия файла
	}
	if (!file_cryption) {
		std::cout << "Ошибка файла" << std::endl; // Обработка ошибки открытия файла
	}

	char buffer[256] = { 0 }; 
	char * out_buf[256] = { 0 }; 
	unsigned int number_of_bytes = 0;
	ctx = EVP_CIPHER_CTX_new(); 
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // Забиваем нашу структуру настройками
	file_text.read(buffer, 256); // Оно считывает в буфер

	while (file_text.gcount() > 0)//бесконечный цикл считывания порций файла
	{
		// Шифруем
		EVP_EncryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, file_text.gcount()); // Последний входной параметр: длина входных данных
		// Запись порции в фаил
		file_cryption.write((const char *)out_buf, len); // Записываем все в фаил 
		file_text.read(buffer, 256); // Оно считывает опять в буфер
	}
	EVP_EncryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	file_cryption.write((const char*)out_buf, len); // Записали это в фаил
	file_cryption.close();
	file_text.close();
	memset(buffer, 0, sizeof(char) * 256); 
	memset(out_buf, 0, sizeof(char) * 256);


	fstream filecryingmore, just_file;// Файлы для шифрования и дешифрования

	filecryingmore.open("file_cryption.txt", std::fstream::in | std::fstream::binary); // Открываем их опять бинарными
	just_file.open("just_file.txt", std::fstream::out | std::fstream::binary);


	ctx = EVP_CIPHER_CTX_new();

	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

	filecryingmore.read(buffer, 256);
	while (filecryingmore.gcount() > 0) // Переделываем из шифра в буквы
	{
		// Расшифровка 
		EVP_DecryptUpdate(ctx, (unsigned char *)out_buf, &len, (unsigned char *)buffer, filecryingmore.gcount());

		// Запись расшифровки в файл 
		just_file.write((const char *)out_buf, len);

		// Чтение следующей порции 
		filecryingmore.read(buffer, 256);
	}

	EVP_DecryptFinal_ex(ctx, (unsigned char *)out_buf, &len);
	just_file.write((const char *)out_buf, len);

	just_file.close();
	filecryingmore.close();

	system("pause");
	return 0;
	getchar();
	return 0;
}


/*



*/

