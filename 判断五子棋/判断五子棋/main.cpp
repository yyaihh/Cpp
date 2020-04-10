// write your code here cpp

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
	int i, j;
	vector<string> vs;
	bool f1(char c) {
		if (j <= 15 && i >= 4) {
			for (int right = j + 4, up = i - 4; up < i && right > j; --right, ++up) {//右上
				if (vs[up][right] != c) return false;
			}
			return true;
		}
		return false;
	}
	bool f2(char c) {
		if (i >= 4 && j >= 4) {
			for (int left = j - 4, up = i - 4; left < j && up < i; ++left, ++up) {//左上
				if (vs[up][left] != c) return false;
			}
			return true;
		}
		return false;
	}
	bool f3(char c) {
		if (j >= 4) {
			for (int left = j - 4; left < j; ++left) { //向左
				if (vs[i][left] != c) return false;
			}
			return true;
		}
		return false;
	}
	bool f4(char c) {
		if (i >= 4) {
			for (int up = i - 4; up < i; ++up) { //向上
				if (vs[up][j] != c) return false;
			}
			return true;
		}
		return false;
	}
public:
	Solution() :vs(20, string(20, 0)) {}
	bool fun(char c) {
		vs[0][0] = c;
		bool flag = true;
		for (i = 0, j = 1; j < 20; ++j) {
			cin >> vs[i][j];
			if (flag && (vs[i][j] == '+' || vs[i][j] == '*')) {
				if (f3(vs[i][j])) {
					flag = false;
				}
			}
		}
		for (i = 1; i < 20; ++i) {
			for (j = 0; j < 20; ++j) {
				cin >> vs[i][j];
				if (flag && (vs[i][j] == '+' || vs[i][j] == '*')) {
					if (f1(vs[i][j]) || f2(vs[i][j]) || f3(vs[i][j]) || f4(vs[i][j])) {
						flag = false;
					}
				}
			}
		}
		return !flag;
	}
};

int main() {
	Solution s;
	char c;
	while (cin >> c) {
		s.fun(c) ? cout << "Yes\n" : cout << "No\n";
	}
	return 0;
}