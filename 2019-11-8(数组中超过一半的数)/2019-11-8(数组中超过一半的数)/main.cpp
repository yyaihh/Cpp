#include<iostream>
#include<vector>
using namespace std;
int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		int size = numbers.size();
		qsort(&numbers[0], size, 4, cmp);
		int num = numbers[size / 2];
		int count = 0;
		for (auto i : numbers) {
			if (i == num) {
				++count;
			}
		}
		if (count > size / 2) {
			return num;
		}
		return 0;
	}
};
int main() {
	vector<int> a;
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	Solution f;
	cout << f.MoreThanHalfNum_Solution(a) << endl;
	system("pause");
	return 0;
}