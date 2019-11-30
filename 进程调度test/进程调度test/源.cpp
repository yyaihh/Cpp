#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#include <iostream>

#include <queue>

#include <stack>

#include <set>

#include <string>

#include <cstring>

#include <cmath>

#define MAX 1111

const double Max = 11111.0;

using namespace std;

typedef struct FCFS {
	int mark;
	string name;
	double arrivetime;
	double servetime;
	double starttime;
	double finishtime;
	double roundtime;
	double daiquantime;	   
	bool operator< (const FCFS &a)const {

		return arrivetime > a.arrivetime;

	}
}FCFS;



typedef struct SJF

{

	int mark;

	string name;

	double arrivetime;
		   
	double servetime;
		   
	double starttime;
		   
	double finishtime;
		   
	double roundtime;
		   
	double daiquantime;
		   
	bool operator< (const SJF &a)const {

		return servetime > a.servetime;

	}

}SJF;



typedef struct RDRN

{

	int mark;

	bool flag = true;

	string name;

	double Count = 0.0;

	double arrivetime;
		   
	double servetime;
		   
	double starttime;
		   
	double finishtime;
		   
	double roundtime;
		   
	double daiquantime;
		   
	double running = 0.0;

	bool operator< (const RDRN &a)const {

		return Count > a.Count;

	}

}RDRN;





void FCFS_arithmetic()

{

	FCFS f[MAX];

	FCFS ff;

	int n;

	double averagedaiquantime = 0.0;

	priority_queue<FCFS> q1;

	printf("请输入作业数(整数)\n");

	scanf("%d", &n);

	printf("请输入n组数据,每组数据包括作业名字(字符串)、作业到达时间(浮点数)、作业服务时间(浮点数)(每组数据的给元素之间用空格隔开!):\n");

	for (int i = 0; i < n; i++) {

		f[i].mark = i;

		cin >> f[i].name;

		scanf("%lf%lf", &f[i].arrivetime, &f[i].servetime);

		q1.push(f[i]);

	}

	double starttime = 0.0;

	ff = q1.top();

	q1.pop();

	f[ff.mark].starttime = ff.arrivetime;

	f[ff.mark].finishtime = f[ff.mark].starttime + ff.servetime;

	f[ff.mark].roundtime = f[ff.mark].finishtime - f[ff.mark].arrivetime;

	f[ff.mark].daiquantime = f[ff.mark].roundtime / f[ff.mark].servetime;

	starttime = f[ff.mark].finishtime;

	printf("先来先服务调度算法的作用时间表:\n\n");

	printf("作业名字 到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间\n");

	cout << "   " << f[ff.mark].name;

	printf("%10.2f %8.2f %8.2f %8.2f %8.2f%8.2f\n", f[ff.mark].arrivetime, f[ff.mark].servetime, f[ff.mark].starttime, f[ff.mark].finishtime, f[ff.mark].roundtime, f[ff.mark].daiquantime);

	while (!q1.empty()) {

		ff = q1.top();

		q1.pop();

		f[ff.mark].starttime = starttime;

		f[ff.mark].finishtime = f[ff.mark].starttime + ff.servetime;

		f[ff.mark].roundtime = f[ff.mark].finishtime - f[ff.mark].arrivetime;

		f[ff.mark].daiquantime = f[ff.mark].roundtime / f[ff.mark].servetime;

		averagedaiquantime += f[ff.mark].daiquantime;

		starttime = f[ff.mark].finishtime;

		cout << "  " << f[ff.mark].name;

		printf("%10.2f %8.2f %8.2f %8.2f %8.2f%8.2f\n", f[ff.mark].arrivetime, f[ff.mark].servetime, f[ff.mark].starttime, f[ff.mark].finishtime, f[ff.mark].roundtime, f[ff.mark].daiquantime);

	}

	printf("\n平均代权周转时间:\n");

	printf("%.2f\n", averagedaiquantime / n);

}



void SJF_arithmetic()

