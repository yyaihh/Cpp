#include"Banker.h"
int main() {
	int n;
	Banker b;
	cout << "1.�������� 2.���м��㷨 3.��ȫ���㷨\n";
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
			cout << "û�����ѡ��, ����������\n";
		}
		cout << "1.�������� 2.���м��㷨 3.��ȫ���㷨\n";
	}
	return 0;
}
