#include<iostream>
using namespace std;
class A {
public:
	int m_a = 0;
	~A() {
		cout << "µ÷ÓÃÎö¹¹\n";
	}
};
int main() {
	A* p = new A;
	p->m_a = 10;
	*(int*)(p - 1) = 10;
	delete[] p;
	system("pause");
	return 0;
}
