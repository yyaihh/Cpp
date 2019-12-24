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
		cout << "������̸�������Դ��\n";
		cin >> m_n >> m_m;
		init();
		cout << "�������Դ�ĸ���\n";
		for (auto& i : m_Available) cin >> i;
		cout << "������" << m_n << 'x' << m_m << "����������Max\n";
		m_Work = m_Available;
		input_(m_Max);
		cout << "������" << m_n << 'x' << m_m << "�������Allocation\n";
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
			cout << "������������\n";
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
			cout << "ϵͳ�ǰ�ȫ��!\n��ȫ����Ϊ:";
			for (int i = 0; i < count; ++i) {
				cout << m_Safe[i];
				i != count - 1 ? cout << "-->" : cout << endl;
			}
			return  true;
		}
		cout << "���в���ȫ\n";
		return false;
	}
	void Banker_Algorithm() {
		if (!Safe_Algorithm()) return;
		print();
		int id;
		while (1) {
			cout << "������һ����Ҫ������Դ�Ľ���\n";
			while (!(cin >> id) || id<0 || id>m_n) {
				cout << "û�иý���! ����������!" << endl;
			}
			bool flag;
			do {
				if (cin >> id) {
					if (id<0 || id>m_n) {
						cout << "û�иý���! ����������!" << endl;
						continue;
					}
					if (m_Finish[id]) {
						cout << "�˽����Ѿ����н���������������!" << endl;
						continue;
					}
					break;
				}
				else {
					cout << "�����ʽ����, ����������\n" << endl;
				}
			} while (1);

		}
	}
		
};