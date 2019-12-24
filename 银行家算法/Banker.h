#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Banker {
	vector<int> m_Available, m_Safe, m_Work;
	vector<bool> m_Finish;
	vector<vector<int>> m_Max, m_Allocation, m_Need;
	queue<vector<int>> m_Request;
	int m_n, m_m;
public:
	void init() {
		m_Available.resize(m_m);
		m_Max.resize(m_n, vector<int>(m_m));
		m_Allocation.resize(m_n, vector<int>(m_m, 0));
		m_Need.resize(m_n, vector<int>(m_m));
		m_Finish.resize(m_n, false);
	}
	void input_(vector<vector<int>>& vv) {
		for (auto& i : vv) 
			for (auto& j : i) 
				cin >> j;
	}
	void print_(vector<vector<int>>& vv) {
		for (auto& i : vv)
			for (auto& j : i)
				cout << j <<' ';
		cout << endl;
	}
	void input() {
		cout << "输入进程个数和资源数\n";
		cin >> m_n >> m_m;
		init();
		cout << "输入各资源的个数\n";
		for (auto& i : m_Available) cin >> i;
		cout << "请输入" << m_n << 'x' << m_m << "最大需求矩阵Max\n";
		m_Work = m_Available;
		input_(m_Max);
		cout << "请输入" << m_n << 'x' << m_m << "分配矩阵Allocation\n";
		input_(m_Allocation);
		for (int i = 0; i < m_n ; ++i) {
			for (int j = 0; j < m_m; ++j) {
				m_Need[i][j] = m_Max[i][j] - m_Allocation[i][j];
			}
		}
	}
	void print() {
		cout << "Allocation" << endl;
		print_(m_Allocation);
		cout << "Need" << endl;
		print_(m_Need);
		cout << "Available" << endl;
		for (auto& i : m_Available)
			cout << i << ' ';
		cout << endl;
	}
	bool Safe_Algorithm() {
		if (m_Available.empty()) {
			cout << "请先输入数据\n";
			return false;
		}
		int count = 0, tmp;
		bool flag;
		while (count != m_n) {
			tmp = count;
			for (int i = 0; i < m_n; ++i) {
				if (m_Finish[i]) continue;
				flag = true;
				for (int j = 0; j < m_m; ++j) {
					if (m_Need[i][j] > m_Work[j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int j = 0; j < m_m; ++j) {
						m_Work[j] += m_Allocation[i][j];
					}
					m_Finish[i] = true;
					m_Safe[count++];
				}
			}
			if (count == tmp) {
				break;
			}
		}
		if (count == m_n) {
			cout << "系统是安全的!\n安全序列为:";
			for (int i = 0; i < count; ++i) {
				cout << m_Safe[i];
				i != count - 1 ? cout << "-->" : cout << endl;
			}
			return  true;
		}
		cout << "序列不安全\n";
		return false;
	}
	void Banker_Algorithm() {
		if (!Safe_Algorithm()) return;
		print();
		int id;
		while (1) {
			cout << "请输入一个需要分配资源的进程\n";
			while (!(cin >> id) || id<0 || id>m_n) {
				cout << "没有该进程! 请重新输入!" << endl;
			}
			bool flag;
			do {
				if (cin >> id) {
					if (id<0 || id>m_n) {
						cout << "没有该进程! 请重新输入!" << endl;
						continue;
					}
					if (m_Finish[id]) {
						cout << "此进程已经运行结束，请重新输入!" << endl;
						continue;
					}
					break;
				}
				else {
					cout << "输入格式错误, 请输入整数\n" << endl;
				}
			} while (1);

		}
	}
		
};