#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string fun(int num, int n) {
		string tmp;
		bool flag = false;
		if (num < 0) {
			num = -num;
			flag = true;
		}
		for (int c; num; num /= n) {
			c = num % n;
			if (c >= 10) {
				tmp.push_back(c - 10 + 'A');
			}
			else {
				tmp.push_back(c + '0');
			}
		}
		if (flag) {
			tmp += '-';
		}
		string res(tmp.rbegin(), tmp.rend());
		return res;
	}
};
int main() {
	int num, n;
	cin >> num;
	while (cin >> n) {
		if (n > 1 && n < 17) break;
	}
	Solution f;
	for (auto i : f.fun(num, n)) {
		cout << i;
	}
	system("pause");
	return 0;
}