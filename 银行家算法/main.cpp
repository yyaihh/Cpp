#include"Banker.h"
int main() {
	int n;
	Banker b;
	cout << "1.输入数据 2.银行家算法 3.安全性算法\n";
	while (cin >> n) {
		if (n == 1) {
			b.input();
			b.print();
		}
		else if (n == 2) {
			b.Banker_Algorithm();
		}
		else if (n == 3) {
			b.Safe_Algorithm();
		}
		else {
			cout << "没有这个选项, 请重新输入\n";
		}
		cout << "1.输入数据 2.银行家算法 3.安全性算法\n";
	}
	return 0;
}
