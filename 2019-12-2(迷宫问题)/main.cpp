#include <iostream>
#include <vector>
using namespace std;
class Solution {
	int N, M;
	vector<vector<int>> m_maze;//�Թ�����
	vector<pair<int, int>> m_path_cur;//��ǰ·��
	vector<pair<int, int>> m_path_best;//���·��
	void dealmaze(int i, int j) {
		m_maze[i][j] = 1;//�Ѿ��߹��Ĳ�������, ������1
		m_path_cur.push_back({ i, j });//��¼��ǰ�ڵ�
		if (i == N - 1 && j == M - 1) {//�Ƿ񵽴��յ�
			if (m_path_best.empty() || m_path_cur.size() < m_path_best.size()) {//ѡ�����·��
				m_path_best = m_path_cur;
			}
		}
		if (i - 1 >= 0 && m_maze[i - 1][j] == 0)//�������Ƿ����
			dealmaze(i - 1, j);
		if (i + 1 < N && m_maze[i + 1][j] == 0)//�������Ƿ����
			dealmaze(i + 1, j);
		if (j - 1 >= 0 && m_maze[i][j - 1] == 0)//�������Ƿ����
			dealmaze(i, j - 1);
		if (j + 1 < M && m_maze[i][j + 1] == 0)//�������Ƿ����
			dealmaze(i, j + 1);
		//���ܼ�������, Ҫô������, Ҫô��·��, �ص���һ��
		m_maze[i][j] = 0;//�ָ��ֳ�����һ��λ��Ҫ��Ϊδ��, ������0
		m_path_cur.pop_back();//��ǰ·���˻�, ����pop
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