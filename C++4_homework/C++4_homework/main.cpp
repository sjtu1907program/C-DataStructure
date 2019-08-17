#include<iostream>
#include"mines.h"
using namespace std;

minesPlace createGame()
{
	cout << "*********************************" << endl;
	cout << "         ��ѡ����Ϸ�Ѷ�          " << endl;
	cout << "*********************************" << endl;
	cout << "*    1.����6x6      ������4     *" << endl;
	cout << "*    2.����9x9      ������12    *" << endl;
	cout << "*    3.����13x13    ������30    *" << endl;
	cout << "*    4.�Զ��� (�߳�1-99)        *" << endl;
	cout << "*********************************" << endl;
	cout << endl << "��������ѡ�Ѷȣ�";
	int sel, n, m;
	cin >> sel;
	while (true)
	{
		if (sel < 1 || sel > 4)
		{
			cout << endl << "*** ��ѡ����ȷ����Ϸ�Ѷ�! ****" << endl << endl;
			cout << "��������ѡ�Ѷȣ�";
			cin >> sel;
		}
		else
		{
			break;
		}
	}
	switch (sel)
	{
	case 1:
		n = 6;
		m = 4;
		break;
	case 2:
		n = 9;
		m = 12;
		break;
	case 3:
		n = 13;
		m = 30;
		break;
	case 4:
		while (true)
		{
			cout << endl << "������߳���";
			cin >> n;
			if (n <= 0 || n >= 100)
			{
				cout << endl << "*** ��������ȷ�ı߳�(1-99)! ***" << endl;
				continue;
			}
			break;
		}
		while (true)
		{
			cout << endl << "��������׸�����";
			cin >> m;
			if (m <= 0 || m >= n*n)
			{
				cout << endl << "*** ��������ʵĵ��׸���! ***" << endl;
				continue;
			}
			break;
		}
		break;
	}
	system("cls");
	minesPlace a{ n, m };
	return a;
}

int main() 
{
	int i;
	while (true)
	{
		system("cls");
		minesPlace n = createGame();
		n.input();
		cout << "�Ƿ����¿�ʼ��Ϸ(1.��  2.��):";
		cin >> i;
		while (true)
		{
			if (i != 1 && i != 2)
			{
				cout << endl << "*** ��ѡ����ȷ��ѡ��! ****" << endl << endl;
				cout << "�Ƿ����¿�ʼ��Ϸ(1.��  2.��):";
				cin >> i;
			}
			else
			{
				break;
			}
		}
		if (i == 2)
		{
			break;
		}
	}
}