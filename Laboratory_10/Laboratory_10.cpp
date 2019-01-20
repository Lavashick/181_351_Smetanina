// Работа с ФАЙЛАМИ

#include <iostream>
#include <fstream>
using namespace std;

// Открываем файл "тест":

int main() {

	ifstream file; // Объявляем сам этот файл
	file.open("test.txt", fstream::in | fstream::binary);



}








/* 
ifstream file;
file.open("test.txt", ios::in | ios::binary);
Оператор логического ИЛИ(| ) позволяет составить режим с любым сочетанием флагов.Так, чтобы, открывая файл по записи, случайно не затереть существующий файл с тем же именем, надо использовать следующую форму :

ofstream file;
file.open("test.txt", ios::out | ios::app);
Предполагается, что к проекту подключён соответствующий заголовочный файл :

#include <fstream.h>
Для проверки того удалось ли открыть файл, можно применять конструкцию

if (!file) {
	//Обработка ошибки открытия файла



*/
