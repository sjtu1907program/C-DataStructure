#include "CloestMatch.h"
#include <iostream>
/*
	��ӽ�����ƥ�䡣
	(�����������飬ÿһ����ѡȡһ����ֵ�����غ�С�ڵ���Ŀ������ӽ�Ŀ��Ľ��)
	eg:
	���룺
			[2000,5000,1000,3000]
			[3000,4000,7000]
		Ŀ�꣺5000	---�����أ�[1000,4000] [2000,3000]
		Ŀ�꣺7000	---�����أ�[3000,4000]

	���裺
		1.����
			1 2 3 5
			3 4 7
		
*/
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))
void test();
int main() {
	test();
	system("pause");
}


void test() {
	int  data1[]{ 5,4,7,8,1,5,6,7 };	//����� 1 4 5 5 6 7 7 8
	int  data2[]{ 4,5,7,1,3,67 };       //����� 1 3 4 5 7 67
	
	CloestMatch<int> data_group(data1, LENGTH(data1), data2 , LENGTH(data2));
	std::vector<std::pair<int, int>> result = std::vector<std::pair<int, int>>();
	data_group.Match(9 ,result);
	for (int i = 0; i < result.size(); i++)
	{
		std::pair<int, int> p = result[i];
		cout << "[" << p.first << "," << p.second << "], ";
	}

	cout << endl;
}