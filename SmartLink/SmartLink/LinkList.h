#pragma once
#include<iostream>
using namespace std;
class ListNode {
	int val;
	ListNode* next;

public:
	int getValue() {
		return val;
	}
	void setValue(int n) {
		val = n;
	}
	ListNode* getNext() {
		return next;
	}
	void setNext(ListNode * node) {
		next = node;
	}
	ListNode(int x) : val(x), next(nullptr) {}
};
class LinkList
{
	ListNode* m_head{ nullptr };
public:
	LinkList(LinkList&& other);
	LinkList& operator=(LinkList&& other);
	ListNode* getHead()const {//��� ���ñ��� ��const
		return m_head;
	}
	void setHead(ListNode * node) {
		m_head = node;
	}

	LinkList(int v[], int size);
	LinkList(std::initializer_list<int> l);
	LinkList(const LinkList& other);
	LinkList& operator = (const LinkList& other);

	~LinkList();

	int size();
	void erase(int x)
	{
		ListNode * temp2{ nullptr };
		for (ListNode*temp{ m_head }; temp->getNext() != nullptr; ) {
			if (temp->getNext()->getValue() == x) {
				temp2 = temp->getNext();
				temp->setNext(temp2->getNext());
				delete temp2;
			}
			else {
				temp = temp->getNext();
			}
		}

	}

	void insert(ListNode* node, int v)
	{
		ListNode*insertOne{ m_head };
		if (node == nullptr) {//�����β
			for (; insertOne->getNext() != nullptr; insertOne = insertOne->getNext()) {// ѭ����ĩβ
			}
			insertOne->setNext(new ListNode(v));
		}
		else {//ֻ���Ǵ�����ǺϷ�node 
			for (; insertOne->getNext() != node; insertOne = insertOne->getNext()) {//ѭ������һ��Ϊnode
			}
			insertOne->setNext(new ListNode(v));
			insertOne->getNext()->setNext(node);
		}

	}

	// return fist node that has value x 
	ListNode* find(int x) {
		ListNode*target{ m_head->getNext() };
		for (; target->getValue() != x; target = target->getNext()) {//ѭ������һ��Ϊnode
		}
		return target;

	};


};

std::ostream& operator<< (std::ostream& os, LinkList& lst) {
	ListNode * temp = lst.getHead()->getNext();
	for (; temp->getNext() != nullptr; temp = temp->getNext()) {//���һ��Ԫ��Ϊֹ

		os << temp->getValue() << "->";
	}
	os << temp->getValue() << std::endl;
	return os;
};


