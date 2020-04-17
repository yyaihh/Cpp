#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

class Solution {
	long long dpmax[11][51];
	long long dpmin[11][51];
public:
	long long fun(vector<int>& v, int k, int d) {
		memset(dpmax, 0, sizeof(dpmax));
		memset(dpmin, 0, sizeof(dpmin));
		long long res = 1LL << 63;
		for (int i = 1, size = v.size(); i < size; ++i) {//第一个成绩, v[i]
			dpmax[1][i] = dpmin[1][i] = v[i];
			for (int j = 2; j <= k; ++j) {//剩余的k-1个, 从[2, k]
				for (int r = i - 1; r > 0 && i - r <= d; --r) {
					dpmax[j][i] = max(dpmax[j][i], max(dpmax[j - 1][r] * v[i], dpmin[j - 1][r] * v[i]));
					dpmin[j][i] = min(dpmin[j][i], min(dpmax[j - 1][r] * v[i], dpmin[j - 1][r] * v[i]));
				}
			}
			res = max(res, dpmax[k][i]);
		}
		return res;
	}
};
int main() {
	Solution s;
	int n, k, d;
	while (cin >> n) {
		vector<int> v(n + 1);
		for (int i = 1; i <= n; ++i) {
			cin >> v[i];
		}
		cin >> k >> d;
		cout << s.fun(v, k, d) << endl;
	}
	return 0;
}