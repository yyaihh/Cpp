#include<iostream>
#include<vector>
#include<string>
#include <queue>
using namespace std;
struct process
{
	string name;//������
	double arrtime;//����ʱ��
	double sertime;//����ʱ��
	int flag = 0;//�����������Ƿ��ѱ�ִ�У�ִ����λ1��û��ִ����λ0
	int num = 0;//û�й����� ��num Ϊ0������numΪ1��
	double N = 0.0; //ʱ��Ƭ
	double fintime = 0.0;//���ʱ��
	double turntime = 0.0;//��תʱ��
	double Turntime = 0.0;//��Ȩ��תʱ��

};


//
//void print(process * P)
//{
//	cout << "������" << " " << "����ʱ��" << " " << "����ʱ��" << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << P->name << "\t" << P->arrtime << "\t" << P->sertime << endl;
//		P++;
//	}
//}


void SortArrtime(process * P, int n) //����ʱ������
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->arrtime > (P + j + 1)->arrtime)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp = (P + j)->name;
				(P + j)->name = (P + j + 1)->name;
				(P + j + 1)->name = tmp;

				tmp1 = (P + j)->arrtime;
				(P + j)->arrtime = (P + j + 1)->arrtime;
				(P + j + 1)->arrtime = tmp1;

				tmp2 = (P + j)->sertime;
				(P + j)->sertime = (P + j + 1)->sertime;
				(P + j + 1)->sertime = tmp2;
			}
		}
	}
}

void SSortSertime(process * P, int n) //����ʱ������
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((P + j)->sertime >= (P + j + 1)->sertime)
			{
				string tmp;
				int tmp1;
				int tmp2;

				tmp = (P + j)->name;
				(P + j)->name = (P + j + 1)->name;
				(P + j + 1)->name = tmp;

				tmp1 = (P + j)->arrtime;
				(P + j)->arrtime = (P + j + 1)->arrtime;
				(P + j + 1)->arrtime = tmp1;

				tmp2 = (P + j)->sertime;
				(P + j)->sertime = (P + j + 1)->sertime;
				(P + j + 1)->sertime = tmp2;
			}
		}
	}
}
void SJF(process *P, int n) //����ҵ�㷨
{
	int time = 0; //��ǰ��ʱ��
	int i = n;
	P->flag = 0; //��ǽ����Ƿ��Ա�ִ��
	while (i >= 1)
	{
		for (int j = 0; j < n; j++)
		{
			if (P[j].arrtime <= time && P[j].flag == 0)
			{
				P[j].fintime = time + P[j].sertime;
				P[j].turntime = P[j].fintime - P[j].arrtime;
				P[j].Turntime = P[j].turntime / P[j].sertime;
				time = P[j].fintime;
				P[j].flag = 1;
				i--;
				j = -1;
			}
		}
		time++;
	}
}

void FCFS(process *P, int n) //�ȵ��ȷ����㷨
{
	int time = 0;

	int i = 1;
	P[0].fintime = P[0].arrtime + P[0].sertime;
	P[0].turntime = P[0].fintime - P[0].arrtime;
	P[0].Turntime = P[0].turntime / P[0].sertime;
	while (i < n)
	{
		if (time > P[i].arrtime)
		{
			P[i].fintime = P[i - 1].fintime + P[i].sertime;
			P[i].turntime = P[i].fintime - P[i].arrtime;
			P[i].Turntime = P[i].turntime / P[i].sertime;
			i++;
		}
		else
		{
			time++;
		}
	}
}

