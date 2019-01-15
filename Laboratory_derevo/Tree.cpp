#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(int data) {
	root = new List(data);
	cout << data << endl;
}

void Tree::insert(int data) { // ���������� ���������
	List* newList = new List(data); // data - �������, ������� �� ���������. ������� ���� � ���� ���������
	List* l1 = NULL; // 
	List* l2 = NULL; // 
	l1 = this->root; 
	while (l1 != NULL) // ���� ����� �� ������ �� ��� ���, ���� ��� �� ����� ������
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