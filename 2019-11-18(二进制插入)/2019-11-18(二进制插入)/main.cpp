#include<iostream>
#include<string>
using namespace std;
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		for (int k = j; k <= i; ++k) {
			n |= (m&(1 << k));
		}
		return n;
	}
};
int main() {
	BinInsert b;
	int m, n, i, j;
	while (cin >> n >> m >> j >> i) { 
		cout << b.binInsert(n, m, j, i) << endl;
	}
	system("pause");
	return 0;
}
