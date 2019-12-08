#include<iostream>
using namespace std;
class Solution {
public:
	pair<long, long> func(int n) {
		if (n == 1)return pair<long, long>(1, 1);
		long sum = (long)pow(5, n) - 4;
		long oldm = sum;
		for (int i = 0; i < n; oldm = (oldm - 1) * 4 / 5, ++i);
		return pair<long, long>(sum, oldm + n);
	}
};
int main() {
	int n;
	Solution s;
	pair<long, long> p;
	while (cin >> n) {
		if (n == 0)break;
		p = s.func(n);
		cout << p.first <<' '<<p.second << endl;
	}
	system("pause");
	return 0;
}