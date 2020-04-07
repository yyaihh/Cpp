#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	double fun(int n, int m, vector<pair<int, int>>& vp) {
		vector<vector<bool>> vb(n + 1, vector<bool>(m + 1, false));
		vector<vector<double>> vf(n + 1, vector<double>(m + 1));//概率
		for (auto& i : vp) {
			vb[i.first][i.second] = true;
		}
		//当前格子可以从上面格子下来, 左边格子过来, 前一个格子有两种选择, 下或者右, 所以之前格子到当前格子的概率是0.5(边界除外)
		vf[1][1] = 1.0;//家的位置肯定没蘑菇, 不碰到蘑菇的概率就为1
		for (int i = 2; i <= n; ++i) {
			vf[i][1] = vb[i][1] ? 0 : vf[i - 1][1] * 0.5;
		}
		for (int i = 2; i <= m; ++i) {
			vf[1][i] = vb[1][i] ? 0 : vf[1][i - 1] * 0.5;
		}
		for (int i = 2; i < n; ++i) {
			for (int j = 2; j < m; ++j) {
				vf[i][j] = vb[i][j] ? 0 : vf[i - 1][j] * 0.5 + vf[i][j - 1] * 0.5;
			}
		}
		for (int i = 2; i < n; ++i) {
			vf[i][m] = vb[i][m] ? 0 : vf[i][m - 1] * 0.5 + vf[i - 1][m];
		}
		for (int i = 2; i < m; ++i) {
			vf[n][i] = vb[n][i] ? 0 : vf[n - 1][i] * 0.5 + vf[n][i - 1];
		}
		vf[n][m] = vf[n - 1][m] + vf[n][m - 1];
		return vf[n][m];
	}
};

int main() {
	int n, m, k;
	Solution s;
	while (cin >> n && cin >> m && cin >> k) {
		vector<pair<int, int>> vp(k);
		for (auto& i : vp) {
			cin >> i.first >> i.second;
		}
		printf("%.2f\n", s.fun(n, m, vp));
	}

}
