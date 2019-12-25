#pragma once
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Banker {
	vector<int> m_Available, m_Safe;
	vector<vector<int>> m_Max, m_Allocation, m_Need;
	int m_n, m_m;
public:
	void init() {
		m_Available.resize(m_m);
		m_Max.resize(m_n, vector<int>(m_m));
		m_Allocation.resize(m_n, vector<int>(m_m, 0));
		m_Need.resize(m_n, vector<int>(m_m));
		m_Safe.resize(m_n);
	}
	void input_(vector<vector<int>>& vv) {
		for (auto& i : vv) 
			for (auto& j : i) 
				cin >> j;
	}
	void print_(vector<vector<int>>& vv) {
		for (auto& i : vv) {
			for (auto& j : i) {
				cout << j << ' ';
			}
			cout << endl;
		}
	}
	void input() {
		cout << "输入进程个数和资源数\n";
		cin >> m_n >> m_m;
		init();
		cout << "输入各资源的个数\n";
		for (auto& i : m_Available) cin >> i;
		cout << "请输入" << m_n << 'x' << m_m << "最大需求矩阵Max\n";
		input_(m_Max);
		cout << "请输入" << m_n << 'x' << m_m << "分配矩阵Allocation\n";
		input_(m_Allocation);
		for (int i = 0; i < m_n ; ++i) {
			for (int j = 0; j < m_m; ++j) {
				m_Need[i][j] = m_Max[i][j] - m_Allocation[i][j];
				while (m_Need[i][j] < 0) {
					cout << "Max与Allocation第" << i + 1 << "数据有误, 请重新输入\n请输入Max第" << i + 1 << "行";
					for (auto& i : m_Max[i]) {
						cin >> i;
					}
					cout << "请输入Max第" << i + 1 << "行";
					for (auto& i : m_Allocation[i]) {
						cin >> i;
					}
					m_Need[i][j] = m_Max[i][j] - m_Allocation[i][j];
				}
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
		vector<bool> Finish(m_n, false);
		vector<int> Work(m_Available);
		int count = 0, tmp;
		bool flag;
		while (count != m_n) {
			tmp = count;
			for (int i = 0; i < m_n; ++i) {
				if (Finish[i]) continue;
				flag = true;
				for (int j = 0; j < m_m; ++j) {
					if (m_Need[i][j] > Work[j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int j = 0; j < m_m; ++j) {
						Work[j] += m_Allocation[i][j];
					}
					Finish[i] = true;
					m_Safe[count++] = i;
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
		return false;
	}
	void Banker_Algorithm() {
		if (!Safe_Algorithm()) return;
		print();
		int id;
		vector<int> Request(m_m);
		char ch = 0;
		bool flag;
		do{
			cout << "请输入一个需要分配资源的进程\n";
			do {
				if (cin >> id) {
					if (id < 0 || id > m_n) {
						cout << "没有该进程! 请重新输入!\n";
						continue;
					}
					flag = true;
					for (auto& i : m_Need[id]) {
						if (i > 0) {
							flag = false;
							break;
						}
					}
					if (flag) {
						cout << "此进程已经运行结束，请重新输入!\n";
						continue;
					}
					break;
				}
				else {
					cout << "输入格式错误, 请输入整数\n";
				}
			} while (1);
			flag = true;
			cout << "请输入该进程的各个资源的请求量:\n";
			for (int i = 0; i < m_m; i++) {
				cin >> Request[i];
				flag && Request[i] != m_Need[id][i] ? flag = false : flag;
			}
			if (flag) {
				cout << "*Request==Need*/系统成功分配资源!\n";
				for (int i = 0; i < m_m; i++) {
					m_Available[i] += m_Need[id][i];
					m_Need[id][i] = m_Allocation[id][i] = 0;
				}
			}
			else {
				flag = true;
				for (int i = 0; i < m_m; i++) {
					if (Request[i] > m_Need[id][i]) {
						cout << "该进程对资源的请求量超过所需资源!\n";
						flag = false;
						break;
					}
					else if (Request[i] > m_Available[i]) {
						cout << "该进程对资源请求量超过系统所剩资源!\n";
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int i = 0; i < m_m; i++) {
						m_Available[i] -= Request[i];
						m_Allocation[id][i] += Request[i];
						m_Need[id][i] -= Request[i];
					}
					if (Safe_Algorithm())
						cout << "系统成功分配资源!\n";
					else {
						cout << "试分配为:\n";
						print();
						cout << "系统不安全, 系统未能成功分配资源,收回预分配的资源!\n收回后为:\n";
						for (int i = 0; i < m_m; i++) {
							m_Available[i] += Request[i];
							m_Allocation[id][i] -= Request[i];
							m_Need[id][i] += Request[i];
						}
					}
				}
			}
			print();
			cout << "继续分配按y/Y\n";
			cin >> ch;
		} while (ch == 'y' || ch == 'Y');
	}
};