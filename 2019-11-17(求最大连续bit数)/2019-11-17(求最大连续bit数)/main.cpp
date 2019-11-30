#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class LCA {
public:
	int getLCA(int num) {
		int count = 0;
		int tmp = 0;
		for (int i = 0; i < 32; ++i) {
			if ((num >> i) & 1) {
				++tmp;
				continue;
			}
			else if (tmp > count) { 
				count = tmp;
				tmp = 0;
			}
			else {
				tmp = 0;
			}
		}
		if (tmp > count) {
			return tmp;
		}
		return count;
	}
};
int main() {
	LCA l;
	int num;
	while (cin >> num) {
		cout << l.getLCA(num) << endl;
	}
	system("pause");
	return 0;
}
