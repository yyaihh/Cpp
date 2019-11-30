#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int fun(int* arr) {
		int count = 0;
		int m, i, tmp;
		for (i = 0; i < 10; ++i) { 
			if (arr[i] < 1) {
				break;
			}
			count = 0;
			for (m = arr[i]; m > 2;) {
				tmp = m / 3;
				count += tmp;
				m += tmp;
				m -= tmp * 3;
			}
			arr[i] = count + (m == 2);
		}
		return i;
	}
};
int main() {
	int* arr = new int[10];
	char tmp;
	Solution s;
	int i = 0;
	while (cin >> arr[i++]) {
		if (arr[i - 1] == 0) {
			break;
		}
	}
	i = s.fun(arr);
	for (int j = 0; j < i; ++j) {
		cout << arr[j] << endl;
	}
	delete[] arr;
	system("pause");
	return 0;
}