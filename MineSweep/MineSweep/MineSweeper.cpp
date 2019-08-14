#include "MineSweeper.h"

#include <iostream>
#include <math.h>
#include <time.h>

void MineSweeper::createMap(int _rows, int _cols) {
	if (_rows <= 3 || _cols <= 3)
		throw "rows or cols is too small";
	m_grid = vector<vector<int>>(_rows,vector<int>(_cols, SAFE_CELL));
	m_status = vector<vector<bool>>(_rows,vector<bool>(_cols,false));
}

MineSweeper::MineSweeper(int _rows, int _cols) {
	new (this)MineSweeper(_rows, _cols, Mode::NORMAL);
}

MineSweeper::MineSweeper(int _rows, int _cols, Mode mode) {
	//�׵��������ͼ�й�
	switch (mode) {
	case Mode::EASY:
		mines = (_rows * _cols) / 16;
		break;
	case Mode::NORMAL:
		mines = (_rows * _cols) / 8;
		break;
	case Mode::HARD:
		mines = (_rows * _cols) / 6;
		break;
	case Mode::CRAZY:
		mines = (_rows * _cols) / 4;
		break;
	default:
		mines = _rows + _cols;
		break;
	}
	new (this)MineSweeper(_rows,_cols,mines);

}
MineSweeper::MineSweeper(int _rows, int _cols, int _mines) {
	rows = _rows;
	cols = _cols;
	mines = _mines;
	gameover = false;
	safeCells = rows * cols - mines;
	//���ɳ�ʼ��ͼ
	createMap(rows, cols);
	foundedSafeCounts = 0;
	shuffle(); //ϴ�ƣ��������λ�õĵ���
	envValConfig();	//���ݵ�����������cell������
}


MineSweeper::~MineSweeper(void) {

}

bool MineSweeper::play(int x, int y) {
	if (x <0  || x > cols) return false;
	if (y < 0 || y > rows) return false;
	bool result = true;
	x--, y--;
	if (m_status[x][y]) {
		cout << "this cell has been open!" << endl;
		return true;
	}
	m_status[x][y] = true;
	int val = m_grid[x][y];
	if (val == MINE_CELL) {
		gameover = true;
		cout << "You failed!" << endl;
	}
	else {
		//�����ף�����¼�����
		foundedSafeCounts++;
		if (val == SAFE_CELL) {//�������ף����ܱ�û���ף�������ܱ߽���չ��
			unfold(x, y);
		}
	}
	print();
	return true;
}

void MineSweeper::show() {
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) {
			int tmp = m_grid[i][j];
			if (tmp == MINE_CELL) {
				cout << "!  ";
			}
			else {
				cout << tmp << "  ";
			}
		}
		cout << endl;
	}
}
//��ӡ��ͼ
void MineSweeper::print() {
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) {
			if (m_status[i][j]) {
				int tmp = m_grid[i][j];
				if (tmp == MINE_CELL) {
					cout << "!  ";
				}
				else {
					cout << tmp << "  ";
				}
			}else{
				cout << "@  ";
			}
		}
		cout << endl;
	}
}

bool MineSweeper::checkOver() {
	if (foundedSafeCounts == safeCells) {
		gameover = true;
		cout << "Win!!" << endl;
	}
	return gameover;
}
void MineSweeper::funcTest() {
	
}


//ϴ��
void MineSweeper::shuffle() {
	int counts = mines;
	srand(time(0) + rows * cols - counts);
	while (counts) {
		int i = rand() % rows ;
		int j = rand() % cols ;
		if (m_grid[i][j] == SAFE_CELL) {
			m_grid[i][j] = MINE_CELL;
			counts--;
		}
	}
}

void MineSweeper::envValConfig() {
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			if (m_grid[i][j]== SAFE_CELL)
				m_grid[i][j] = round(m_grid,i,j);
		}
}

inline int MineSweeper::round(vector<vector<int>> & m_grid, int i, int j) {
	int rows = m_grid.size(), cols = m_grid[0].size();//�к���
	int result{0};
	for (int x = -1; x <= 1; x++)
		for (int y = -1; y <= 1; y++) {
			int tmpx = i + x, tmpy = j + y;
			if (tmpx >= 0 && tmpy >= 0 && tmpx < rows && tmpy < cols)
				if (m_grid[tmpx][tmpy] == 9)
					result++;
		}
	
	return result;
}

void MineSweeper::unfold(int i, int j) {
	int initXoffset{ -1 }, initYoffset{-1};
	int endXoffset{ 1 }, endYoffset{ 1 };
	if (j == 0) initYoffset = 0;
	else if (j == cols - 1) endYoffset = 0;
	if (i == 0) initXoffset = 0;
	else if (i == rows - 1) endXoffset = 0;
	
	for(int x = initXoffset ; x <= endXoffset ;x++)
		for (int y = initYoffset; y <= endYoffset; y++) {
			if (x == 0 && y == 0) continue;	//��������λ��
			int tmpx = i + x, tmpy = j + y;
			if (!m_status[tmpx][tmpy] )
			{
				foundedSafeCounts++;
				m_status[tmpx][tmpy] = true;
				if(m_grid[tmpx][tmpy] == SAFE_CELL)
					unfold(tmpx, tmpy);
			}
			
			//cout << "��ǰ�ѷ��ֵ�safe cells��" << foundedSafeCounts << endl;

		}
		
}