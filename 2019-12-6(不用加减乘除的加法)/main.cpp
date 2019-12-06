#include<iostream>
using namespace std;
class Solution {
public:
	int Add1(int num1, int num2) {
		int sum = 0, n =32;
		if (num1 < 0 && num2 >= 0 || num2 < 0 && num1 >= 0) {
			n = 32;
		}
		for (int i = 0; i < n; ++i) {
			if ((num1 & (1 << i)) && (num2 & (1 << i))) {
				sum |= 1 << (i + 1);
			}
			else if ((num1 & (1 << i)) == 0 && (num2 & (1 << i)) == 0);
			else {
				if ((sum&(1 << i)) == 0) {
					sum |= 1 << i;
				}
				else {
					sum |= 1 << (i + 1);
					sum &= (~(1 << i));
				}
			}
		}
		return sum;
	}
	int Add(int num1, int num2) {
		int tmp;
		while (num2) {
			tmp = num1 ^ num2;
			num2 = ((num1&num2) << 1);
			num1 = tmp;
		}
		return num1;
	}
};
int main() {
	int num1, num2;
	Solution s;
	while (cin >> num1 >> num2) {
		cout << s.Add(num1, num2) << endl;
	}
	system("pause");
	return 0;
}