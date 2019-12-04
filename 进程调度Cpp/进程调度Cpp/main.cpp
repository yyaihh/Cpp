#include<iostream>
#include<queue>
#include<string>
using namespace std;
class PCB {
	static int id;
public:
	string m_pname;
	int arrtime = 0;//����ʱ��
	int sertime = 0;//����ʱ��
	int sertime2 = 0;//����ʱ��
	int fintime = 0;//���ʱ��
	int turntime = 0;//��תʱ��
	double Turntime = 0;//��Ȩ��תʱ��
	bool if_finish = false;//�����Ƿ����
	bool operator >(const PCB& p)const {
		return this->arrtime > p.arrtime;
	}
};
void print(const PCB& p) {
	cout << p.m_pname << "\t" << p.arrtime << "\t" << "   " << p.sertime << "\t\t" << p.fintime << "\t" << p.turntime << "\t\t";
	printf("%.2f\n", p.Turntime);
}
void print_(const PCB& p) {
	cout << p.m_pname << "\t" << p.arrtime << "\t" << "   " << p.sertime << "\t\t" << p.fintime << endl;
}
void Sort(vector<PCB>& vp, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (vp[j].arrtime > vp[j + 1].arrtime) {
				swap(vp[j], vp[j + 1]);
			}
		}
	}
}
vector<PCB> fcfs(vector<PCB>& vp, int n) {
	vector<PCB> v = vp;
	Sort(v, n);
	int ftime = vp[0].arrtime;
	for (int i = 0; i < n; ++i) {
		PCB& p = v[i];
		p.fintime = p.sertime + ftime;
		ftime = p.fintime;
	}
	return v;
}
vector<PCB> RR(vector<PCB>& vp, int n) {
	deque<PCB> cq;
	vector<PCB> v;
	int T, time = 0, tsum = 0;
	double Tsum = 0;
	cout << "������ʱ��Ƭ\n";
	cin >> T;
	for (auto& i : vp) cq.push_back(i);
	while (!cq.empty()) {
		time += T;
		PCB& tmp = cq.front();
		tmp.sertime2 -= T;
		cq.pop_front();
		if (tmp.sertime2 > 0) {
			cq.push_back(tmp);
		}
		else {
			tmp.sertime2 == 0 ? tmp.fintime = time : time += tmp.sertime2, tmp.fintime = time;
			tmp.turntime = tmp.fintime - tmp.arrtime;
			tmp.Turntime = (double)tmp.turntime / (double)tmp.sertime;
			Tsum += tmp.Turntime;
			tsum += tmp.turntime;
			v.push_back(tmp);
		}
	}
	printf("��תʱ���ƽ��ֵ�� : %.2f\n", tsum / (double)n);
	printf("��Ȩ��תʱ���ƽ��ֵ�� : %.2f\n", Tsum / n);
	cout << "������" << "  " << "����ʱ��" << " " << "����ʱ��" << "  " << "���ʱ��" << "  " << "��תʱ��" << "  " << "��Ȩ��תʱ��" << endl;
	return v;
}
int MENU() {
	int n;
	cout << "��������������������1��FCFS�㷨 ������������������" << endl;
	cout << "��������������������2��RR�㷨 ��������������������" << endl;
	cout << "��������������������0���˳� ����������������������" << endl;
	cin >> n;
	return n;
}
void input(vector<PCB>& vp) {
	for (auto& i : vp) {
		cout << "�����������������ʱ�䡢����ʱ��" << endl;
		cin >> i.m_pname;
		cin >> i.arrtime;
		cin >> i.sertime;
		i.sertime2 = i.sertime;
	}
}
int main() {
	int num;
	cout << "��������̸���\n";
	cin >> num;
	vector<PCB> vp(num);
	input(vp);
	Sort(vp, num);
	while (1) {
		switch (MENU()) {
		case 1:
			cout << "������" << "  " << "����ʱ��" << " " << "����ʱ��" << "  " << "���ʱ��" << "  " <<endl;
			for (auto& i : fcfs(vp, num)) print_(i);
			break;
		case 2:
			for (auto& i : RR(vp, num)) print(i);
			break;
		case 0:
			cout << "�˳�!\n";
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}