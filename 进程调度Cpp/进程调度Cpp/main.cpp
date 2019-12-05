#include<iostream>
#include<queue>
#include<string>
#include"Circularqueue.h"
using namespace std;
void print_(const PCB& p) {
	cout << p.name << "\t" << p.arrtime << "\t" << "   " << p.sertime << "\t\t" << p.fintime << endl;
}
bool cmp1(const PCB& a, const PCB& b) {
	return a.arrtime > b.arrtime;
}
bool cmp2(const PCB& a, const PCB& b) {
	return a.sertime > b.sertime;
}
void Sort(deque<PCB>& vp, int n, bool(*cmp)(const PCB&, const PCB&)) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (cmp(vp[j], vp[j+1])) {
				swap(vp[j], vp[j + 1]);
			}
		}
	}
}
vector<PCB> fcfs(deque<PCB>& vp, int n) {
	vector<PCB> v(vp.begin(), vp.end());
	int ftime = vp[0].arrtime;
	for (int i = 0; i < n; ++i) {
		PCB& p = v[i];
		p.fintime = p.sertime + ftime;
		ftime = p.fintime;
	}
	return v;
}
vector<PCB> sjf(deque<PCB>& vp, int n) {
	vector<PCB> v(vp.begin(), vp.end());
	int ftime = vp[0].arrtime;
	for (int i = 0; i < n; ++i) {
		PCB& p = v[i];
		p.fintime = p.sertime + ftime;
		ftime = p.fintime;
	}
	return v;
}
//vector<PCB> RR(deque<PCB> vp, int n) {
//	deque<PCB> cq;
//	queue<PCB> qu;
//	vector<PCB> v(n);
//	int T, time = 0, tsum = 0;
//	double Tsum = 0;
//	cout << "请输入时间片\n";
//	cin >> T;
//	//for (auto& i : vp) cq.push_back(i);
//	cq.push_back(vp[0]);
//	int i = 1;
//	while (!cq.empty() || !qu.empty()) {
//		time += T;
//		PCB tmp = cq.front();
//		tmp.sertime2 -= T;
//		cq.pop_front();
//		if (tmp.sertime2 > 0) {
//			if(i < n - 1 && time >= vp[i + 1].arrtime) {
//				qu.push(tmp);
//				while (i < n - 1 && time >= vp.front().arrtime()) {
//					cq.push_back(vp.front());
//					vp.pop_front();
//				}
//				cq.push_back(tmp);
//				qu.pop();
//				continue;
//			}
//			else {
//				cq.push_back(tmp);
//			}
//		}
//		else {
//			tmp.sertime2 == 0 ? tmp.fintime = time : time += tmp.sertime2, tmp.fintime = time;
//			tmp.turntime = tmp.fintime - tmp.arrtime;
//			tmp.Turntime = (double)tmp.turntime / (double)tmp.sertime;
//			Tsum += tmp.Turntime;
//			tsum += tmp.turntime;
//			v.push_back(tmp);
//			qu.pop();
//		}
//	}
//	printf("周转时间的平均值是 : %.2f\n", tsum / (double)n);
//	printf("带权周转时间的平均值是 : %.2f\n", Tsum / n);
//	cout << "进程名" << "  " << "到达时间" << " " << "服务时间" << "  " << "完成时间" << "  " << "周转时间" << "  " << "带权周转时间" << endl;
//	return v;
//}
int MENU() {
	int n;
	cout << "——————————1、FCFS算法 —————————" << endl;
	cout << "——————————2、RR算法 ——————————" << endl;
	cout << "——————————3、短作业 ——————————" << endl;
	cout << "——————————0、退出 ———————————" << endl;
	cin >> n;
	return n;
}
void input(deque<PCB>& vp) {
	int j = 0;
	for (auto& i : vp) {
		cout << "请输入进程名、到达时间、服务时间" << endl;
		cin >> i.name;
		cin >> i.arrtime;
		cin >> i.sertime;
		i.sertime2 = i.sertime;
	}
}
int main() {
	int num;
	while (1) {
		cout << "请输入进程个数\n";
		cin >> num;
		deque<PCB> vp(num);
		PCB* P = new PCB[num];
		PCB* P2 = new PCB[num];
		input(vp);
		deque<PCB> vp2 = vp;
		Sort(vp, num, cmp1);
		Sort(vp2, num, cmp2);
		int j = 0;
		for (auto i : vp) {
			P[j].name = i.name;
			P[j].arrtime = i.arrtime;
			P[j].sertime = i.sertime;
			++j;
		}
		j = 0;
		for (auto i : vp2) {
			P2[j].name = i.name;
			P2[j].arrtime = i.arrtime;
			P2[j].sertime = i.sertime;
			++j;
		}
		switch (MENU()) {
		case 1:
			cout << "进程名" << "  " << "到达时间" << " " << "服务时间" << "  " << "完成时间" << "  " <<endl;
			for (auto& i : fcfs(vp, num)) print_(i);
			break;
		case 2:	
			RR(P, num, num);
			break;
		case 3:
			cout << "进程名" << "  " << "到达时间" << " " << "服务时间" << "  " << "完成时间" << "  " << endl;
			SJF(P2, num);
			break;
		case 0:
			cout << "退出!\n";
			break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}