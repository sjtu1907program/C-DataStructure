#include<iostream>
using namespace std;

int ReverseInt(int x);
//�Ҿ�����longlong�����е㱩�����׵ĸо�
//���������int���ж��Ƿ񳬹�INT_MAX�Ļ�Ҫд�Ĳ�������е�̫�����ˣ��ҷ���
int main()
{
	cout << ReverseInt(2)<<endl;
	cout << ReverseInt(1234)<<endl;
	cout << ReverseInt(1563847412) << endl;//һ������С��INT_MAX��������΢����INT_MAX����
	cout << ReverseInt(1463847412) << endl;//һ������С��INT_MAX��������΢С��INT_MAX����
	system("PAUSE");
	return 0;
}

int ReverseInt(int x)
{
	long long ll_x = (long long)x;
	long long ll_revx = 0;
	while(ll_x!=0)
	{
		ll_revx = ll_revx * 10 + ll_x % 10;
		ll_x /= 10;
	}
	if (ll_revx > INT_MAX) {
		cout << "error!";
		return 0;
	}
	else
		return (int)ll_revx;


}