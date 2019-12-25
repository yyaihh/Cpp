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
		cout << "������̸�������Դ��\n";
		cin >> m_n >> m_m;
		init();
		cout << "�������Դ�ĸ���\n";
		for (auto& i : m_Available) cin >> i;
		cout << "������" << m_n << 'x' << m_m << "����������Max\n";
		input_(m_Max);
		cout << "������" << m_n << 'x' << m_m << "�������Allocation\n";
		input_(m_Allocation);
		for (int i = 0; i < m_n ; ++i) {
			for (int j = 0; j < m_m; ++j) {
				m_Need[i][j] = m_Max[i][j] - m_Allocation[i][j];
				while (m_Need[i][j] < 0) {
					cout << "Max��Allocation��" << i + 1 << "��������, ����������\n������Max��" << i + 1 << "��";
					for (auto& i : m_Max[i]) {
						cin >> i;
					}
					cout << "������Max��" << i + 1 << "��";
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
			cout << "������������\n";
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
			cout << "ϵͳ�ǰ�ȫ��!\n��ȫ����Ϊ:";
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
			cout << "������һ����Ҫ������Դ�Ľ���\n";
			do {
				if (cin >> id) {
					if (id < 0 || id > m_n) {
						cout << "û�иý���! ����������!\n";
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
						cout << "�˽����Ѿ����н���������������!\n";
						continue;
					}
					break;
				}
				else {
					cout << "�����ʽ����, ����������\n";
				}
			} while (1);
			flag = true;
			cout << "������ý��̵ĸ�����Դ��������:\n";
			for (int i = 0; i < m_m; i++) {
				cin >> Request[i];
				flag && Request[i] != m_Need[id][i] ? flag = false : flag;
			}
			if (flag) {
				cout << "*Request==Need*/ϵͳ�ɹ�������Դ!\n";
				for (int i = 0; i < m_m; i++) {
					m_Available[i] += m_Need[id][i];
					m_Need[id][i] = m_Allocation[id][i] = 0;
				}
			}
			else {
				flag = true;
				for (int i = 0; i < m_m; i++) {
					if (Request[i] > m_Need[id][i]) {
						cout << "�ý��̶���Դ������������������Դ!\n";
						flag = false;
						break;
					}
					else if (Request[i] > m_Available[i]) {
						cout << "�ý��̶���Դ����������ϵͳ��ʣ��Դ!\n";
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
						cout << "ϵͳ�ɹ�������Դ!\n";
					else {
						cout << "�Է���Ϊ:\n";
						print();
						cout << "ϵͳ����ȫ, ϵͳδ�ܳɹ�������Դ,�ջ�Ԥ�������Դ!\n�ջغ�Ϊ:\n";
						for (int i = 0; i < m_m; i++) {
							m_Available[i] += Request[i];
							m_Allocation[id][i] -= Request[i];
							m_Need[id][i] += Request[i];
						}
					}
				}
			}
			print();
			cout << "�������䰴y/Y\n";
			cin >> ch;
		} while (ch == 'y' || ch == 'Y');
	}
};