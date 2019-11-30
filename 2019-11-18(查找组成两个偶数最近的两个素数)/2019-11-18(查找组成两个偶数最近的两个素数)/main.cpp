#include<iostream>
using namespace std;
class BinInsert {
	bool f(int num) {
		double m = sqrt(num);;
		for (int j = 2; j <= m; j++)
			if (num%j == 0)
				return false;
		return true;
	}
public:
	pair<int, int> fun(int num) {
		int n = num / 2;
		int min = num;
		int flag;
		for (int i = num - 1; i >= n; --i) { 
			if (f(i) && f(num - i)) {
				if (i - num + i < min) {
					flag = i;
					min = i - num + i;
				}
			}
		}
		return pair<int, int>(num - flag, flag);
	}
};
int main() {
	int num;
	BinInsert b;
	pair<int, int> p;
	while (cin >> num) {
		p = b.fun(num);
		cout << p.first << endl;
		cout << p.second << endl;
	}
	system("pause");
	return 0;
}
