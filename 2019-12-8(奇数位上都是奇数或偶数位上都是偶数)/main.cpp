#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 */
	void oddInOddEvenInEven_(vector<int>& arr, int len) {
		for (int i = 0, j = 1; i < len&&j < len;) {
			if (arr[i] % 2 == 0) {//偶数位上是偶数
				i += 2;
				continue;
			}
			if (arr[j] % 2) {//奇数位上是奇数
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);//奇数位是偶数, 偶数位是奇数
		}
	}
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		int& end = arr[len - 1];
		while (i < len&&j < len) {
			if (end % 2 == 0) {
				swap(arr[i], end);
				i += 2;
			}
			else {
				swap(arr[j], end);
				j += 2;
			}
		}
	}
};
int main() {
	Solution s;
	int n;
	vector<int> v;
	while (cin >> n) {
		v.resize(n);
		for (auto& i : v) {
			cin >> i;
		}
		s.oddInOddEvenInEven(v, n);
		for (auto& i : v) {
			cout << i << ' ';
		}
	}
}