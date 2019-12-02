#include <iostream>
#include <vector>
using namespace std;
class Solution {
	int N, M;
	vector<vector<int>> m_maze;//迷宫矩阵
	vector<pair<int, int>> m_path_cur;//当前路径
	vector<pair<int, int>> m_path_best;//最佳路径
	void dealmaze(int i, int j) {
		m_maze[i][j] = 1;//已经走过的不能再走, 所以置1
		m_path_cur.push_back({ i, j });//记录当前节点
		if (i == N - 1 && j == M - 1) {//是否到达终点
			if (m_path_best.empty() || m_path_cur.size() < m_path_best.size()) {//选择最短路径
				m_path_best = m_path_cur;
			}
		}
		if (i - 1 >= 0 && m_maze[i - 1][j] == 0)//向上走是否可行
			dealmaze(i - 1, j);
		if (i + 1 < N && m_maze[i + 1][j] == 0)//向下走是否可行
			dealmaze(i + 1, j);
		if (j - 1 >= 0 && m_maze[i][j - 1] == 0)//向左走是否可行
			dealmaze(i, j - 1);
		if (j + 1 < M && m_maze[i][j + 1] == 0)//向右走是否可行
			dealmaze(i, j + 1);
		//不能继续走了, 要么走完了, 要么死路了, 回到上一步
		m_maze[i][j] = 0;//恢复现场，上一个位置要设为未走, 所以置0
		m_path_cur.pop_back();//当前路径退回, 所以pop
	}
public:
	vector<pair<int, int>>& maze() { 
		m_path_best.clear();
		m_path_cur.clear();
		dealmaze(0, 0);
		m_maze.clear();
		return m_path_best;
	}
	friend istream& operator>>(istream& os, Solution& s);
};
istream& operator>>(istream& os, Solution& s) {
	os >> s.N >> s.M;
	s.m_maze.resize(s.N, vector<int>(s.M));
	for (auto& i : s.m_maze) {
		for (auto& j : i) {
			os >> j;
		}
	}
	return os;
}
int main() {
	Solution s;
	while (cin >> s) { 
		vector<pair<int, int>>& bp = s.maze();
		for (auto i : bp) {
			cout << '(' << i.first << ',' << i.second << ')' << endl;
		}
	}
	return 0;
}