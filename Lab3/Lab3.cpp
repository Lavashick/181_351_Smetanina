#include "pch.h"
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

// Выводмассива
void printArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
		cout << array[i] << " ";
}


// Заполнение массива
void initArray(int array[], int len)
{
	cout << "Enter numbers: \n";
	for (int i = 0; i < len; i++)
		cin >> array[i];
}

int main()
{
	const int l = 5;
	int A[l];
	initArray(A, l);
	bubbleSort(A, l);
	printArray(A, l);
}