#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<functional>
#include<list>
using namespace std;
class PCB {
	static int id;
public:
	string m_pname;
	int Tarrive;//到达时间
	int Tservice;//服务时间
	int Tsurplus;//剩余时间
	int Tstart;//开始时间
	int Taccomplish;//完成时间
	int prio;//优先级---数字越大优先级越高
	int if_finish;//进程是否完成
	int num;//进程个数
	bool operator >(const PCB& p)const {
		return this->Tarrive > p.Tarrive;
	}
};
priority_queue<PCB, vector<PCB>, greater<PCB>> fcfs(vector<PCB>& vp) {
	priority_queue<PCB, vector<PCB>, greater<PCB>> pq(vp.rbegin(), vp.rend());
	return pq;
}
list<PCB> RR(priority_queue<PCB, vector<PCB>, greater<PCB>>& pq) { 
	list<PCB> l;
	size_t T;
	cout << "请输入时间片\n";
	cin >> T;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	for (auto i = l.begin(); !l.empty(); ++i) {

	}
}
void print(const PCB& p) {
	cout << "进程名" << "\t" << "到达时间" << "\t" << "服务时间" << "\t" << "完成时间" << endl;
	cout << p.m_pname << '\t' << p.Tarrive << "\t\t" << p.Tservice << "\t\t" << p.Taccomplish<<endl;
}
void print2(int num){
	cout << "进程名" << "\t" << "到达时间" << "\t" << "服务时间" << "\t" << "完成时间" << endl;
	for (int i = 0; i < num; i++){
		
	}
}
int MENU() {
	int n;
	cout << "—————————————————————————" << endl;
	cout << "——————————1、FCFS算法 —————————" << endl;
	cout << "——————————2、RR算法 ——————————" << endl;
	cout << "——————————0、退出 ———————————" << endl;
	cout << "—————————————————————————" << endl;
	cin >> n;
	return n;
}
void input(vector<PCB>& vp) {
	for (auto& i : vp) {
		cout << "请输入进程名、到达时间、服务时间" << endl;
		cin >> i.m_pname;
		cin >> i.Tarrive;
		cin >> i.Tservice;
	}
}
int main() {
	int num;
	cout << "请输入进程个数\n";
	cin >> num;
	vector<PCB> vp(num);
	input(vp);
	priority_queue<PCB, vector<PCB>, greater<PCB>> pq1 = fcfs(vp);
	priority_queue<PCB, vector<PCB>, greater<PCB>> pq2 = pq1;
	while (1) {
		switch (MENU()) {
		case 1:
			while (!pq1.empty()) {
				print(pq1.top());
				pq1.pop();
			}
			break;
		case 2:
			
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