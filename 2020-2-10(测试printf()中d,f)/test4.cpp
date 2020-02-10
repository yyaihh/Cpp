#include<iostream>
struct Test{
	Test(int) {}
	Test() {}
	void fun() {}
};
void main(void){
	Test a(1);
	a.fun();
	Test b = *(new Test ());
	b.fun();
}