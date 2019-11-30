//#include<stdio.h>
//int main() {
//	int arr[10];
//	int a = 10;
//	const int* p1;
//	const int* p2;
//	//可以在定义时初始化
//	//如const int* p1 = arr; 
//	//const int* p2 = &a;
//	p1 = arr;
//	p2 = &a;
//
//	*p1 = 10;
//	*(p1 + 1) = 10;
//	p1[0] = 10;
//	p1[1] = 10;
//
//	*p2 = 20;
//
//	p1 = &a;
//	p2 = arr;
//	return 0;
//}
//#include<stdio.h>
//int main() {
//	int arr[10];
//	int a = 10;
//	int const * p1;
//	int const * p2;
//	//可以在定义时初始化
//	//如const int* p1 = arr; 
//	//const int* p2 = &a;
//	p1 = arr;
//	p2 = &a;
//
//	*p1 = 10;
//	*(p1 + 1) = 10;
//	p1[0] = 10;
//	p1[1] = 10;
//
//	*p2 = 20;
//
//	p1 = &a;
//	p2 = arr;
//	return 0;
//}
#include<stdio.h>
int main() {
	int arr[10];
	int a = 10;
	const int * const p = &a;
	int* const p1 = arr;
	int* const p2 = &a;
	int* const p3;
	int* const p4;
	p3 = arr;
	p4 = &a;

	*p1 = 10;
	*(p1 + 1) = 10;
	p1[0] = 10;
	p1[1] = 10;

	*p2 = 20;

	p1 = &a;
	p2 = arr;
	return 0;
}