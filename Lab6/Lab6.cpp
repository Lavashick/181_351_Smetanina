#include "pch.h"
#include <iostream>
#include "string"
using namespace std;

/*
Наследование - заимствование свойств и методов родительского класса в производном классе
синтаксис
class name_new_class : [type of наследования] имя родительского класса1,
	[type of наследования] имя родительского класса2
{
...
};
*/

//в род.классе	public		protected	private
//public		public		protected	private
//protected		protected	private		protected
//private		недоступен	недоступен	недоступен

/*
Метод, переопределенный в доч классе полностью заменит унаследованный родит метод
чтобы при запуске нового доч метода
*/

/*
Можно в  дочернем классе объявить с тем же именем, он заменит.
иначе, чтобы дополнить - надо явно вызвать родительский метод:
в род классе - void weapon::reload(){};
в дочернем классе - rifle::reload():weapon::reload(),...{};
*/

/*
Если объявить метод со словом virtual в данном классе
можно явно не реализовывать, и определить его (привести
реализацию) только в дочерних классах
*/


/*
4. //фии дб не больше 50-100 строк, дробить на маленькие нужно.
void fnc1(const тип1 параметр1, тип2 параметр2)
{
//параметр1=10; //компилятор выдаст ошибку
}
//объвление константного метода класса запрещает
		   ему менять какое-либо и св-ств объекта
											|
										   \/
void fnc2(тип1 параметр1, тип2 параметр2) const
{
//параметр1=10; //компилятор выдаст ошибку
}

*/
//
//
//
//
//
//

class Matrix {
private:
	double arrayMatrix[10][10] = { 0 };
	unsigned short columns;
	unsigned short rows;
public:

	bool summMatrix(Matrix matr2);
	bool multMatrix(Matrix matr2);
	void transMatrix();
	//virtual double scalMultVector(vector vec2);
	//virtual double scalMultVector(vector vec2);
	void printMat();
	void readMatr();
	unsigned short getRows();
	unsigned short getColumns();
	double getElem(unsigned short rov, unsigned short col);
	Matrix(/*const unsigned int a, const unsigned int b*/) {
		/*arrayMatrix[a][b]={ 0 };
		columns = a;
		rows = b;*/
	}
	~Matrix() {
	}
};


int main()
{
	/*int i=-15;
	double d = 1000.5e+03; //= 1000.5 * 10 ^ 3 = 1000500;
	//d = 1000.5e-03; = 1000.5*0.1 ^ 3 = 1.0005;
	float result1;
	long long result2; //
	result1 = i + d;//преобразует к большему справа, а потом к левому урезается.
	result2 = i / d;//
	//"123"+ "456"
//	std::string : "123456"
	//char * + char *//*/сложатся как unsigned int
	/*const char * ch1 = "123.6";//='1','2','3','\0'
	const wchar_t * ch2 = L"456";//к юникоду
	//???=ch1+ch2;

	std::cout << *ch1+*ch2;
	//strtod(); //srt TO double
	//double a=strtod(ch1);
	//strtol() //long
	//strtoul()//unsigned long
	//									ctrl+SPACE вызвать дополнение кода intellisense
	//									strl+Shift+SPACE меню параметров
	i=atoi(ch1);
	d = atof((char*)ch2);
	//
	std::cout << " "<<i<< " "<<d;//двоичное число
	//0.7=0.6999999999999999999999999999999999999999999.., //111001000
	//потому что двоичная алгебра за этим стоит
	char hhh[255] ="";
	char ggg[255] = "";

	std::cout << "\n first: ";
	std::cin >> hhh;
	std::cout << "\n second: ";
	std::cin >> ggg;
	std::cout << "\n";
	i = atoi(hhh);
	d = atof(ggg)*10/10;
	std::cout << i << "   " << d;

	//scanf_s("First ");

	//Создать клас матриц размера m*n 1<=m,n<=10 с операциями
	/*1) 	сложение
	a b   + k l   = a+k b+l
	c d     m n     c+m d+n //размеры матриц совпадают

	2)умножение

	а11 а12 а13			b11 b12
	а21 а22 а23 *		b21 b22 = c11 c12
						b31 b32   c21 c22 //c21=a21*b11+a22*b21+a23*b31
						cij=ai1*b1j+ai2*b2j+...ainbnj
						//столбцы а=строки б
	3)транспонирование

	4) печать
	5) ввод с клавы

	Создать класс наследник -вектор, длиной n,1<=n<=10, с дополнительными операциями
	1)скалярное поизведение
	2)умножение вектора на число

	*/
	//const int n = 10, m=10;

	//double mass[n]= 


	Matrix checking, checking2;
	checking.readMatr();
	checking2.readMatr();
	checking.printMat();
	checking2.printMat();

}

/*// lab6.cpp: определяет точку входа для консольного приложения.
//

/*
создать класс матриц matrix размера m*n, 1<=m<=10, 1<=n<=10, c операциями
1) сложение bool summMatrix(matrix matr2);
a b		+		k l		=		a+k 	b+l
c d				m n				c+m		d+n
верно, размеры матриц совпадают
2) умножение bool multMatrix(matrix matr2);
a11	a12	a13			b11	b12		c11	c12
a21	a22	a23		*	b21	b22	=	c21	c22
b31	b32

c21 = a21*b11+a22*b21+a23*b31
cij = ai1*b1j+ai2*b2j+...+ain*bnj
верно, если columns(a)=rows(b)
3) транспонирование bool transp();
|	a11	a12	a13|*			a11	a21
|	a21	a22	a23|		=	a12	a22
a13	a23
4) печать bool print();
5) ввод с клавиатуры bool input();

создать класс-наследник вектор vector, длиной n, 1<=n<=10, c дополнительными операциями
1) скалярное произведение double scalMultVector(vector vec2);
(a1 a2 a3)*(b1 b2 b3) = a1*b1+a2*b2+a3*b3
верно, если размеры соврадают
2) умножение вектора на число
(a1 a2 a3)*k = (a1*k a2*k a3*k)
*/
/*
#include "stdafx.h"
#include <iostream>

class matrix
{
private:
	//свойства класса
	double matr[10][10];
	int rows;
	int columns;
public:
	matrix();
	~matrix();

	//void setMatrix(int p_rows, int p_colums, int p_matr[10][10]);
	bool input();
	bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Connot get elenent. Index Error!\n";
		return	-1;
	}
};


int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.transp(); matrA.print();
	matrA.summMatrix(matrB); matrA.print();
	matrA.multMatrix(matrB); matrA.print();
	return 0;
}

matrix::matrix()
{
}

matrix::~matrix()
{
}

bool matrix::input()
{
	//считать количество строк
	//проверить, что введенно число в пределах [1,10]
	//иначе вернуть ошибку

	//считать количество столбцов
	//проверить, что введенно число в пределах [1,10]
	//иначе вернуть ошибку

	//считать элементы матрицы
	return true;
}*/
