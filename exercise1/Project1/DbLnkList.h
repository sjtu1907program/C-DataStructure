#pragma once
/*
	Doubly linked list
*/
#include <iostream>

//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};

struct DbListNode {
	int val;
	DbListNode *pre;
	DbListNode *next;
	DbListNode(int x, DbListNode * _pre  = nullptr, DbListNode * next = nullptr) : val(x), pre(_pre), next(next) {}
};

struct DbLinkList {
//members
	DbListNode* m_head{ nullptr };
	DbListNode* m_tail{ nullptr };
	int m_size;

//functions
	DbLinkList(int v[], int size);

	~DbLinkList();
	
	int size();

	void erase(int x);

	void insert_front(int v);
	void insert_back(int v);
	void insert(DbListNode* node, int v);


	// return fist node that has value x 
	DbListNode* find(int x);
};

//���������ע����ڽṹ���Լ�����ⲿ
std::ostream& operator<<(std::ostream&, const DbLinkList&);