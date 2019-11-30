#include<iostream>
using namespace std;
class A {
public:
	void fun() {
		cout << "A::void fun()\n";
	}
	int fun(int a) {
		cout << "A::void fun(int)\n";
		return 0;
	}
};
char fun(char a, int b) {
	cout << "char fun(char, int)\n";
	return 0;
}
char fun(int a, char b) {
	cout << "char fun(int, char)\n";
	return 0;
}
class B {
public:
	
};
int main() {
	A a;
	a.fun();
	a.fun(1);
	fun('a', 10);
	fun(10, 'a');
	system("pause");
	return 0;
}