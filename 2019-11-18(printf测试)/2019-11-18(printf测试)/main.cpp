#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main() {
	int a; float b, c;
	scanf("%2d%3f%4f", &a, &b, &c);
	printf("\na=%d,b=%d,c=%.500f\n", a, b, c);
	system("pause");
	return 0;
}
