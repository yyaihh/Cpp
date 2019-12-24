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
//			cout << "输入错误，请重新输入!" << endl;
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
void bank();	//声明bank (应行家算法)
bool safe();//声明safe ()安全性算法
void init();
//*******************************主函数main() ****************************************************** /
int main() {
	int num;
	while (1) {
		cout << "1.输入数据。2.安全性检测算法。3.银行家算法。0.退出。" << endl;
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
			cout << "输入错误，请重新输入!" << endl;
	}
	return 0;
}
//******************************** 初始化函数init() ***************************************** 
void init() {
	int i, j, temp;
	cout << "请输入资源类数:";
	cin >> m;
	cout << "请输入各类资源总数!" << endl;
	Available.resize(m);
	for (i = 0; i < m; i++) {
		cout << "请输入R" << i << "类资源总数:";
		cin >> Available[i];
	}
	for (i = 0; i < m; i++)
		cout << Available[i] << endl;
	cout << "输入进程数:";
	cin >> n;
	Max.resize(n);
	for (i = 0; i < n; i++) {
		cout << "输入进程" << i << "的最大需求向量!" << endl;
		for (j = 0; j < m; j++) {
			cout << "输入需要R" << j << "类资源的最大数目:";
			cin >> temp;
			if (temp > Available[j]) {
				cout << j << "类资源最大需求超过该类资源总量，重新输入!";
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
	cout << "输入已分配的Allocation" << endl;
	Allocation.resize(n);
	Need.resize(n);
	for (i = 0; i < n; i++) {
		cout << "输入为进程" << i << "的分配向量" << endl;
		for (j = 0; j < m; j++) {
			cout << "输入分配R" << j << "类资源的数目:";
			cin >> temp;
			if (temp > Max[i][j]) {
				cout << "R" << j << "类资源分配超过该类需求资源总量，重新输入!";
				j--;
				continue;
			}
			if (temp > Available[j]) {
				cout << "R" << j << "类资源分配超过剩余资源总量，重新输入!";
				j--;
				continue;
			}
			Allocation[i].push_back(temp);
			temp = Max[i][j] - temp;
			Need[i].push_back(temp);
			Available[j] -= Allocation[i][j];
		}
		cout << "各资源总量剩余如下:" << endl;
		for (j = 0; j < m; j++)
			cout << Available[j] << " ";
		cout << endl;
	}
}
void bank() {
	if (Allocation.size() == 0 || Available.size() == 0) {
		cout << "没有进程，请先输入数据!" << endl;
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
	int jc;//任选一个进程
	char again;
	int all = 0;
	while (1) {
		while (all == 0) {
			all = 0;
			cout << "请选择一个要分配资源的进程:" << endl;
			cin >> jc;
			if (jc < 0 || jc >= n) {
				cout << "没有该进程!请重新输入!" << endl;
				continue;
			}
			for (j = 0; j < m; j++) {
				all += Need[jc][j];
			}
			if (all == 0) {
				cout << "此进程已经运行结束，请重新输入!" << endl;
			}
		}
		for (i = 0; i < m; i++) {
			cout << "请输入该进程的R" << i << "请求量:";
			cin >> Request[i];

		}
		int is = 1;
		for (i = 0; i < m; i++) {
			if (Request[i] > Available[i]) {
				cout << "该进程的R" << i << "请求量超过系统所剩资源!" << endl;
				is = 0;
			}
			else if (Request[i] > Need[jc][i]) {
				cout << "该进程的R" << i << "请求量超过所需资源!" << endl;
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

		//调用安全性算法，判断此次资源分配后，系统是否处安全状态
		if (safe())
			cout << "系统成功分配资源!" << endl;
		else {
			cout << "系统未能成分配资源,收回预分配资源!" << endl;
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
		cout << "您还想再次请求分配吗?是请按y/Y,否请按其它键" << endl;
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
		cout << "没有进程，请先输入数据!" << endl;
		return false;
	}
	vector< int> Work(Available);
	vector<bool> Finish(n, false);//申请工作向量work, finish
	vector<int> count(n);//记录安全序列
	int len = 0;//记录 安全序列的进程个数，如果len== n，即表示所有的finish[i] = true，处于安全状态.
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
			cout << "系统是安全的!" << endl;
			cout << "安全序列:";
			for (int i = 0; i < len; i++) {
				cout << count[i];
				if (i < len - 1)
					cout << "-->";
			}
			cout << endl;
			return  true;
		}
	}
	cout << "序列不安全" << endl;
	return false;
}



