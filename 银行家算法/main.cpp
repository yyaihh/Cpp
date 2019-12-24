//#include"Banker.h"
//using namespace std;
//void menu() {
//
//}
//int main() {
//	int num;
//	Banker b;
//	menu();
//	while (cin >> num) {
//		if (num == 1)
//			b.input();
//		else if (num == 2)
//			b.Safe_Algorithm();
//		else if (num == 3)
//			b.Banker_Algorithm();
//		else if (num == 0)
//			break;
//		else
//			cout << "�����������������!" << endl;
//		menu();
//	}
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
vector<int> Available;
vector<vector<int>>Need;
vector<vector<int>> Allocation;
vector<vector<int>> Max;
int n;
int m;
void bank();	//����bank (Ӧ�м��㷨)
bool safe();//����safe ()��ȫ���㷨
void init();
//*******************************������main() ****************************************************** /
int main() {
	int num;
	while (1) {
		cout << "1.�������ݡ�2.��ȫ�Լ���㷨��3.���м��㷨��0.�˳���" << endl;
		cin >> num;
		if (num == 1)
			init();
		else if (num == 2)
			safe();
		else if (num == 3)
			bank();
		else if (num == 0)
			break;
		else
			cout << "�����������������!" << endl;
	}
	return 0;
}
//******************************** ��ʼ������init() ***************************************** 
void init() {
	int i, j, temp;
	cout << "��������Դ����:";
	cin >> m;
	cout << "�����������Դ����!" << endl;
	Available.resize(m);
	for (i = 0; i < m; i++) {
		cout << "������R" << i << "����Դ����:";
		cin >> Available[i];
	}
	for (i = 0; i < m; i++)
		cout << Available[i] << endl;
	cout << "���������:";
	cin >> n;
	Max.resize(n);
	for (i = 0; i < n; i++) {
		cout << "�������" << i << "�������������!" << endl;
		for (j = 0; j < m; j++) {
			cout << "������ҪR" << j << "����Դ�������Ŀ:";
			cin >> temp;
			if (temp > Available[j]) {
				cout << j << "����Դ������󳬹�������Դ��������������!";
				j--;
			}
			Max[i].push_back(temp);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << Max[i][j] << " ";
		cout << endl;
	}
	cout << "�����ѷ����Allocation" << endl;
	Allocation.resize(n);
	Need.resize(n);
	for (i = 0; i < n; i++) {
		cout << "����Ϊ����" << i << "�ķ�������" << endl;
		for (j = 0; j < m; j++) {
			cout << "�������R" << j << "����Դ����Ŀ:";
			cin >> temp;
			if (temp > Max[i][j]) {
				cout << "R" << j << "����Դ���䳬������������Դ��������������!";
				j--;
				continue;
			}
			if (temp > Available[j]) {
				cout << "R" << j << "����Դ���䳬��ʣ����Դ��������������!";
				j--;
				continue;
			}
			Allocation[i].push_back(temp);
			temp = Max[i][j] - temp;
			Need[i].push_back(temp);
			Available[j] -= Allocation[i][j];
		}
		cout << "����Դ����ʣ������:" << endl;
		for (j = 0; j < m; j++)
			cout << Available[j] << " ";
		cout << endl;
	}
}
void bank() {
	if (Allocation.size() == 0 || Available.size() == 0) {
		cout << "û�н��̣�������������!" << endl;
		return;
	}
	if (!safe())
		return;
	int i, j;
	vector<int> Request(m);
	cout << "Allocation" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << Allocation[i][j] << " ";
		cout << endl;
	}
	cout << "Need" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << Need[i][j] << " ";
		cout << endl;

	}
	cout << "Available" << endl;
	for (i = 0; i < m; i++)
		cout << Available[i] << " ";
	cout << endl;
	int jc;//��ѡһ������
	char again;
	int all = 0;
	while (1) {
		while (all == 0) {
			all = 0;
			cout << "��ѡ��һ��Ҫ������Դ�Ľ���:" << endl;
			cin >> jc;
			if (jc < 0 || jc >= n) {
				cout << "û�иý���!����������!" << endl;
				continue;
			}
			for (j = 0; j < m; j++) {
				all += Need[jc][j];
			}
			if (all == 0) {
				cout << "�˽����Ѿ����н���������������!" << endl;
			}
		}
		for (i = 0; i < m; i++) {
			cout << "������ý��̵�R" << i << "������:";
			cin >> Request[i];

		}
		int is = 1;
		for (i = 0; i < m; i++) {
			if (Request[i] > Available[i]) {
				cout << "�ý��̵�R" << i << "����������ϵͳ��ʣ��Դ!" << endl;
				is = 0;
			}
			else if (Request[i] > Need[jc][i]) {
				cout << "�ý��̵�R" << i << "����������������Դ!" << endl;
				is = 0;
			}
		}
		if (is == 0)
			return;

		for (i = 0; i < m; i++) {
			Available[i] = Available[i] - Request[i];
			Allocation[jc][i] = Allocation[jc][i] + Request[i];
			Need[jc][i] = Need[jc][i] - Request[i];
		}

		//���ð�ȫ���㷨���жϴ˴���Դ�����ϵͳ�Ƿ񴦰�ȫ״̬
		if (safe())
			cout << "ϵͳ�ɹ�������Դ!" << endl;
		else {
			cout << "ϵͳδ�ܳɷ�����Դ,�ջ�Ԥ������Դ!" << endl;
			for (int i = 0; i < m; i++) {
				Available[i] = Available[i] + Request[i];
				Allocation[jc][i] = Allocation[jc][i] - Request[i];
				Need[jc][i] = Need[jc][i] + Request[i];
			}
		}
		cout << "Allocation" << endl;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				cout << Allocation[i][j] << " ";
			cout << endl;
		}
		cout << "Need" << endl;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				cout << Need[i][j] << " ";
			cout << endl;
		}
		cout << "Available" << endl;
		for (i = 0; i < m; i++)
			cout << Available[i] << " ";
		cout << endl;
		cout << "�������ٴ����������?���밴y/Y,���밴������" << endl;
		cin >> again;
		if (again == 'y' || again == 'Y') {
			all = 0;
			continue;
		}
		break;
	}
}
bool safe() {
	if (Allocation.size() == 0 || Available.size() == 0) {
		cout << "û�н��̣�������������!" << endl;
		return false;
	}
	vector< int> Work(Available);
	vector<bool> Finish(n, false);//���빤������work, finish
	vector<int> count(n);//��¼��ȫ����
	int len = 0;//��¼ ��ȫ���еĽ��̸��������len== n������ʾ���е�finish[i] = true�����ڰ�ȫ״̬.
	while (1) {
		int temp = len;
		for (int i = 0; i < n; i++) {
			if (Finish[i] == true)
				continue;
			bool needed = true;
			for (int j = 0; j < m; j++) {
				if (Need[i][j] > Work[j]) {
					needed = false;
					break;
				}
			}
			if (Finish[i] == false && needed == true) {
				for (int j = 0; j < m; j++)
					Work[j] += Allocation[i][j];
				Finish[i] = true;
				count[len++] = i;
			}
		}
		if (len == temp)
			break;
		if (len == n) {
			cout << "ϵͳ�ǰ�ȫ��!" << endl;
			cout << "��ȫ����:";
			for (int i = 0; i < len; i++) {
				cout << count[i];
				if (i < len - 1)
					cout << "-->";
			}
			cout << endl;
			return  true;
		}
	}
	cout << "���в���ȫ" << endl;
	return false;
}



