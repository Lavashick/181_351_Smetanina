#include <iostream>
using namespace std;

// Обмен значениями
void mySwap(int * a, int * b)
{
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

// Сортировка по возрастанию методом пузырька
void bubbleSort(int array[], int len)
{
	for (int j = 0; j < len; j++)
		for (int i = 0; i < len - 1 - j; i++)
			if (array[i] > array[i + 1])
				mySwap(&array[i], &array[i + 1]);
}

// Вывод массива
void printArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
}

// Заполнение массива
void initArray(int array[], int len)
{
	cout << "Enter numbers (" << len << "): \n";
	for (int i = 0; i < len; i++)
		cin >> array[i];
}

// Метод сортировки шейкером
void shakerSort(int array[], int len)
{
	for (int i = 0; i < len / 2; i++) // По кол-ву проходов, один проход- туда и обратно
	{
		for (int j = i; j < len - i - 1; j++) // Идет до конца массива
		{
			if (array[j] > array[j + 1])
				mySwap(&array[j], &array[j + 1]); // Меняет местами
		}
		for (int j = len - i - 2; j > i; j--) // Идет в обратную сторону
			if (array[j] < array[j - 1])
				mySwap(&array[j], &array[j - 1]); // Меняет местами
	}
}

int main()
{
	const int len = 5;
	int A[len];
	initArray(A, len);
	bubbleSort(A, len);
	shakerSort(A, len);
	printArray(A, len);
}