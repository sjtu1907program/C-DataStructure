#include<iostream>

using namespace std;
class RepeatWord {

public:
	// static string Process(string test) {
	  static char*  Process(string test){
		int tsize = test.size();
		if (tsize == 0)
			return NULL;
		int repeatTimes{1};//�ظ�����
		int length = 1;
		while (true) {
			int pos= length * repeatTimes;//����λ��
			if (pos + length > tsize) {//�ظ�������
				break;
			}
			if (test.compare(0, length, test, pos, length)==0) {//��ͬ�������ж�
				repeatTimes++;
			}
			else {
				length = pos +1;//�ȶ���Ϊ��ǰλ�õĳ���
				while (tsize%length != 0) {//Ѱ�ҿ������Ĺ�����
					length++;
				}
				repeatTimes = 1;
			}
		}


		char * s=new char[length+1];
		s[length + 1] = '\0';
		test.copy(s, length, 0);
		return s;
		//return test.substr(0,length);
	};
};



int main() {
	string a = "asfasfasfasfasfasfasfasfasfasfsasfasfasfasfasfasf";
	//string c = RepeatWord::Process(a);
	//printf("%s\n", c);
	cout << RepeatWord::Process(a)<<endl;
	return 0;
}