#include<iostream>
using namespace std;
class Solution {
public:
	bool func(long double a, long double b) {
		return a - 2 * 3.14*b < 0;
	}
};
int main() {
	Solution s;
	long double a, b;
	while (cin >> a >> b) {
		s.func(a, b) ? cout << "Yes\n" : cout << "No\n";
	}
	system("pause");
	return 0;
}