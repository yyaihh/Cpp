#include<iostream>
using namespace std;
class Solution {
public:
	static int count(int num) {
		int count = 0;
		int size, tmp1, tmp2;
		for (int i = 2; i <= num; ++i) {
			size = (int)sqrt(i);
			tmp2 = 1;
			for (int j = 2; j <= size; ++j) {
				tmp1 = i % j;
				if (tmp1 == 0) {
					if (j*j == i) {
						tmp2 += j;
					}
					else {
						tmp2 += (j + i / j);
					}
				}
				if (tmp2 > i) {
					break;
				}
			}
			if (tmp2 == i) {
				count++;
				cout << i << endl;
			}
		}
		if (count == 0) {
			return -1;
		}
		return count;
	}
};
int main() {
	Solution l;
	int num;
	cin >> num;
	cout << l.count(num) << endl;
	system("pause");
	return 0;
}
