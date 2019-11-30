#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class LCA {
public:
	static int findNumberOf1(int num) {
		int count = 0;
		for (int i = 0; i < 32; ++i) {
			if ((num >> i) & 1) {
				++count;
			}
			
		}
		return count;
	}
};
int main() {
	int num;
	while (cin >> num) {
		cout << LCA::findNumberOf1(num) << endl;
	}
	system("pause");
	return 0;
}
