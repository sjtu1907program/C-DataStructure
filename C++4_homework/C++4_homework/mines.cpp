#include"mines.h"
#include<ctime>

minesPlace::minesPlace(int n,int m)
{
	num = n;
	mines_num = m;
	array.resize(num, vector<int>(num, 0));
	_array.resize(num, vector<bool>(num, false));
	buryMines();
}

void minesPlace::buryMines()
{
	srand((int)time(NULL));
	int x, y;
	//����
	for (int i = 0; i < mines_num; i++)
	{
		while (true)
		{
			x = rand() % num;
			y = rand() % num;
			if (array[x][y] == -1)
			{
				continue;
			}
			break;
		}
		array[x][y] = -1;
	}
	//�׵ĵ���Χ+1
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (array[i][j] == -1)
			{
				if (i > 0 && j > 0 && array[i - 1][j - 1] != -1)
					array[i - 1][j - 1] += 1;
				if (i > 0 && array[i - 1][j] != -1)
					array[i - 1][j] += 1;
				if (i > 0 && j < num-1 && array[i - 1][j + 1] != -1)
					array[i - 1][j + 1] += 1;
				if (j < num - 1 && array[i][j + 1] != -1)
					array[i][j + 1] += 1;
				if (i < num - 1 && j < num - 1 && array[i + 1][j + 1] != -1)
					array[i + 1][j + 1] += 1;
				if (i < num - 1 && array[i + 1][j] != -1)
					array[i + 1][j] += 1;
				if (i < num - 1 && j > 0 && array[i + 1][j - 1] != -1)
					array[i + 1][j - 1] += 1;
				if (j > 0 && array[i][j - 1] != -1)
					array[i][j - 1] += 1;
			}
		}
	}
}

//0λ����ɢЧ��
void minesPlace::zero(int p, int q)
{
	int x = p;
	int y = q;
	if (array[x][y] == 0)
	{
		if (x > 0 && y > 0 && _array[x - 1][y - 1] == false)
		{
			_array[x - 1][y - 1] = true;
			zero(x - 1, y - 1);
		}
		if (x > 0 && _array[x - 1][y] == false)
		{
			_array[x - 1][y] = true;
			zero(x - 1, y);
		}
		if (x > 0 && y < num - 1 && _array[x - 1][y + 1] == false)
		{
			_array[x - 1][y + 1] = true;
			zero(x - 1, y + 1);
		}
		if (y < num - 1 && _array[x][y + 1] == false)
		{
			_array[x][y + 1] = true;
			zero(x, y + 1);
		}
		if (x < num - 1 && y < num - 1 && _array[x + 1][y + 1] == false)
		{
			_array[x + 1][y + 1] = true;
			zero(x + 1, y + 1);
		}
		if (x < num - 1 && _array[x + 1][y] == false)
		{
			_array[x + 1][y] = true;
			zero(x + 1, y);
		}
		if (x < num - 1 && y > 0 && _array[x + 1][y - 1] == false)
		{
			_array[x + 1][y - 1] = true;
			zero(x + 1, y - 1);
		}
		if (y > 0 && _array[x][y - 1] == false)
		{
			_array[x][y - 1] = true;
			zero(x, y - 1);
		}
	}
}

bool minesPlace::judge()
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (_array[i][j] == false && array[i][j] != -1)
			{
				return false;
			}
		}
	}
	return true;
}

void minesPlace::showAll()
{
	cout << endl << "\t��������" << mines_num << endl << endl;
	cout << "   ";
	for (int i = 0; i < num; i++)
	{
		cout << "(" << i << ") ";
	}
	cout << endl;
	//����ӡ״̬��
	for (int i = 0; i < num; i++)
	{
		cout << "(" << i << ") ";
		for (int j = 0; j < num; j++)
		{
			if (_array[i][j])
			{
				cout << array[i][j] << "   ";
			}
			else
			{
				cout << "*   ";
			}
		}
		cout << endl << endl;
	}

	//��ӡ״̬��
	//for (int i = 0; i < num; i++)
	//{
	//	cout << "(" << i << ") ";
	//	for (int j = 0; j < num; j++)
	//	{
	//		cout << array[i][j] << "   ";
	//	}
	//	cout << "\t";
	//	for (int j = 0; j < num; j++)
	//	{
	//		cout << _array[i][j] << "   ";
	//	}
	//	cout << endl << endl;
	//}
}

void minesPlace::input()
{
	int x, y;
	bool sf = false;
	while (true)
	{
		showAll();
		cout << "������ɨ��λ��(�Կո���)��";
		cin >> x >> y;
		if (x >= num || y >= num || x < 0 || y < 0)
		{
			system("cls");
			cout << endl << "*** ������Ϸ�λ��! ****" << endl << endl;
			continue;
		}
		_array[x][y] = true;
		if (array[x][y] == 0)
		{
			zero(x, y);
		}
		system("cls");
		if (array[x][y] == -1)
		{
			showAll();
			cout << "*** ��Ϸ����! ***" << endl << endl;
			break;
		}
		sf = judge();
		if (sf)
		{
			showAll();
			cout << "*** ��Ӯ��! ***" << endl << endl;
			break;
		}
	}
}