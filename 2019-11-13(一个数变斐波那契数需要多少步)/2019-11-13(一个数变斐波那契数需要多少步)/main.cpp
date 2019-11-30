#include<iostream>
using namespace std;
class Solution {
public:
	int fun(int num) {
		if (num < 0) {
			return -num;
		}
		int left = 0;
		int right = 1;
		int tmp;
		while (num>right) {
			tmp = right;
			right += left;
			left = tmp;
		}
		if (right - num > num - left) {
			return num - left;
		}
		else {
			return right - num;
		}
	}

};
int main() {
	int num;
	cin >> num;
	Solution f;
	cout << f.fun(num);
	system("pause");
	return 0;
}