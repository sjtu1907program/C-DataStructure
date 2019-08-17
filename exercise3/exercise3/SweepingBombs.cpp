#include "SweepingBombs.h"
SweepingBombs::SweepingBombs(int row,int col,int bombs)//�����ʼ�� ���ò����׵ķ���
{
	gameStatus = true;
	m_grid.resize(row, vector<int>(col, 0));
	m_status.resize(row, vector<bool>(col, false));
	SetBombs(row, col, bombs);
	
}

void SweepingBombs::SetBombs(int row,int col,int bombs) {
	int tempNumber = RandomNumber();
	for (int i = 0; i < bombs; i++) {
		if (m_grid[tempNumber /col][tempNumber%col] != -1) {
			m_grid[tempNumber /col][tempNumber%col] =-1;//ը��Ϊ-1
			for (int j = tempNumber / col - 1; j != tempNumber / col+2; j++) {
				for (int k = tempNumber % col - 1; k != tempNumber % col + 2; k++) {
					if (j < 0 || j>=row || k<0 || k>=col|| m_grid[j][k] == -1) {//Խ����ߵ�ǰΪը��
						continue;
					}
					else {
						m_grid[j][k] += 1;
					}
				}
			}
		}
		else {
			i--;
			tempNumber = RandomNumber();
		}
	}
};
void SweepingBombs::Show_Status() {
	for (int i = 0; i < m_grid.size(); i++) {
		for (int j = 0; j < m_grid[i].size(); j++) {
			if (m_status[i][j]) {
				if (m_grid[i][j] == -1) {//�Ѿ����㿪��ը��
					cout << "* ";
				}
				else {
					cout << m_grid[i][j] << " ";//
				}
			}
			else {
				cout << "? ";
			}
		}
		cout << " " << endl;
	}
}
void SweepingBombs::ScanLineSeedFill(int x, int y) {
	int pRight, pLeft;//���ұ߽�
	stack<Point> stk;
	stk.push(Point{ x,y });
	while (!stk.empty()) {
		Point p = stk.top();
		stk.pop();
		pLeft = FindLeft(p.x, p.y);
		pRight = FindRight(p.x, p.y);
		if (p.x >= 1) {//�Ƿ�Ϊ�߽�
			SearchLineNewSeed(stk, pLeft, pRight, p.x - 1);
		}
		if (p.x < (m_grid.size()-1)) {//�Ƿ�Ϊ�߽�
			SearchLineNewSeed(stk, pLeft, pRight, p.x + 1);
		}
		
	}
};
int  SweepingBombs::FindLeft(int x, int y) {//������һ��==0 ���ص���0�ı߽� ���һ��0��λ�� ����Ҫ���Աߵ�1 status ���� ��ǰ���Ѿ�Ϊ��
	y--;
	while (y != -1 && m_grid[x][y] == 0&&!m_status[x][y]) {//�㲻Ϊ0���� Խ��
		m_status[x][y] = true;//�������ͨ��0 ����0�Աߵ�һ����Ϊ0�� ���ɼ�
		y--;
	
	}
	if (y != -1) {
		m_status[x][y] = true;//0�Աߵ�����;
	}
	return( (y==-1)?y+1:y);//Խ���˾ͷ��ر߽� ���򷵻��Լ�
};
int SweepingBombs::FindRight(int x, int y) {
	y++;
	while (y != m_status[0].size()&&m_grid[x][y] == 0&&!m_status[x][y] ) {//��ֹԽ�� �Լ�ȷ����ǰ��Ϊ0 ��������Ϊ0
		m_status[x][y] = true;
		y++;
	}
	if (y != m_status[0].size()) {
		m_status[x][y] = true;
	}
	return( (y==m_status[0].size())?y-1:y);//
};
void SweepingBombs::SearchLineNewSeed(stack<Point>& stk, int yLeft, int yRight,int row) {  //ɨ���� ɨ���������� ��ÿ�������������ջ
	int yL = yLeft + 1;
	if (row >= 1) {//���Ͽ� �����Ƿ�Ϊ0 ��ǰ�Ƿ�Ϊ1  ��1�ʹ򿪱��� 
		for (int L = yLeft, R = yRight; L <= R; L++) {
			if (m_grid[row - 1][L] == 0&&m_status[row-1][L]) {
				if (m_grid[row][L] != 0) {
					m_status[row][L] = true;
				}
			}
		}
	}
	if (row < m_grid.size()-1) {
		for (int L = yLeft, R = yRight; L <= R; L++) {
			if ( m_grid[row +1][L] == 0 && m_status[row +1][L]) {
				if ( m_grid[row][L] != 0) {
					m_status[row][L] = true;
				}
			}
		}

	}//���¿� �����Ƿ�Ϊ0 ����Ǿʹ򿪱���  ���¶��ж���Ϊ�˲���©����� ����ͨ��ɨ���߲�ͬ
	for ( int yR = yRight + 1; yL < yR; yL++) {//�������� �ҵ�0 X����� ��X ��ջ
		if (m_grid[row][yL] != 0) {
			if (m_grid[row][yL - 1] == 0&&!m_status[row][yL - 1]) {
				m_status[row][yL - 1] = true;
				stk.push(Point{ row,yL - 1 });//����ջ֮ǰ���Լ���Ϊ��
			}
		}
	}
	if (m_grid[row][yL - 1] == 0&&!m_status[row][yL - 1]) {//����߽� ������
		m_status[row][yL - 1] = true;
		stk.push(Point{ row,yL - 1 });
	}
};
void SweepingBombs::Play(int x, int y) {//��������
	//���벻�Ϸ�
	if (x<0 || x>=m_status.size() || y<0 || y>=m_status[0].size()) {
		cout << "WrongNumber";
	}
	if (m_status[x][y]) {//����Ѿ����㿪����
		cout << "You have opened it" << endl;
	}
	m_status[x][y] = true;
	if (m_grid[x][y] == -1) {//��� ��ը��
		gameStatus = false;
		cout << "GameOver" << endl;
	}
	else if (m_grid[x][y] >= 1) {//�����1�Լ�����
	}
	else {//�㿪����0
		ScanLineSeedFill(x, y);
	}
	Show_Status();
};




