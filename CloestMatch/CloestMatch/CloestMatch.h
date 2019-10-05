#pragma once
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
template <typename T>
class CloestMatch {
public:
	using Value_Type = T;
	CloestMatch() : data_group1(0),dg1_length(0), data_group2(0), dg2_length(0)  {}
	CloestMatch(Value_Type dg1[] , int dg1l, Value_Type dg2[] , int dg2l) : 
		data_group1(dg1), dg1_length(dg1l), data_group2(dg2), dg2_length(dg2l) {}
	~CloestMatch() {
	}
	//void Match(Value_Type targetValue);
	void Match(Value_Type targetValue, vector<std::pair<T, T>> & tmp);
private:
	Value_Type * data_group1;
	int dg1_length;
	Value_Type * data_group2;
	int dg2_length;
};

//
//��������
//
template <typename T>
void insertSort(T dg[], int length)
{
	for (int i = 1; i < length; i++)
	{
		T tmp = dg[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (tmp >= dg[j])
				break;
			dg[j + 1] = dg[j];
		}
		dg[j + 1] = tmp;
	}
}

//
//����
//
template <typename T>
int divide(T a[], int b, int e)
{
	auto pivot = a[e];
	auto i = b - 1;
	for (int j = b; j < e; j++)
	{
		if (a[j] < pivot)
		{
			i++;
			std::swap(a[i], a[j]);
		}
	}
	i++;
	std::swap(a[i], a[e]);
	return i;
}

//
//������dg[begin,end]��������
//
template <typename T>
void quickSort(T dg[], int begin, int end) 
{
	if (begin < end) 
	{
		auto p = divide<T>(dg,begin, end);
		quickSort(dg,begin, p-1);
		quickSort(dg,p+1, end);
	}
}

template <typename T>
void quickSort(T dg[], int length)
{
	quickSort<T>(dg,0,length-1);
}

//
//�鲢����
//
template <typename T>
void Merge(T a[], int b, int m, int e , int temp[])
{
	int i = b;
	int j = m;
	int t = b;
	while (i < m && j < e) {
		if (a[i] <= a[j]) {
			temp[t++] = a[i++];
		}
		else {
			temp[t++] = a[j++];
		}
	}

	while (i < m) 
	{
		temp[t++] = a[i++];
	}

	while (j < e)
	{
		temp[t++] = a[j++];
	}
	
	i = b ;
	while (i < e) {
		a[i] = temp[i];
		i++;
	}
}

template <typename T>
void MergeSort(T dg[], int begin, int end , T temp[])
{
	if (end - begin <= 1) return;
	int middle = (end + begin) / 2;
	MergeSort(dg, begin, middle , temp);
	MergeSort(dg, middle, end , temp);
	Merge<T>(dg, begin , middle, end, temp);
}

template <typename T>
void MergeSort(T dg[], int length)
{
	T * temp = new T[length];
	MergeSort<T>(dg, 0, length , temp);
	delete [] temp;
}

//
//ƥ���㷨
//
template <typename T>
void CloestMatch<T>::Match(T targetValue, vector<std::pair<T, T>> & tmp)
{

	//sort ����
	MergeSort<T>(data_group1, dg1_length);
	MergeSort<T>(data_group2, dg2_length);

	//���ֲ��ҷ�
	int dg2_start = 0, dg2_end = dg2_length-1;
	int dg2_mid = 0;
	T lastSum = data_group1[0] + data_group2[0];
	for (int i = 0; i < dg1_length; i++)
	{
		auto d1 = data_group1[i];
		while (dg2_start <= dg2_end)
		{
			dg2_mid = (dg2_start + dg2_end) / 2;
			auto d2 = data_group2[dg2_mid];
			auto sum = d1 + d2;
			if (sum > targetValue)
			{
				if (dg2_mid == 0) return ;
				dg2_end = dg2_mid-1;
				continue;
			}
			else
			{
				if (sum >= lastSum)
				{
					if (sum > lastSum) tmp.clear();
					lastSum = sum;
					tmp.push_back(std::pair<T, T>(d1, d2));
					int index = dg2_mid - 1;
					while (index >= dg2_start)
					{
						auto d2 = data_group2[index--];
						auto sum = d1 + d2;
						if (sum < lastSum) break;
						tmp.push_back(std::pair<T, T>(d1, d2));
					}
				}
				dg2_start = dg2_mid+1;
			}
		}
		dg2_start = 0;
	}

}

