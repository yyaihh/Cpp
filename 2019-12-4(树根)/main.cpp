#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int fun(int n) {
		int Troot = 0;
		int cur = n;
		while (cur) {
			Troot += cur % 10;
			cur /= 10;
			if (cur == 0 && Troot / 10 > 0) {
				cur = Troot;
				Troot = 0;
			}
		}
		return Troot;
	}
};
int main() {
	int tmp;
	Solution s;
	string str;
	while (cin >> str) {
		tmp = 0;
		for (auto& i : str) {
			tmp += i - '0';
		}
		cout << s.fun(tmp) << endl;
	}
	system("pause");
	return 0;
}