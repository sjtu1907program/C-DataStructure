#include"SweepingBombs.h"

int main() {
	cout << "�������� �� ը����" << endl;
	int row=0, col, bombs;
	cin >> row >> col >> bombs;
	SweepingBombs gameTest=SweepingBombs(row, col, bombs);
	cout << "��������������  ����-1 -1�˳�  ���߲ȵ��� �Զ�����" << endl;
	cin >> row >> col;//����x y���� �������±����ˣ�
	while (row != -1&&gameTest.getStatus()) {
		gameTest.Play(row, col);
	
			cout << "��������������  ����-1 -1�˳�  ���߲ȵ��� �Զ�����" << endl;
			cin >> row >> col;//����x y���� �������±����ˣ�
		
	}

	
}