//template <typename T>
//void CloestMatch<T>::Match(T targetValue , vector<std::pair<T, T>> & tmp)
//{
//
//	//sort ����
//	quickSort<T>(data_group1, dg1_length);
//	quickSort<T>(data_group2, dg2_length);
//
//	//���ֲ��ҷ�
//	int dg1_start = 0, dg1_end = dg1_length ;
//	int dg2_start = 0, dg2_end = dg2_length ;
//	int dg2_mid = 0;
//	T lastSum = data_group1[0] + data_group2[0];
//	for (int i = dg1_start; i < dg1_end; i++) 
//	{
//		auto d1 = data_group1[i];
//		while (dg2_start < dg2_end )
//		{
//			dg2_mid = (dg2_start + dg2_end) / 2;
//			auto d2 = data_group2[dg2_mid];
//			auto sum = d1 + d2;
//			if (sum > targetValue)
//			{
//				if (dg2_mid >= dg2_end - 1) break;
//				dg2_end = dg2_mid;
//				continue;
//			}else
//			{ 
//				if (sum >= lastSum)
//				{
//					//sum > targetValue
//					if (sum > lastSum) tmp.clear();
//					lastSum = sum;
//					tmp.push_back(std::pair<T, T>(d1, d2));
//					int index = dg2_mid - 1;
//					while (index >= dg2_start)
//					{
//						auto d2 = data_group2[index--];
//						auto sum = d1 + d2;
//						if (sum < lastSum) break;
//						tmp.push_back(std::pair<T, T>(d1, d2));
//					}
//				}
//				dg2_start = dg2_mid;
//			}
//
//			if (dg2_start >= dg2_end - 1) dg2_start++;
//		}
//		dg2_start = 0;
//	}
//
//}

