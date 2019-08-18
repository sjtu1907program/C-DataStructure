#include<iostream>
#include<vector>
#include <random>
#include <ctime>
#include"SweepingBombs.h"
using namespace std;

void SweepingBombs::MainLoop()
{
	cin >> command;
	if (command == 'h' || command == 'H')
	{
		PrintHelp(); return;
	}
	else {
		cin >> _c >> _r;

		if (_c<1 || _c>col || _r<1 || _r>row) {
			cout << "wrong index\n";
			PrintTip();
			return;
		}
		switch (command)
		{
		case 'c':case 'C':
			Click(_c - 1, _r - 1);
			break;
		case 'm':case 'M':
			Mark(_c - 1, _r - 1);
			break;
		default:
			cout << "wrong command\n";
			PrintTip();
			return;
		}

	}
	PrintMap();

	if (revealCount == col * row - minesCnt)
	{
		cout << "-------YOU WIN!!!-------\n";
		system("pause");
	}
	PrintTip();
}

//�����Ϊ�������
void SweepingBombs::Click(int c, int r)
{
	if (m_userMap[c][r] != '+')
	{
		cout << "��Ч����\n";
		return;
	}//����ǻ��ѱ��򿪵��������Ч��
	if (!initMineFlag)//�ڵ�һ�ε���������׵�ͼ
	{
		SetMines(c, r);
		initMineFlag = true;
	}

	if (m_mineMap[c][r] == -1)//�ȵ���
	{
		cout << "------- G A M E   O V E R -------\n";
		PrintMine();
		system("pause");
	}
	else
	{
		Reveal(c, r);
	}
}

//�����Ϊ���Ҽ���
void SweepingBombs::Mark(int c, int r)
{
	if (m_userMap[c][r] == '+') {
		m_userMap[c][r] = 'X';
		markCount++;
	}
	else if (m_userMap[c][r] == 'X') {
		m_userMap[c][r] = '+';
		markCount--;
	}
}

void SweepingBombs::Reveal(int c, int r)
{
	if (c < 0 || c >= col || r < 0 || r >= row)return;//�ݹ�ʱ�����߽�
	if (m_userMap[c][r] != '+')return;//�ѱ���

	m_userMap[c][r] = m_mineMap[c][r] + '0';
	revealCount++;

	if (m_mineMap[c][r] == 0)//��Ϊ0����������ΧһȦ
	{
		Reveal(c - 1, r - 1);	Reveal(c - 1, r);	Reveal(c - 1, r + 1);
		Reveal(c, r - 1);	Reveal(c, r + 1);
		Reveal(c + 1, r - 1);	Reveal(c + 1, r);	Reveal(c + 1, r + 1);
	}
}


//��ͼ��ʼ��
void SweepingBombs::SetMines(int avoid_c, int avoid_r)
{
	default_random_engine e;
	e.seed(unsigned(time(0)));
	uniform_int_distribution<unsigned> range_c(0, col - 1);
	uniform_int_distribution<unsigned> range_r(0, row - 1);

	int c, r;
	bool flag;//flagΪtrue������roll��λ�ÿ���

	for (int i = 0; i < minesCnt; i++)//����99����
	{
		flag = false;
		while (!flag) {
			c = range_c(e);
			r = range_r(e);

			//���˴������Ƿ����
			flag = true;
			if (m_mineMap[c][r] == -1)flag = false;//Ҫ�ر��Ѿ����µ�
			if (c == avoid_c && r == avoid_r)flag = false;//��Ҫ�رܵ�һ�ε�������˺����Ĳ�����
		}
		m_mineMap[c][r] = -1;

		//���ú���֮��Ҫ����ΧһȦ�������ú�
		MineNeighbor(c - 1, r - 1); MineNeighbor(c - 1, r); MineNeighbor(c - 1, r + 1);
		MineNeighbor(c, r - 1); MineNeighbor(c, r + 1);
		MineNeighbor(c + 1, r - 1); MineNeighbor(c + 1, r); MineNeighbor(c + 1, r + 1);
	}

	//TODO:�رܱ���ȫΧ�����ף���ܾŹ���Ķ����׵������

	//PrintMine();
}

void SweepingBombs::MineNeighbor(int c, int r)
{
	if (c < 0 || c >= col || r < 0 || r >= row)return;//�ݹ�ʱ�����߽�
	if (m_mineMap[c][r] != -1)//��������׵Ļ�������++
		m_mineMap[c][r]++;
}

void SweepingBombs::PrintMap()
{
	for (int j = 0; j <= row; j++)
	{
		if (j % 5 == 0)
			if (j % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";
	}
	cout << endl;
	for (int i = 0; i < col; i++)
	{
		if ((i + 1) % 5 == 0)
			if ((i + 1) % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";

		for (int j = 0; j < row; j++)
			cout << m_userMap[i][j] << ' ';
		cout << endl;
	}
}

void SweepingBombs::PrintMine()
{
	cout << "��ͼ:" << endl << "--------------------------" << endl;
	for (int j = 0; j <= row; j++)
	{
		if (j % 5 == 0)
			if (j % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";
	}
	cout << endl;
	for (int i = 0; i < col; i++)
	{
		if ((i + 1) % 5 == 0)
			if ((i + 1) % 10 == 0)cout << "0 ";
			else cout << "5 ";
		else cout << "  ";

		for (int j = 0; j < row; j++)
			cout << m_mineMap[i][j] << ' ';
		cout << endl;
	}
	cout << "--------------------------" << endl;
}

void SweepingBombs::PrintTip()
{
	cout << "���������һ����\n";
	cout << "[c _ _]--�㿪, [m _ _]--�����, [h]--ͳ�������" << endl;
}

void SweepingBombs::PrintHelp()
{
	cout << "�ѵ㿪" << revealCount << "��\n";
	cout << "���ձ�ǻ�ʣ" << minesCnt - markCount << "����\n";
	cout << "�һ�ûд����\n";
}



SweepingBombs::SweepingBombs(int c, int r, int m) :col(c), row(r), minesCnt(m)
	{
		vector<int> tmp1(row, 0);
		vector<char> tmp2(row, '+');
		for (int i = 0; i < col; i++)
		{
			m_mineMap.push_back(tmp1);
			m_userMap.push_back(tmp2);
		}

	}

	//������Ϸ�ĺ���
void SweepingBombs::StartGame()
{
	PrintMap();
	cout << "���������һ����\n";
	cout << "[c _ _]--�㿪, [m _ _]--�����, [h]--ͳ�������" << endl;
	while (true)
	{
		MainLoop();
	}
}