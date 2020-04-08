#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution_(int n, int m) {
		if (n < 1) return -1;
		list<int> l(n);
		int k = 0;
		for (auto& e : l) {
			e = k++;
		}
		auto i = l.begin();
		while (l.size() > 1) {
			for (k = 1; k < m; ++k) {
				++i;
				if (i == l.end()) i = l.begin();
			}
			i = l.erase(i);
			if (i == l.end()) i = l.begin();
		}
		return *i;
	}
	int LastRemaining_Solution(int n, int m) {
		if (n < 1) return -1;
		vector<int> v(n, 0);
		int i, k, count = n;
		for (i = 0, k = 1; count > 1; i = (++i) % n) {
			if (v[i] == -1) continue;
			if (k == m) {
				v[i] = -1;
				--count;
			}
			k = k % m + 1;
		}
		for (int i = 0; i < n; ++i) {
			if (v[i] == 0) {
				return i;
			}
		}
		return -1;
	}
};

int main() {
	int n, m;
	Solution s;
	while (cin >> n >> m) {
		cout << s.LastRemaining_Solution(n, m) << endl;
	}
	return 0;
}