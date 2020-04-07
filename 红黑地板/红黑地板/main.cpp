// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	vector<string>* pvs;
	vector<vector<int>>* pvv;
	int right, down;
	int judge(int x, int y) {
		if (x < 0 || x >= down || y < 0 || y >= right || (*pvv)[x][y]) return 0;
		(*pvv)[x][y] = 1;
		return judge(x - 1, y) + judge(x + 1, y) + judge(x, y - 1) + judge(x, y + 1) + 1;
	}
public:
	int fun(vector<string>& vs) {
		pvs = &vs;
		right = vs[0].size(), down = vs.size();
		vector<vector<int>> vv(down, vector<int>(right));//±Í÷æ
		int x, y;
		pvv = &vv;
		for (int i = 0; i < down; ++i) {
			y = vs[i].find('@');
			if (y != string::npos) {
				x = i;
				break;
			}
		}
		for (int i = 0; i < down; ++i) {
			for (int j = 0; j < right; ++j) {
				vs[i][j] == '#' ? vv[i][j] = 1 : vv[i][j] = 0;
			}
		}
		return judge(x, y);
	}
};
int main() {
	int m, n;
	Solution s;
	while (cin >> m && cin >> n) {
		vector<string> vs(m);
		for (auto& s : vs) {
			cin >> s;
		}
		cout << s.fun(vs) << endl;
	}
	return 0;
}