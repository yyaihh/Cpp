#include<iostream>
using namespace std;
class A {
public:
	int m_a;
};
class B {
public:
	A m_A;
	int m_b;
};
class C {
public:
	B m_B;
	int m_c;
};
int main_() {
	C c;
	c.m_B.m_A.m_a = 10;
	c.m_B.m_b = 20;
	c.m_c = 30;
	system("pause");
	return 0;
}
