#include<iostream>
#include<string>
using namespace std;

bool CheckPattern(string pat,string rest)//�ж�ʣ�µĲ����Ƿ������patѭ�����
{
	if (pat == rest)return true;//���һ��һ�����ݹ��յ�
	else if (pat == rest.substr(0, pat.length()))//�Ƚϵ�һ���Ƿ�һ��
		return CheckPattern(pat, rest.substr(pat.length()));//�ݹ�Ƚ�ʣ�µ�һ���Ƿ���pat���
	else return false;//��һ�β�һ��������false
}

string FindPattern(string str)
{
	for (int i = 1; i < str.length() / 2; i++)
	{
		if (str[i] == str[0] && str.length()%i == 0)//���һλһ�����Ҵ�ǰ�ַ����ܱ��ܳ�����
		{
			if (CheckPattern(str.substr(0, i), str.substr(i)))
				return str.substr(0, i);
		}
	}
	return str;
}

int main()
{
	string a;
	cin >> a;
	cout << FindPattern(a);

	system("pause");
	return 0;
}