#include<iostream>
using namespace std;
int NormalReverseNumber(int n) {
	int reverseResult=0;
	while (n >= 1 || n <= -1) {
		int temp = n % 10;
		reverseResult = reverseResult * 10 + temp;
		n = n / 10;
	}
	return reverseResult;
}
int ReverseNumber(int n) {
	int reverseResult = 0;
	int maxint = std::numeric_limits<int>::max();
	int minint = std::numeric_limits<int>::min();
	if ((n / 1000000000 >= 1) || (n / 1000000000 <= -1)) {//�洢����998765432*10�����֣�����ֵ�����ޣ�
		reverseResult = NormalReverseNumber(n % ((n / 1000000000) * 1000000000));

		if ((reverseResult > maxint / 10) || reverseResult < minint / 10) {//��ת���9λ �������ֵ��ת���9λ �����ж����һλ
			  return maxint;
		    
		}
		else if( (reverseResult==maxint/10)||(reverseResult==minint/10)) {//���벻�ܣ�int  ���ܽ���������
			if (((n/1000000000)>(maxint%10))||((n/1000000000)<(minint%10))) {
				return maxint;
			}
		}
		else {
			return reverseResult * 10 + n / 1000000000;
		}
	}
	else{
		reverseResult = NormalReverseNumber(n);
	}
	return reverseResult;
}

void test(int n) {
	auto result = ReverseNumber(n);
	if (result == std::numeric_limits<int>::max()) {
		cout << "Cannot reverse" << n << "  overflow error" << endl;
	}
	else {
		cout << n << " -> " << result << endl;
	
	}
}
int main() {
	test(123);
	test(-1234);
	test(1234567899);
	//test(-1234567899);
	//test(1234567801);
	//cout << std::numeric_limits<int>::max() << endl;//2147483647
	//test(7463847412); ���룾int�Ǹ�bug��
	return 0;
}