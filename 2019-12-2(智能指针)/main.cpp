#include<iostream>
#include"Smart_Ptr.h"
using namespace std;
class A {
public:
	int m_data;
};
int main1() {
	Smart_Ptr<A> p(new A);
	(*p).m_data = 10;
	cout << (*p).m_data << endl;
	cout << p.operator->()->m_data << endl;
	cout << p->m_data << endl;
	p->m_data = 20;
	cout << (*p).m_data << endl;
	cout << p.operator->()->m_data << endl;
	cout << p->m_data << endl;
	p.~Smart_Ptr();
	cout << p->m_data << endl;
	system("pause");
	return 0;
}