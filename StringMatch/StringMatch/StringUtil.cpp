#include "StringUtil.h"
#include <iostream>
/*
	//����Ѱ�����һ���ַ�һ�����ַ��������ڣ����ҴӴ˴���ʼ�����ַ����е���С�����ַ�����
	//Ȼ���������ַ���֮ǰ��������жԱȣ�����ͬ��Ϊ��С�����ַ��������򣬷����䱾��
*/
/*
	���룺�ַ���
	���أ���С���ȵ������ַ���
*/
std::string StringUtil::GetCyclicSubStr(std::string str)
{
	int length = str.length();
	if (length > 1) {
		std::string result;
		int i = 1;
		while (i <= (length / 2)) {
			if (str[0] == str[i])
			{
				result = str.substr(0, i);//[0,i-1]   substr(i) --> [i, end]
				std::string cyclicStr = GetCyclicSubStr(str.substr(i));//��ȡ�Ӵ�λ�ÿ�ʼ�����ַ����������ַ���
				if (result == cyclicStr)
					return result;
			}
			i++;
		}
	}
	return str;
}

std::string StringUtil::GetCyclicSubStr(char * str) {
	return GetCyclicSubStr(std::string(str));
}
