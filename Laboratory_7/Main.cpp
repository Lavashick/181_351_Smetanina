#include <iostream>
using namespace std;



int main()
{
	// Создали элемент int с указателем
	int * in = new int;

	// Удалили его
	delete(in);


	int n = 10; int m = 15;

	// Создали int с двойным указателем и присвоили ему массив int, элементы которого являются указателем
	int ** doubleArray = new int *[n];
	for (int i = 0; i < n; i++)
	{
		// Теперь для элементов этого массива создаем массивы
		doubleArray[i] = new int[m];
		for (int j = 0; j < m; j++)
			// И уже этим массивам даем числа
			doubleArray[i][j] = rand();
	}

	cout << "Address \t\t Index \t\t Value" << endl;
	cout << "--------------------------------------------" << endl << endl;

	cout << &doubleArray << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << &doubleArray[i] << '\t' << i << endl << endl;
		for (int j = 0; j < m; j++)
			cout << &doubleArray[i][j] << '\t' << i << ' ' << j <<  '\t' << doubleArray[i][j] << endl;
		cout << endl;
	}


	// Удаляем двумерный массив из памяти
	for (int i = 0; i < n; i++)
		delete[] doubleArray[i]; // Сначала удалим все подмассивы
	delete[] doubleArray;



	system("pause");



    return 0;
}

