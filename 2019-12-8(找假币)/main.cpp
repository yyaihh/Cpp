// write your code here cpp
#include<iostream>
using namespace std;
int main() {
	long n;
	int count;
	while (cin >> n) {
		if (n == 0)break;
		count = 0;
		for (long i = 1; i < n; i *= 3, ++count);
		cout << count << endl;
	}
	return 0;
}