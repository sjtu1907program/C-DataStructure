#pragma once

#include <vector>
//homework
using namespace std;
class SweepingBombs {
public:
	SweepingBombs(int row, int col);
	void play(int x, int y); //�����㷨  ��������㷨
private:
	vector<vector<int> >m_grid;
	vector<vector<bool> >m_status;//�Ƿ񱻴�
};
