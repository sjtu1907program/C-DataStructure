#include<iostream>;
#include "LinkList.h"
using namespace std;

int main()
{
	int v[] = { 1, 2, 3, 4, 3 };
	LinkList list(v, 5);
	cout << "ԭ����Ϊ��" << list << endl;
	list.erase(3);
	cout << "��ɾ��3��������Ϊ��" << list.size() << endl;
	cout << "��ɾ��3������Ϊ��" << list << endl;
	list.insert(nullptr, 10);
	cout << "������10��" << endl;
	auto node = list.find(2);
	list.insert(node, 8);
	cout << "������8������Ϊ��" << list << endl;
}