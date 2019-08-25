#include <iostream>
#include <string>
using namespace std;

string FindLoopString(string test);
bool FindLoopString(string test, int loopLength);

string FindLoopString(string test)
{
	string result{};
	int origLength = test.length();	//��ǰ�ַ�������
	int i = 1;
	while (i <= (origLength / 2))
	{
		if (test[0] == test[i])		//Ѱ�����һ����ͬ���ַ�
		{
			int loopLength = i;		//ѭ���ַ�������
			if (origLength%loopLength != 0)		//��������������ز���ȷ
			{
				break;
			}
			result = test.substr(0, i);
			if (FindLoopString(test, loopLength))
			{
				return result;
			}
		}
		i++;
	}
	return test;
}

bool FindLoopString(string test, int loopLength)	//�жϺ����ַ����Ƿ���ͬ
{
	if (test.length() == loopLength)
	{
		return true;
	}
	if (test.substr(0, loopLength) == test.substr(loopLength, loopLength))
	{
		if (!FindLoopString(test.substr(loopLength), loopLength))
			return false;
	}
	else
	{
		return false;
	}
}

int main()
{
	while (true)
	{
		string test{};
		cin >> test;
		string result = FindLoopString(test);
		cout << test << " --> " << result << endl;
	}
	return 0;
}