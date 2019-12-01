#include<iostream>
#include"Smart_Ptr.h"
using namespace std;
int* fun() {
	int* arr = new int[100];
	Smart_Ptr<int> sp = arr;
	arr[0] = 10;
	cout << arr[0] << endl;
	return arr;
}
int main() {
	int* p = fun();
	cout << p[0] << endl;
	int* p2 = new int;
	*p2 = 10;
	delete p2;
	*p2 = 100;
	system("pause");
	return 0;
}