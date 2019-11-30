#include<iostream>
using namespace std;
class Solution {
	int f(int x, int y) {
		int z;
		while (z = x % y)
		{
			x = y;
			y = z;
		}
		return y;
	}
public:
	int fun(int x, int y) {
		return x * y / f(x, y);
	}

};
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	Solution f;
	cout << f.fun(num1, num2);
	system("pause");
	return 0;
}