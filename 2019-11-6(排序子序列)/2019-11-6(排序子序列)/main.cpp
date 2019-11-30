#include<iostream>
using namespace std;
class Solution {
public:
	inline bool f(int x, int y,int& i,int n) {
		if (x> y) {
			return true;
		}
		else if (x< y) {
			return false;
		}
		else {
			while (i < n - 1) {
				++i;
				if (x> y) {
					return true;
				}
				else if (x< y) {
					return false;
				}
			}
		}
		return true;
	}
	int fun(int* a, int n) {
		if (n < 1) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		bool flag = false;//代表递增
		if (a[0] > a[1]) {
			flag = true;//代表递减
		}
		int count = 1;
		for (int i = 2; i < n - 1; ++i) {
			if (flag&&a[i - 1] < a[i]) {
				++count;
				flag = f(a[i], a[i + 1], i, n);
			}
			else if (!flag&&a[i - 1] > a[i]) {
				++count;
				flag = f(a[i], a[i + 1], i, n);
			}
		}
		if (flag&&a[n - 2] < a[n - 1]) {
			++count;
		}
		else if (!flag&&a[n - 2] > a[n - 1]) {
			++count;
		}
		return count;
	}
};
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	Solution f;
	cout << f.fun(a, n) << endl;
	system("pause");
	return 0;
}