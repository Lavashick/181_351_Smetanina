#include <iostream>
#include <list>
using namespace std;


// ШАБЛОНЫ

/*
template <typename MyType>
MyType max(MyType* array, int len) {
	MyType m = array[0];
	for (int i = 1; i < len; i++) {
		if (array[i] > m)
			m = array[i];
	}
	return m;
}

int max(double* array, int len) {
	double m = array[0];
	for (int i = 1; i < len; i++) {
		if (array[i] > m)
			m = array[i];
	}
	return m;
}
*/

template<typename TT>
class MyList {
public: 
	TT element;
	MyList * prev;
	MyList * next;

	MyList();
	MyList(TT el);
	MyList();

	MyList<TT> next_elem() {

	}

	void print();
	void push


};


int main()
{
	MyList<int> li(5);


    return 0;
}

