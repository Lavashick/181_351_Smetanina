#pragma once

// ������� ����� ������ � ������, ������� � ���������� � ���������
class Tree {

	class List {
		List* brother;
		List* child;
		int data;

	public:
		// ���� ���� �� ��������
		bool find(int data);
		int getData();
		List* getChild();
		List* getBrother();
		void setChild(List* newList);
		void setBrother(List* newList);
		List(int data);
		void print(List* list);
	};

	List* root;

public:
	bool find(int data);
	void insert(int data);
	void print();

	Tree(int data);
};