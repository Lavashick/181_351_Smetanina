#include <iostream>
#include <string>
#include <iomanip>
#include "Labaratory_6.h"
#include <stdexcept>
using namespace std;


bool isLessTen(int a) // проверяет, входит ли число в промежуток от 1 до 10
{
	return (a >= 1 && a <= 10);
}

int** createDoubleArray(int lines, int colums)
{
	int ** newMatr = new int*[lines];
	for (int i = 0; i < lines; i++)
	{
		newMatr[i] = new int[colums];
		for (int j = 0; j < colums; j++)
			newMatr[i][j] = 0;
	}
	return newMatr;
}

void deleteDoubleArray(int ** array, int lines, int colums)
{
	for (int i = 0; i < lines; i++)
	{
		delete(array[i]);
	}
	delete(array);
}

void swap(int* a, int* b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

class Matrix
{

private:
	
	int ** matr;
	int lines; // писать ВСЕ ВРЕМЯ this->
	int colums;

	bool isRight(Matrix * mat)
	{
		return (this->lines == (*mat).getLines() && this->colums == (*mat).getColums());
	}


	bool isRightMult(Matrix * mat)
	{
		return (this->lines == (*mat).getColums());
	}


	bool isInMatrix(int line, int colum)
	{
		return this->lines >= line && this->colums >= colum;
	}

public:

	int getElement(int line, int colum) // возвращает элемент, т.к. он является приватным
	{
		if (!isInMatrix(line, colum))
		{
			cout << "Error" << endl;
		}
		else {
			return this->matr[line][colum];
		}
	}

	void setElement(int value, int line, int colum)
	{
		this->matr[line][colum] = value;
	}

	int getLines()
	{
		return lines;
	}

	int getColums()
	{
		return colums;
	}


	void input() // ввод матрицы
	{
		cout << "Enter the matrix: " << endl << endl;
		for (int i = 0; i < this->lines; i++)
			for (int j = 0; j < this->colums; j++)
				cin >> matr[i][j];
		cout << endl << endl;
	}


	void print() // вывод матрицы
	{
		for (int i = 0; i < this->lines; i++)
		{
			for (int j = 0; j < this->colums; j++)
				cout << left << setw(4) << matr[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	void transp() // транспонирование матрицы, т.е. меняем строки и столбцы 
	{
		// Создаем временную матрицу, кол-во строк которой равны кол-ву столбцов старой матрицы и наоборот
		int **newMatr = createDoubleArray(this->colums, this->lines); 

		// Строки старой матрицы сохраняем в столбцы новой
		for (int i = 0; i < this->colums; i++)
			for (int j = 0; j < this->lines; j++)
				newMatr[i][j] = this->matr[j][i];

		deleteDoubleArray(this->matr, this->lines, this->colums);
		this->matr = newMatr;
		// deleteDoubleArray(newMatr, this->colums, this->lines); - НЕЛЬЗЯ, УДАЛИТ ОСНОВНУЮ МАТРИЦУ
		swap(&this->colums, &this->lines); // Меняем кол-во строк и стобцов
	}


	void summ(Matrix *mat) // сумма матриц
	{
		if (isRight(&(*mat)))
		{
			for (int i = 0; i < this->lines; i++)
				for (int j = 0; j < this->colums; j++)
					matr[i][j] += (*mat).getElement(i, j);
		}
		else {
			cout << "Numer of lines and colums aren't the same, you can't summarize matrixes" << endl;
		}
	}
		
	void mult(Matrix *mat) // произведение матриц
	{
		if (isRightMult(&(*mat)))
		{
			int ** matrMul = createDoubleArray(this->lines, (*mat).getColums());
			for (int i = 0; i < this->lines; i++)
			{
				for (int j = 0; j < (*mat).getColums(); j++)
				{
					int sum = 0;
					for (int p = 0; p < this->colums; p++)
					{
						sum += this->matr[i][p] * (*mat).getElement(p, j);
					}
					matrMul[i][j] = sum;
				}
			}
			deleteDoubleArray(this->matr, this->lines, this->colums);
			this->matr = matrMul;
			this->colums = this->lines;
		}
		else {
			cout << "Numer of lines and colums aren't right, you can't multiply matrixes" << endl;
		}
	}

	
	
	Matrix(int lines, int colums) 
	{
		this->lines = lines;
		this->colums = colums;

		this->matr = createDoubleArray(this->lines, this->colums);
	}

	~Matrix()
	{
		deleteDoubleArray(matr, lines, colums);
	}
};




int inputLinesColums(string linCol, string number)
{
	cout << "Enter number of " << linCol << " in the " << number << " matrix: " << endl;
	int lc;
	cin >> lc; // узнаем кол-во строк или столбцов матрицы 

	while (!isLessTen(lc))
	{
		cout << "Error. Please, enter the number again: " << endl; // выдает ошибку при неправильном вводе
		cin >> lc;
	}
	return lc;
}

int main()
{
	int lin1 = inputLinesColums("lines", "first"); // спрашиваем инфу про матрицу А
	int col1 = inputLinesColums("colums", "first");

	Matrix matrA = *new Matrix(lin1, col1); // объявили матрицу А

	matrA.input(); // ввели матрицу А
	cout << "Matrix A:" << endl;
	matrA.print(); // вывели А

	{
		Matrix matrX = *new Matrix(1, 1); // Пример удаления матрицы
	}

	int lin2 = inputLinesColums("lines", "second"); // спрашиваем инфу про матрицу В
	int col2 = inputLinesColums("colums", "second");
	
	Matrix matrB = *new Matrix(lin2, col2); // Объявили матрицу В

	matrB.input(); // ввели матрицу В
	cout << "Matrix B:" << endl;
	matrB.print(); // вывели B

	cout << endl << endl << "Trans Matrix A:" << endl;
	matrA.transp(); // транспонировали А
	matrA.print(); // вывели А
	matrA.transp(); // транспонировали А

	matrA.print(); // вывели А

	cout << "+" << endl << endl;

	matrB.print(); // вывели В

	cout << "||" << endl << endl;

	matrA.summ(&matrB); // сложили А с В
	matrA.print(); // вывели новую матрицу 

	matrA.mult(&matrB); // умножили матрицу А и В
	matrA.print(); // вывели новую матрицу

	system("pause");
}