{

	SJF f[MAX];

	SJF ff;

	int n;

	double starttime = Max;

	double averagedaiquantime = 0.0;

	priority_queue<SJF> q1;

	printf("请输入作业数(整数)\n");

	scanf("%d", &n);

	printf("请输入n组数据,每组数据包括作业名字(字符串)、作业到达时间(浮点数)、作业服务时间(浮点数)(每组数据的给元素之间用空格隔开!):\n");

	for (int i = 0; i < n; i++) {

		f[i].mark = i;

		cin >> f[i].name;

		scanf("%lf %lf", &f[i].arrivetime, &f[i].servetime);

		if (f[i].arrivetime < starttime) starttime = f[i].arrivetime;

		q1.push(f[i]);

	}

	printf("短作业优先调度算法的作用时间表:\n\n");

	int cnt = 0;

	while (!q1.empty()) {

		SJF temp[MAX];

		ff = q1.top();

		q1.pop();

		if (f[ff.mark].arrivetime <= starttime) {

			for (int i = 0; i < cnt; i++) q1.push(temp[i]);

			cnt = 0;

			f[ff.mark].starttime = starttime;

			f[ff.mark].finishtime = f[ff.mark].starttime + ff.servetime;

			f[ff.mark].roundtime = f[ff.mark].finishtime - f[ff.mark].arrivetime;

			f[ff.mark].daiquantime = f[ff.mark].roundtime / f[ff.mark].servetime;

			averagedaiquantime += f[ff.mark].daiquantime;

			starttime = f[ff.mark].finishtime;

		}

		else temp[cnt++] = ff;

	}

	printf("作业名字 到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间\n");

	for (int i = 0; i < n; i++) {

		cout << "  " << f[i].name;

		printf("%10.2f %8.2f %8.2f %8.2f %8.2f%8.2f\n", f[i].arrivetime, f[i].servetime, f[i].starttime, f[i].finishtime, f[i].roundtime, f[i].daiquantime);

	}

	printf("\n平均代权周转时间:\n");

	printf("%.2f\n", averagedaiquantime / n);

}



void RDRN_arithmetic()

{

	double timeslice;

	RDRN f[MAX];

	RDRN temp[MAX];

	int cnt = 0;

	RDRN ff;

	int n;

	double averagedaiquantime = 0.0;

	priority_queue<RDRN> q1;

	printf("请输入作业数和时间片长度(作业数为整数，时间片长度可为浮点数，中间用空格隔开!):\n");

	scanf("%d%lf", &n, &timeslice);

	int tot = n;

	printf("请输入n组数据,每组数据包括作业名字(字符串)、作业到达时间(浮点数)、作业服务时间(浮点数)(每组数据的给元素之间用空格隔开!):\n");

	for (int i = 0; i < n; i++) {

		f[i].mark = i;

		cin >> f[i].name;

		scanf("%lf %lf", &f[i].arrivetime, &f[i].servetime);

		f[i].Count = f[i].arrivetime;

		q1.push(f[i]);

	}

	double clock = q1.top().arrivetime;

	int t = 0;

	while (t != n) {

		ff = q1.top();

		if (f[ff.mark].arrivetime <= clock && tot-- > 0) {

			q1.pop();

			if (f[ff.mark].flag) {

				f[ff.mark].starttime = clock;

				f[ff.mark].flag = false;

			}



			if (f[ff.mark].running != f[ff.mark].servetime) {

				double newtime = f[ff.mark].servetime - f[ff.mark].running;

				if (newtime >= timeslice) {

					clock += timeslice;

					f[ff.mark].running += timeslice;

					f[ff.mark].Count += timeslice;

				}

				else {

					clock += newtime;

					f[ff.mark].running += newtime;

					f[ff.mark].Count += newtime;

				}

				if (f[ff.mark].running != f[ff.mark].servetime) temp[cnt++] = f[ff.mark];

			}



			if (f[ff.mark].running == f[ff.mark].servetime) {

				t++;

				f[ff.mark].finishtime = clock;

				f[ff.mark].roundtime = f[ff.mark].finishtime - f[ff.mark].arrivetime;

				f[ff.mark].daiquantime = f[ff.mark].roundtime / f[ff.mark].servetime;

				averagedaiquantime += f[ff.mark].daiquantime;

			}

		}



		else {

			for (int i = 0; i < cnt; i++) q1.push(temp[i]);

			cnt = 0;

			tot = q1.size();

		}

	}



	printf("时间轮转调度算法的作用时间表:\n\n");

	printf("作业名字 到达时间 服务时间 开始时间 完成时间 周转时间 带权周转时间\n");

	for (int i = 0; i < n; i++) {

		cout << "  " << f[i].name;

		printf("%10.2f %8.2f %8.2f %8.2f %8.2f %8.2f\n", f[i].arrivetime, f[i].servetime, f[i].starttime, f[i].finishtime, f[i].roundtime, f[i].daiquantime);

	}

	printf("\n平均代权周转时间:\n");

	printf("%.2f\n", averagedaiquantime / n);

}



int main()

{

	printf("********************************************************欢迎您！***********************************************************\n");

	int ca = 0;

	do {

		printf("\n请选择调度算法或结束程序:\n");

		printf("0、结束程序\n1、先来先服务\n2、短作业优先\n3、时间片轮转\n");

		scanf("%d", &ca);

		if (ca == 1)FCFS_arithmetic();

		if (ca == 2)SJF_arithmetic();

		if (ca == 3) RDRN_arithmetic();

	} while (ca);

	return 0;

}