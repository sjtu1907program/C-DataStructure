//���������飺
//{ 2000��5000��3000��1000 }��
//{ 3000�� 4000�� 7000 }
//����Ŀ��������5000���򷵻أ�
//{ 2000 ��3000 }��{ 1000��4000 }
////������ǡ���к͵������룬��ֻ�������к�ǡ�õ��ڵ����
//��7500�򷵻أ�
//{ 3000��4000 }
////�����������ӽ����
//��9000�򷵻أ�
//{ 1000�� 7000 }
//��2000��ɷ����쳣��
//
//P.S.  :����forѭ��֮��û��Ч�ʵ��㷨��������㷨���Ӷ�С�ڵ���O(nlogn)

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class TwoSum {
public :
	TwoSum(vector<int>& data1, vector<int>& data2, int sum)
	{
		 sort(data1.begin(), data1.end());   //O(N log N)
		 sort(data2.begin(), data2.end());
		 
		 if (data1[0] + data2[0] > sum)
		 {
			 cout << "Target is too small! "<<endl;
			 return;
		 }

		 for (int i{}; i < data1.size(); i++)
		 {
			 int target = sum - data1[i];
			 if (binary_search(data2.begin(),data2.end(), target))
			 {
				 cout << "{" << data1[i] << "," << target << "}" << endl;
				 count++;
				 continue;
			 }
		 }
		 
		 if (count == 0)
		 {
			 int min_difference{INT32_MAX};
			 int d1value{};
			 int d2value{};
			 for (int i{}; i < data1.size(); i++)
			 {
				 int target = abs(sum - data1[i] - data2[
					 ++lower_bound(data2.begin(), data2.end(), target)  - data2.begin()]);
				 if (target < min_difference)
				 {
					 min_difference = target;
					 d1value = data1[i];
					 d2value = data2[++lower_bound(data2.begin(), data2.end(), target)  - data2.begin()];
				 }
			 }
			 cout << "{" << d1value << "," << d2value << "}" << endl;
		 }
	}
private:
	int count{};
};