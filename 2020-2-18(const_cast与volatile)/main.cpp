#include<iostream>
using namespace std;
const int qa = 10;
void test1() {
	const int a = 10;
	int* p = const_cast<int*>(&a);
	*p = 0;
	cout << a << endl;
	cout << *p << endl << endl;

	const int b = 10;
	int* p2 = (int*)(&a);
	*p2 = 0;
	cout << b << endl;
	cout << *p2 << endl << endl;

	volatile const int c = 10;
	int* p3 = const_cast<int*>(&c);
	*p3 = 0;
	cout << c << endl;
	cout << *p3 << endl << endl;

	volatile const int d = 10;
	int* p4 = (int*)(&d);
	*p4 = 0;
	cout << c << endl;
	cout << *p4 << endl;
}
void test2() {
	int* p = const_cast<int*>(&qa);
	*p = 0;
	cout << qa << endl;
	cout << *p << endl << endl;

	int* p2 = (int*)(&qa);
	*p2 = 2;
	cout << qa << endl;
	cout << *p2 << endl << endl;
}
void test3() {
	static const int qa = 10;
	int* p = const_cast<int*>(&qa);
	*p = 0;
	cout << qa << endl;
	cout << *p << endl << endl;

	int* p2 = (int*)(&qa);
	*p2 = 2;
	cout << qa << endl;
	cout << *p2 << endl << endl;
}
int main() {
	//test2();
	test3();
	return 0;
}
