#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");		
	
	cout << "\\n	Новая строка \n" ;
	cout << "\\b	Backspace \n" ;	
	cout << "\\r	Возврат каретки \n" ;
	cout << "\\t	Горизонтальная табуляция \n";
	cout << "\\v	Вертикальная табуляция \n" ;
	cout << "\\?    Литерал вопросительного знака \n" ;
	cout << "\\a	Звонок(предупреждение) \n" ;
	cout << "\\'	Одиночная кавычка \n" ;
	cout << "\"	Двойная кавычка \n" ;
	cout << "\\f	Перевод страницы \n" ;
	cout << "\\	Обратная косая черта \n" ;
}