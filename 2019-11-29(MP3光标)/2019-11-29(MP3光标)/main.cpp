#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	void fun(int num, string& s) {
		int n, flag = 1, i = 0;
		num >= 4 ? n = 4 : n = num;
		for (auto&c : s) {
			if (c == 'U') {
				flag == 1 ? flag : --flag;
				i == 0 ? flag = n, i = num - 1 : --i;
			}
			else if (c == 'D') {
				flag == n ? flag : ++flag;
				i == num - 1 ? flag = 1, i = 0 : ++i;
			}
		}
		int f = i;
		while (--flag) --i;
		for (int j = 0; j < 4 && i < num; ++j) {
			cout << ++i << ' ';
		}
		cout << endl << f + 1 << endl;
	}
};
int main() {
	int num;
	string str;
	Solution s;
	while (cin >> num >> str) { 
		s.fun(num, str);
	}
	system("pause");
	return 0;
}