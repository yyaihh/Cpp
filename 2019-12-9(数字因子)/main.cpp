// write your code here cpp
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
	int fun(int n) {
		int count = 0;
		int cri = (int)sqrt(n);
		for (int i = 2; i <= cri; i++) {
			if (n % i == 0) {
				do {//����һ�������Ƿ���ת��Ϊ�������, ��������8������2��4
					n = n / i;
				} while (n % i == 0);
				++count;
				cri = (int)sqrt(n);
			}
		}
		return count + (n != 1);//����2,3�����
	}
};

int main() {
	int num;
	Solution s;
	while (cin>>num) {
		cout << s.fun(num) << endl;
	}
	return 0;
}