void RR(process *P, int W) //ʱ��Ƭ��ת�㷨
{
	int T;
	cout << "������ʱ��Ƭ" << endl;
	cin >> T;
	for (int i = 0; i < W; i++)
	{
		P[i].N = T;
	}
	double serive[100] = { 0 };
	for (int i = 0; i < W; i++)
	{
		serive[i] = P[i].sertime;
	}
	queue<string> qu; //����һ�����У���Ҫִ�е���ҵ
	double time = 0.0;
	while (qu.empty())
	{
		if (P[0].arrtime <= time)
		{
			qu.push(P[0].name);
			P[0].num = 1;
		}
		else
		{
			time++;
		}
	}
	for (int i = 1; i < W; i++)
	{
		if (P[i].arrtime <= time)
		{
			qu.push(P[i].name);
			P[i].num = 1;
		}
	}
	while (!qu.empty())
	{
		string tmp;
		for (int s = 0; s < W; s++)
		{
			for (int j = 0; j < W && (!qu.empty()); j++)
			{
				tmp = qu.front();
				if (tmp == P[j].name)
				{
					if (serive[j] > P[j].N && P[j].flag == 0)
					{
						serive[j] -= P[j].N;
						time += P[j].N;
						P[j].fintime = time;
						qu.pop();
						for (int i = 0; i < W; i++)
						{
							if (P[i].num == 0 && P[i].arrtime <= time)
							{
								queue<string> qu1;
								qu1.push(P[i].name);
								int size = qu.size();
								for (int i = 0; !(qu.size() == 0) && i <= size; i++)
								{
									qu1.push(qu.front());
									qu.pop();
								}
								qu = qu1;
								P[i].num = 1;
							}
						}
						qu.push(tmp);

					}
					else
					{
						time += serive[j];
						P[j].fintime = time;
						P[j].flag = 1;
						qu.pop();

						for (int i = 0; i < W; i++)
						{
							if (P[i].num == 0 && P[j].arrtime <= time)
							{
								queue<string> qu1;
								for (int j = i; j < W; j++)
								{
									while (P[j].num == 0 && P[j].arrtime <= time && j < W)
									{
										qu1.push(P[j].name);
										P[j].num = 1;
										j++;
										for (int i = 0; qu.size() && i < qu.size(); i++)
										{
											qu1.push(qu.front());
										}
									}
									qu = qu1;
								}
							}


						}

						W--;
					}
				}
			}
		}


	}
}

void RRturn(process * P, int W)
{
	for (int j = 0; j < W; j++)
	{
		P[j].turntime = P[j].fintime - P[j].arrtime;
		P[j].Turntime = P[j].turntime / P[j].sertime;
	}
}

void FinPrint(process *P, int n) //��ӡ�����������ҵ���ʱ�䡣������
{
	double sumturntime = 0.0;//���н��̵���תʱ��
	double sumTurntime = 0.0;//���н��̵Ĵ�Ȩ��תʱ��
	for (int i = 0; i < n; i++)
	{
		sumturntime += P[i].turntime;
		sumTurntime += P[i].Turntime;
	}
	cout << "������" << "  " << "����ʱ��" << " " << "����ʱ��" << "  " << "���ʱ��" << "  " << "��תʱ��" << "  " << "��Ȩ��תʱ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << P->name << "\t" << P->arrtime << "\t" << "   " << P->sertime << "\t\t" << P->fintime << "\t" << P->turntime << "\t\t" << P->Turntime << endl;
		P++;
	}
	printf("��תʱ���ƽ��ֵ�� ��%f \n", (sumturntime / n));
	printf("��Ȩ��תʱ���ƽ��ֵ�� ��%f \n", (sumTurntime / n));

}
int main()
{

	//process P[5] = { { "A", 0.0, 4.0 }, { "B", 1.0, 3.0 }, { "C", 2.0, 4.0 }, { "D", 3.0, 2.0 }, { "E", 4.0, 4.0 } };

	//print(P);

	int n;//�����м�������
	cout << "��������̸���" << endl;
	cin >> n;
	process P[100];
	cout << "������������� ���̵���ʱ�� ���̷���ʱ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i].name >> P[i].arrtime >> P[i].sertime;
	}

	int num;
	cout << "1:�ȵ��ȷ���  2:����ҵ  3��ʱ��Ƭ��ת " << endl;
	cout << "������Ҫ���е��㷨ѡ��->";
	cin >> num;
	switch (num)
	{
	case 1:
		SortArrtime(P, n);
		FCFS(P, n);
		break;
	case 2:
		SSortSertime(P, n);
		SJF(P, n);
		break;
	case 3:
		SortArrtime(P, n);
		RR(P, n);
		RRturn(P, n);
		break;
	default:
		break;
	}
	//SortArrtime(P,n);
	//FCFS(P,n);
	FinPrint(P, n);

	/*SSortSertime(P,n);
	SJF(P,n);
	FinPrint(P,n);*/
	system("pause");
	return 0;
}