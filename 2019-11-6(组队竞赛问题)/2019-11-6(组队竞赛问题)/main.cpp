#include<iostream>
using namespace std;
#include<vector>
int cmp(const void * a, const void * b) {
	return *((int*)a) - *((int*)b);
}
class Solution {
public:
	int func(int* x, int n) {
		int m = 3 * n;
		qsort(x, m, 4, cmp);
		int count = 0;
		for (int i = m - 2; n; i -= 2, --n) {
			count += x[i];
		}
		return count;
	}
};
int main() {
	int n;
	cin >> n;
	int* v = new int[3 * n];
	for (int i = 0, m = 3 * n, a_i; i < m; ++i) {
		cin >> a_i;
		v[i] = a_i;
	}
	Solution f;
	cout << f.func(v, n) << endl;
	system("pause");
	return 0;
}