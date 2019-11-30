#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	long long fun1(int n, int m) {
		vector<vector<long long> > v;
		v.resize(n + 1, vector<long long>(m + 1));
		for (int i = 1; i < m + 1; ++i) {
			v[0][i] = 1;
		}
		for (int i = 1; i < n + 1; ++i) {
			v[i][0] = 1;
		}
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[n][m];
	}
	long long fun2(int n, int m) {
		vector<long long> v;
		v.resize(m + 1, 1);
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				v[j] += v[j - 1];
			}
		}
		return v[m];
	}
	long long fun3(int n, int m) {
		vector<long long> v;
		v.resize(m + 1, 1);
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < m + 1; ++j) {
				v[j] += v[j - 1];
			}
		}
		return v[m];
	}
	long long fun4(int n, int m) {
		if (n == 0 || m == 0) {
			return 1;
		}
		return fun4(n - 1, m) + fun4(n, m - 1);
	}
};
int main() {
	int n, m;
	Solution f;
	while (cin >> n >> m) {
		cout << f.fun2(n, m) << endl;
		cout << f.fun4(n, m) << endl;
	}
	system("pause");
	return 0;
}
