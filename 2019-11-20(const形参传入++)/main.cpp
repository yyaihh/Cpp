#include<iostream>
using namespace std;
void fun(const int& a, const int& b) {
	cout << a << " "<< b;
}
int main(){
	int i = 0;
	fun((++i)++, ++i);
	return 0;
}