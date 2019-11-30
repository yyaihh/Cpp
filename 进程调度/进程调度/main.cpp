#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include<queue>
struct Node {
	char name;
	int Tarrive;//����ʱ��
	int Tservice;//����ʱ��
	int Tsurplus;//ʣ��ʱ��
	int Tstart;//��ʼʱ��
	int Taccomplish;//���ʱ��
	int prio;//���ȼ�---����Խ�����ȼ�Խ��
	int if_finish;//�����Ƿ����
	int num;//���̸���
}job[10];
//������ʱ������
void Arrive_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive > job[j].Tarrive)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//������ʱ������
void Service_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tservice > job[j].Tservice)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
			}
		}
	}
}
//�����ȼ�����
void Priority_sort(int num)//�����ȼ���С����
{
	int temp1, temp2, temp3, temp4;
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].prio < job[j].prio)
			{
				temp1 = job[j].name;
				job[j].name = job[i].name;
				job[i].name = temp1;
				temp2 = job[j].Tarrive;
				job[j].Tarrive = job[i].Tarrive;
				job[i].Tarrive = temp2;
				temp3 = job[j].Tservice;
				job[j].Tservice = job[i].Tservice;
				job[i].Tservice = temp3;
				temp4 = job[j].prio;
				job[j].prio = job[i].prio;
				job[i].prio = temp3;
			}
		}
	}
}
//�������ʱ����ȣ�����ʱ�䰴��С��������
void Arrive_Short_sort(int num)
{
	int temp1, temp2, temp3;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i].Tarrive >= job[j].Tarrive)
			{
				if (job[i].Tarrive > job[j].Tarrive)
				{
					temp1 = job[j].name;
					job[j].name = job[i].name;
					job[i].name = temp1;
					temp2 = job[j].Tarrive;
					job[j].Tarrive = job[i].Tarrive;
					job[i].Tarrive = temp2;
					temp3 = job[j].Tservice;
					job[j].Tservice = job[i].Tservice;
					job[i].Tservice = temp3;
				}
				else
				{
					if (job[i].Tservice > job[j].Tservice)
					{
						temp1 = job[j].name;
						job[j].name = job[i].name;
						job[i].name = temp1;
						temp2 = job[j].Tarrive;
						job[j].Tarrive = job[i].Tarrive;
						job[i].Tarrive = temp2;
						temp3 = job[j].Tservice;
						job[j].Tservice = job[i].Tservice;
						job[i].Tservice = temp3;
					}
				}
			}
		}
	}
}
void fcfs(int num)//�����ȷ���
{
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
		if (job[i].Tstart < job[i].Tarrive)
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void sjf(int num)//����ҵ����
{
	Service_sort(num);
	for (int i = 0; i < num; i++)
	{
		job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
		if (job[i].Tstart < job[i].Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
		{
			job[i].Tstart = job[i].Tarrive;
		}
		else
		{
			job[i].Tstart = job[i - 1].Taccomplish;
		}
		job[i].Taccomplish = job[i].Tstart + job[i].Tservice;
	}
}
void RR(int num)//RR�㷨
{
	int q;
	cout << "������ʱ��Ƭ���ȣ�" << endl;
	cin >> q;
	int flag = 1;//��־�������Ƿ��н���
	int finish_pro = 0;//��ɵĽ�����
	cout << "��������\t" << "��ʼʱ��\t" << "����ʱ��\t" << "ʣ�����ʱ��\t" << "����ʱ��\t" << endl;
	int time;//��¼��ǰʱ��ʱ��
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//����������û����
		for (int i = c; i < num; i++)
		{
			Arrive_sort(num);
			job[i].Tsurplus = job[i].Tservice;
			job[i].Tstart = job[i - 1].Taccomplish;//��һ����ҵ����ʱ��
			if (job[i].Tstart < job[i].Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
			{
				job[i].Tstart = job[i].Tarrive;
			}
			else
			{
				job[i].Tstart = job[i - 1].Taccomplish;
			}
			time = job[i].Tstart;
			if (job[i].if_finish == 1) continue;//�ý��������
			else
			{
				if (job[i].Tsurplus <= q && time >= job[i].Tarrive)//δ���������һ��ʱ��Ƭ
				{
					flag = 1;
					time = time + job[i].Tsurplus;
					job[i].if_finish = 1;//�ý������
					job[i].Taccomplish = time;
					cout << job[i].name << "\t\t" << job[i].Taccomplish - job[i].Tsurplus << "\t\t" << job[i].Tsurplus << "\t\t" << 0 << "\t\t" << job[i].Taccomplish << endl;
					job[i].Tsurplus = 0;
				}
				else if (job[i].Tsurplus > q && time >= job[i].Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i].Tsurplus -= q;
					job[i].Taccomplish = time;
					cout << job[i].name << "\t\t" << time - q << "\t\t" << q << "\t\t" << job[i].Tsurplus << "\t\t" << job[i].Taccomplish << endl;
					job[num].name = job[i].name;
					job[num].Tarrive = time;
					job[num].Tservice = job[i].Tsurplus;
					num++;
				}
				if (job[i].if_finish == 1) finish_pro++;//һ��������ɼ�һ
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//ûִ������û�����������
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i].if_finish == 0)
				{
					time = job[i].Tarrive;
					break;
				}
			}
		}
	}
}
//���
void print(int num)
{
	cout << "������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t" << "���ʱ��" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << job[i].name << "\t" << job[i].Tarrive << "\t\t" << job[i].Tservice << "\t\t" << job[i].Taccomplish << endl;
	}
}
void display(int num)
{
	int ch = 0;
	cout << "��������������������������������������������������" << endl;
	cout << "��������������������1��FCFS�㷨 ������������������" << endl;
	cout << "��������������������2��SJF�㷨��������������������" << endl;
	cout << "��������������������3��RR�㷨 ��������������������" << endl;
	cout << "��������������������4�����ȼ��㷨 ����������������" << endl;
	cout << "��������������������5���˳� ����������������������" << endl;
	cout << "��������������������������������������������������" << endl;
	do {
		cout << "��ѡ������Ҫ���㷨��" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			Arrive_sort(num);
			fcfs(num);
			print(num);
			break;
		case 2:
			//Arrive_Short_sort(num);
			sjf(num);
			print(num);
			break;
		case 3:
			RR(num);
			break;
		case 4:
			//priority(num);
			break;
		case 5:
			exit;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	} while (ch != 5);
}
int main()
{
	int num;
	char jname;
	int arrive;
	int service;
	int accomplish;
	cout << "��������̸�����" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "�����������������ʱ�䡢����ʱ��" << endl;
		cin >> jname;
		job[i].name = jname;
		cin >> arrive;
		job[i].Tarrive = arrive;
		cin >> service;
		job[i].Tservice = service;
	}
	display(num);
	return 0;
}
