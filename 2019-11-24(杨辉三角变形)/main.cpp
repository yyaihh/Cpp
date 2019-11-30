#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	static int func(int num) {
		int pos = 0;
		if (num < 3) {
			return -1;
		}
		if (num % 2 == 1) {
			return 2;
		}
		else {
			vector<int> vs1(num+1);
			vector<int> vs2(num+1);
			vs1[0] = 0;
			vs1[1] = vs1[2] = vs1[3] = 1;
			for (int i = 2; i < num; ++i) {
				vs2[1] = 1;
				for (int j = 2; j <= i+1; ++j) {
					vs2[j] = vs1[j - 1] + vs1[j - 2] + vs1[j];
				}
				vs1 = vs2;
			}
			for (int i = 2; i <= num; ++i) {
				if (vs2[i] % 2 == 0) {
					return i;
				}
			}
		}
		return -1;
	}
};
int main() {
	Solution l;
	int num;
	while (cin >> num) {
		cout << l.func(num) << endl;
	}
	system("pause");
	return 0;
}
