#include<iostream>
#include<string>
using namespace std;
class LCA {
	void Swap(int& a, int&b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
public:
	int getLCA1(int a, int b) {
		if (a < 1 || b < 1) {
			return 0;
		}
		int i;//a²ãÊý
		int j;//b²ãÊý
		int m, zu1, zu2;
		for (i = 0, m = 1; a < m || a >= 2 * m; ++i, m *= 2);
		for (j = 0, m = 1; b < m || b >= 2 * m; ++j, m *= 2);
		if (j < i) {
			Swap(i, j);
			Swap(a, b);
		}
		zu1 = a;
		zu2 = b;
		for (; j > i; --j) {
			if (zu2 % 2) {
				zu2 = (2 * zu2 - 1) / 4;
			}
			else {
				zu2 = (2 * zu2 + 1) / 4;
			}
			if (zu1 == zu2) {
				return zu1;
			}
		}
		while (zu1 != zu2) {
			if (zu1 % 2) {
				zu1 = (2 * zu1 - 1) / 4;
			}
			else {
				zu1 = (2 * zu1 + 1) / 4;
			}
			if (zu2 % 2) {
				zu2 = (2 * zu2 - 1) / 4;
			}
			else {
				zu2 = (2 * zu2 + 1) / 4;
			}
		}
		return zu1;
	}
	int getLCA2(int a, int b) {
		while (a != b) { 
			a > b ? a /= 2 : b /= 2;
		}
		return a;
	}
	int getLCA3(int a, int b) {
		int i, j, ancestor = 0;
		for (i = 31; !((a >> i) & 1); --i);
		for (j = 31; !((b >> j) & 1); --j);
		if (i == 0 || j == 0) return 1;
		for (; i >= 0 && j >= 0 && ((a >> i) & 1) == ((b >> j) & 1); --i, --j) {
			ancestor <<= 1;
			ancestor += ((a >> i) & 1);
		}
		char* p1 = (char*)&a;
		return ancestor;
	}
};
int main() {
	LCA l;
	int a, b;
	while (cin >> a >> b) {
		//cout << endl << l.getLCA1(a, b)<< endl;
		//cout << l.getLCA2(a, b) << endl;
		cout << l.getLCA3(a, b) << endl;
	}
	system("pause");
	return 0;
}
