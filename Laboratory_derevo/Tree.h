#pragma once

// —оздает класс дерева с корнем, листами и значени€ми в листочках
class Tree {

	class List {
		List* brother;
		List* child;
		int data;

	public:
		// »щем есть ли значение
		bool find(int data);
		int getData();
		List* getChild();
		List* getBrother();
		void setChild(List* newList);
		void setBrother(List* newList);
		List(int data);
		void remove();
		void print(List* list);
	};

	List* root;

public:
	bool find(int data);
	void insert(int data);
	void print();
	void removeAll();

	Tree(int data);
};