//template <typename T>
//void CloestMatch<T>::Match(T targetValue) {
//	vector<std::pair<T, T>> tmp = vector<std::pair<T, T>>();
//	//sort ����
//	insertSort<T>(data_group1 , dg1_length);
//	insertSort<T>(data_group2 , dg2_length);
//	
//	//���ֲ��ҷ�
//	int dg1_start = 0, dg1_end = dg1_length;
//	int dg2_start = 0, dg2_end = dg2_length;
//
//	bool dg1_flag = dg1_start < dg1_end;//���ֽ�����־
//	bool dg2_flag = dg2_start < dg2_end;//���ֽ�����־
//	bool existPerfectMatch = false;
//	int dg1_mid = 0;
//	int dg2_mid = 0;
//
//	int dg1_matchID = 0;
//	int dg2_matchID = 0;
//	T lastSum  = data_group1[0] + data_group2[0];//��һ��С��Ŀ���sum
//
//	while (dg1_flag || dg2_flag) 
//	{
//		dg1_mid = (dg1_start + dg1_end) / 2;
//		dg2_mid = (dg2_start + dg2_end) / 2;
//		if (dg1_mid == dg1_start && dg2_mid == dg2_start) break;	//�Ѿ������յ�
//		T data1 = data_group1[dg1_mid];
//		T data2 = data_group2[dg2_mid];
//		T sum = data1 + data2;
//		if (sum > targetValue)
//		{	
//			//����Ŀ��ֵ��������Ҫ��
//			dg1_end = dg1_mid;
//			dg2_end = dg2_mid;
//		}else if (sum < targetValue )
//		{
//
//			//С��Ŀ��ֵ������ΪĿ��⡣
//			if (tmp.size() > 0)//�޳�����������бȸ�ֵС�Ľ��,Ȼ�󽫸���ֵ��д��
//			{
//				if (sum > lastSum)	//˵��֮ǰ�Ĳ�����
//				{
//					lastSum = sum;
//					tmp.clear();
//				}
//			}
//			tmp.push_back(std::pair<T, T>(data1,data2));
//			dg1_start = dg1_mid;
//			dg2_start = dg2_mid;
//			
//		}else
//		{
//			//�������Ŀ��ֵ��
//			if(!existPerfectMatch)
//				tmp.clear();
//			tmp.push_back(std::pair<T, T>(data1, data2));
//			existPerfectMatch = true;
//			dg1_matchID = dg1_mid;
//			dg2_matchID = dg2_mid;
//			break;
//		}
//		dg1_flag = dg1_start < dg1_end;
//		dg2_flag = dg2_start < dg2_end;
//	}
//
//	bool existMatch = false;
//	if (!existPerfectMatch)
//	{
//		//��δ���ҵ�����ƥ��
//		if (tmp.size() == 0)
//		{
//			//ͨ�����ַ�δ���ҵ�Ŀ�ꡣ�����н��������Ŀ��ֵ��
//		}
//		else
//		{
//			//���ַ����ڽ��,���ý��������ѡ�
//			//pass 1
//			//dg1���ң�dg2���ҡ�
//			for (int i = 0; dg1_mid - i >= 0; i++) {
//				if (existMatch) break;
//				for (int j = 1; dg2_mid + i < dg2_length; j++)
//				{
//					if (existMatch) break;
//					auto v1 = data_group1[dg1_mid - i];
//					auto v2 = data_group2[dg2_mid + j];
//					auto sum = v1 + v2;
//					if (sum > targetValue || sum < lastSum) break;
//					if (sum > lastSum) {
//						tmp.clear();
//					}
//					lastSum = sum;
//					tmp.push_back(std::pair<T, T>(v1, v2));
//					if (sum == targetValue)
//					{
//						dg1_matchID = dg1_mid - i;
//						dg2_matchID = dg2_mid + j;
//						existMatch = true;
//					}
//				}
//			}
//			//pass 2
//			//dg2���ң�dg1����
//			for (int j = 0; dg2_mid - j >= 0; j++) {
//				if (existMatch) break;
//				for (int i = 1; dg1_mid + i < dg1_length; i++)
//				{
//					if (existMatch) break;
//					auto v1 = data_group1[dg1_mid - i];
//					auto v2 = data_group2[dg2_mid + j];
//					auto sum = v1 + v2;
//					if (sum > targetValue || sum < lastSum) break;
//					if (sum > lastSum) {
//						tmp.clear();
//					}
//					lastSum = sum;
//					tmp.push_back(std::pair<T, T>(v1, v2));
//					if (sum == targetValue)
//					{
//						dg1_matchID = dg1_mid - i;
//						dg2_matchID = dg2_mid + j;
//						existMatch = true;
//					}
//				}
//			}
//
//		}
//
//	}
//	if (existPerfectMatch || existMatch)
//	{
//		//�����ҳ���ý����ͬ��������
//		//dg1���ң�dg2����
//		for (int i = 0; dg1_matchID - i >= 0 ; i++)
//			for (int j = 1; dg2_matchID + i < dg2_length; j++)
//			{
//
//				auto v1 = data_group1[dg1_matchID - i];
//				auto v2 = data_group2[dg2_matchID + j];
//				auto sum = v1 + v2;
//				if (sum > targetValue) break;
//				if (sum < targetValue) continue;
//				tmp.push_back(std::pair<T, T>(v1, v2));
//				break;
//			}
//		//dg2���ң�dg1����
//		for (int j = 0; dg2_matchID - j >= 0 ; j++)
//			for (int i = 1; dg1_matchID + i < dg1_length; i++)
//			{
//
//				auto v1 = data_group1[dg1_matchID + i];
//				auto v2 = data_group2[dg2_matchID - j];
//				auto sum = v1 + v2;
//				if (sum > targetValue) break;
//				if (sum < targetValue) continue;
//				tmp.push_back(std::pair<T, T>(v1, v2));
//				break;
//			}
//	}
//	
//}

