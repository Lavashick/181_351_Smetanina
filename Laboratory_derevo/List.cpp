#include <iostream>
#include "Tree.h"


Tree::List::List(int data) {
	this->data = data;
}

bool Tree::List::find(int data) { // data - число, которое мы ищем
	if (this->child != NULL) { // Пока левая ветка не пустая:
		if (this->child->find(data)) 
			return true; // Сравниваем, совпадает ли в рекурсии число, если найдено, то возвращает true
	}
	if (this->brother != NULL) {
		if (this->brother->find(data))
			return true;
	}
	if (this->data == data) {
		std::cout << "Number " << data << " was find" << std::endl;
		std::cout << "Address of this number is: " << &this->data << std::endl;
		return true;
	}
	else {
		return false;
	}
}

int Tree::List::getData() {
	return this->data;
}

Tree::List* Tree::List::getChild() {
	return this->child;
}

Tree::List* Tree::List::getBrother() {
	return this->brother;
}

void Tree::List::setChild(List* newList) {
	this->child = newList;
}

void Tree::List::setBrother(List* newList) {
	this->brother = newList;
}

int tabs = 0;

void Tree::List::print(List* list) {
	if (!list) return;
	tabs++;

	print(list->child);

	for (int i = 0; i < tabs; i++) std::cout << "  ";
	std::cout << list->data << std::endl;


	print(list->brother);

	tabs--;
	return;
}

void Tree::List::remove() {
	if (this->child != NULL) {
		this->child->remove();
		this->child = NULL;
	}

	if (this->brother != NULL) {
		this->brother->remove();
		this->brother = NULL;
	}

	std::cout << "List " << this << " was delete" << std::endl;
	delete(this);
}