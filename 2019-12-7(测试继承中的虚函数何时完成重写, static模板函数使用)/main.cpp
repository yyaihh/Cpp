#include<iostream>
using namespace std;
class A {
	int a = 0;
public:
	A(int v = 0) :a(v) {
		test();
	}
	void test() {
		fun();
	}
	virtual void fun() {
		cout << 1 << endl;
	}
};
class B : public A{
public:
	B() {
		test();
	}
	virtual void fun() {
		cout << 2 << endl;
	}
};
int main() {
	new B;
	system("pause");
	return 0;
}