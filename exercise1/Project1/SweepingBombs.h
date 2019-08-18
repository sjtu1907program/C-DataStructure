#pragma once
#include<iostream>
#include<vector>
#include <random>
#include <ctime>
using namespace std;


class SweepingBombs {

private:
	void MainLoop();

	//�����Ϊ�������
	void Click(int c,int r);

	//�����Ϊ���Ҽ���
	void Mark(int c, int r);

	void Reveal(int c, int r);


	//��ͼ��ʼ��
	void SetMines(int avoid_c, int avoid_r);

	void MineNeighbor(int c, int r);

	void PrintMap();

	void PrintMine();
	
	void PrintTip();

	void PrintHelp();


public:


	SweepingBombs(int c, int r, int m);
	
	//������Ϸ�ĺ���
	void StartGame();


private:
	const int col;
	const int row;
	const int minesCnt;

	bool initMineFlag = false;	
	int revealCount = 0;		//����ʤ���ж�
	int markCount = 0;

	//�����û�����
	char command;
	int _c, _r;

	vector<vector<char>> m_userMap;
	vector<vector<int>> m_mineMap;//-1Ϊ�ף���Ȼ��Ϊ��ΧһȦ����
};







