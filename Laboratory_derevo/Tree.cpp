#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(int data) {
	root = new List(data);
	cout << data << endl;
}

void Tree::insert(int data) { // Добавление элементов
	List* newList = new List(data); // data - элемент, который мы добавляем. Создаем лист с этим значением
	List* l1 = NULL; // 
	List* l2 = NULL; // 
	l1 = this->root; 
	while (l1 != NULL) // Идем влево по дереву до тех пор, пока оно не будет пустым
	{
		l2 = l1; 
		if (l1->getData() > data) {
			l1 = l1->getChild();
		}
		else {
			l1 = l1->getBrother();
		}
	}
	if (l2 == NULL) {
		this->root = newList;
	}
	else {
		if (data < l2->getData()) {
			l2->setChild(newList);
		}
		else {
			l2->setBrother(newList);
		}
	}
	
}

bool Tree::find(int data) {
	if (!this->root->find(data)) {
		std::cout << "Number " << data << " wasn't find" << std::endl;
		return false;
	}
	return true;
}

void Tree::print() {
	root->print(root);
}