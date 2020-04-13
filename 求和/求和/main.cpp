#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Solution {
	vector<vector<int>>* pres;
	void judge(int n, int m, int num = 1) {
		static vector<int> tmp;
		if (m == 0) {
			pres->push_back(tmp);
		}
		for (int i = num; i <= n && i <= m; ++i) {
			tmp.push_back(i);
			judge(n, m - i, i + 1);
			tmp.pop_back();
		}
	}
public:
	vector<vector<int>> fun(int n, int m) {
		vector<vector<int>> res;
		pres = &res;
		judge(n, m);
		return res;
	}
};

int main() {
	Solution s;
	int n, m, i, size;
	while (cin >> n && cin >> m) {
		for (auto& v : s.fun(n, m)) {
			for (i = 0, size = v.size() - 1; i < size; ++i) {
				cout << v[i] << ' ';
			}
			cout << v[i] << endl;
		}
	}
	return 0;
}
