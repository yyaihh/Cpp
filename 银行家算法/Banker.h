#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Banker {
	vector<int> m_Available;
	vector<vector<int>> m_Max;
	vector<vector<int>> m_Allocation;
	vector<vector<int>> m_Need;
	queue<vector<int>> m_Request;
	int m_n, m_m;
public:
	void init() {
		m_Available.resize(m_m);
		m_Max.resize(m_n, vector<int>(m_m));
		m_Allocation.resize(m_n, vector<int>(m_m, 0));
		m_Need.resize(m_n, vector<int>(m_m));
	}
	void input_(vector<vector<int>>& vv) {
		for (auto& i : vv) 
			for (auto& j : i) 
				cin >> j;
	}
	void input() {
		cout << "输入进程个数和资源数\n";
		cin >> m_n >> m_m;
		init();
		cout << "输入各资源数\n";
		for (auto& i : m_Available) cin >> i;
		cout << "请输入" << m_n << 'x' << m_m << "最大需求矩阵Max\n";
		input_(m_Max);
		cout << "请输入" << m_n << 'x' << m_m << "分配矩阵Allocation\n";
		for (int i = 0; i < m_n ; ++i) {
			for (int j = 0; j < m_m; ++j) {
				m_Need[i][j] = m_Max[i][j] - m_Allocation[i][j];
			}
		}
	}
	bool Safe_algorithm() {

	}
	void Banker_algorithm() {
		bool flag = true;
		int i = 0, j = 0, R;
		vector<int> tmp(m_m);
		while (flag && !m_Request.empty()) {
			if (i < 5) {

			}
	
			m_Available[j] -= R;
			m_Allocation[i][j];
		}
	}
};