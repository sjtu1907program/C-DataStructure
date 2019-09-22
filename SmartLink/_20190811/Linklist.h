#pragma once
#include<iostream>
using namespace std;
using std::shared_ptr;
struct ListNode {
	int val;
	shared_ptr<ListNode> next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class LinkList
{
	shared_ptr<ListNode> m_head{ nullptr };
public:
	LinkList(LinkList&& other);
	LinkList& operator=(LinkList&& other);
	shared_ptr<ListNode> getHead()const {//��� ���ñ��� ��const
		return m_head;
	}
	void setHead(shared_ptr<ListNode> node) {
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
		shared_ptr<ListNode>  temp2{ nullptr };
		for (shared_ptr<ListNode> temp{ m_head }; temp->next != nullptr; ) {
			if (temp->next->val == x) {
				temp2 = temp->next;
				temp->next=temp2->next;
				temp2.reset();
			}
			else {
				temp = temp->next;
			}
		}

	}

	void insert(shared_ptr<ListNode>  node, int v)
	{
		shared_ptr<ListNode> insertOne{ m_head };
		if (node == nullptr) {//�����β
			for (; insertOne->next != nullptr; insertOne = insertOne->next) {// ѭ����ĩβ
			}
			insertOne->next=make_shared<ListNode>(v);
		}
		else {//ֻ���Ǵ�����ǺϷ�node 
			for (; insertOne->next != node; insertOne = insertOne->next) {//ѭ������һ��Ϊnode
			}
			insertOne->next=make_shared<ListNode>(v);
			insertOne->next=node;
		}

	}

	// return fist node that has value x 
	shared_ptr<ListNode>  find(int x) {
		shared_ptr<ListNode> target{ m_head->next };
		for (; target->val != x; target = target->next) {//ѭ������һ��Ϊnode
		}
		return target;

	};


};
inline std::ostream& operator<< (std::ostream& os, LinkList& lst) {
	shared_ptr<ListNode>  temp = lst.getHead()->next;
	for (; temp->next != nullptr; temp = temp->next) {//���һ��Ԫ��Ϊֹ

		os << temp->val << "->";
	}
	os << temp->val << std::endl;
	return os;
};





