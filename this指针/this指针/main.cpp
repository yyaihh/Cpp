#include<iostream>
using namespace std;

class Test {
public:
	int* a;
	Test() {
		a = new int;
		*a = 10;
	}
	void test() {
		cout << typeid(this).name() << endl;
	}
	void test1(Test* const p){
		cout << &p << endl;
		cout << *a << endl;
	}
	void test2(Test* const p) {
		cout << &p << endl;
	}
	~Test() {
		delete a;
		a = nullptr;
	}
};
void test() {
	const int a = 10;
	cout << a << endl;
	*((int*)(&a)) = -10;
	cout << a << endl;

	volatile const int b = 10;
	cout << b << endl;
	*((int*)(&b)) = -10;
	cout << b << endl;
}
int main() {
	Test t;
	t.test();
	test();
	return 0;
}