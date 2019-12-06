#pragma once
#include<iostream>
#include<memory>
#include"Shared_ptr.h"
using namespace std;
class A {
public:
	int m_data;
	~A() {
		cout << "Îö¹¹\n";
	}
};
void test2() {
	shared_ptr<A> hp1(new A);
	shared_ptr<A> hp2(hp1);
	shared_ptr<A> hp3 = hp2;
	hp3->m_data = 10;
	cout << hp1->m_data << endl;
	cout << hp2->m_data << endl;
	cout << hp3->m_data << endl;
}
void test3() {
	Shared_ptr<A> hp1(new A);
	Shared_ptr<A> hp2(hp1);
	Shared_ptr<A> hp3 = hp2;
	hp3->m_data = 10;
	cout << hp1->m_data << endl;
	cout << hp2->m_data << endl;
	cout << hp3->m_data << endl;
}
int main5() {
	//test2();
	test3();
	system("pause");
	return 0;
}