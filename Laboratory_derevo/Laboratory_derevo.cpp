#include <iostream>
using namespace std;

#include "Tree.h"

int main()
{
	Tree tree = *new Tree(10);
	tree.insert(89);
	tree.insert(76);
	tree.insert(34);
	tree.insert(99);
	tree.insert(12);
	tree.insert(98);
	tree.insert(56);
	tree.insert(97);
	tree.insert(6);
	tree.insert(54);
	tree.insert(1);
	tree.insert(56);
	tree.insert(43);

	tree.insert(77);

	tree.find(56);

	tree.print();

	tree.removeAll();
}