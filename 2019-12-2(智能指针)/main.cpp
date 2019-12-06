#include<iostream>
#include"Smart_Ptr.h"
using namespace std;
class A {
public:
	int m_data;
	~A() {
		cout << "Îö¹¹\n";
	}
};
A* test() {
	A* p = new A;
	Smart_Ptr<A> sp(p);
	(*sp).m_data = 10;
	cout << (*sp).m_data << endl;
	cout << sp.operator->()->m_data << endl;
	cout << sp->m_data << endl;
	sp->m_data = 20;
	cout << (*sp).m_data << endl;
	cout << sp.operator->()->m_data << endl;
	cout << sp->m_data << endl;
	return sp.get();
}
int main4() {
	A* p = test();
	cout << p->m_data << endl;
	system("pause");
	return 0;
}