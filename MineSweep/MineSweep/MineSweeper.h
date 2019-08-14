#pragma once
#include <vector>
using namespace std;
enum class Mode {
	EASY,
	NORMAL,
	HARD,
	CRAZY
};
class MineSweeper {

public:
	MineSweeper(int row, int col);
	MineSweeper(int row, int col , Mode mode);
	MineSweeper(int row, int col , int bombs);
	~MineSweeper(void);
	/*
		���ȵ��ף���ը
		���ȵ�û���׵ĵط����Ը�λ��Ϊԭ�㣬���з�ɢʽչ����һȦһȦ������ɢ����ֱ����ɢ��Ȧ����ֹͣ
	*/
	bool play(int x , int y);//��λ��
	
	void print();//��ӡ��ͼ
	void show();	//��ʾϸ��
	bool checkOver();	//��⺯��
	void funcTest();	//���Ժ���
private :
	const int SAFE_CELL = 0; //��ʾ��ȫ
	const int MINE_CELL = 9; //��ʾ����
	int mines{0};			//ը������
	int safeCells{0};			//ը������
	int foundedSafeCounts{0};	//���ҵ��İ�ȫ������
	vector<vector<int>> m_grid;
	vector<vector<bool>> m_status;
	int rows{0};
	int cols{0};
	bool gameover{false};
	void createMap(int row, int col);
	/*
		���ƹ��죺
		1.ͨ��������������ֲ���
			�ø�����ʾ��

	*/
	void shuffle();
	void envValConfig();

	void unfold(int x , int y);
	inline int round(vector<vector<int>> & m_grid, int i, int j);
};