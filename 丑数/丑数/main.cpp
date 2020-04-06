#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7) {
			return index;
		}
		vector<int> arr(index);
		int i = 0, i2 = 0, i3 = 0, i5 = 0, tmp2, tmp3, tmp5;
		arr[i] = 1;
		for (i = 1; i < index; ++i) {
			tmp2 = arr[i2] * 2;
			tmp3 = arr[i3] * 3;
			tmp5 = arr[i5] * 5;
			arr[i] = min(tmp2, min(tmp3, tmp5));
			if (arr[i] == tmp2) ++i2;
			if (arr[i] == tmp3) ++i3;
			if (arr[i] == tmp5) ++i5;
		}
		return arr[index - 1];
	}
}; 
int main() {
	Solution s;
	int n;
	while (cin >> n) {
		cout << s.GetUglyNumber_Solution(n) << endl;
	}
	return 0;
}