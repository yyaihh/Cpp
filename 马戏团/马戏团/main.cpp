#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct body {
	int id, height, weight;
};
struct Cmp {
	bool operator()(body& b1, body& b2) {
		if (b1.weight == b2.weight) {
			return b1.height > b2.height;
		}
		return b1.weight < b2.weight;
	}
};
class Solution {
public:
	static int fun(vector<body>& v) {
		int res = 0, n = v.size(), tmp = 0;
		sort(v.begin(), v.end(), Cmp());
		vector<int> dp(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (v[i].height >= v[j].height) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (dp[i] > res) res = dp[i];
		}
		return res;
	}
};
int main() {
	int N;
	while (cin >> N) {
		vector<body> v(N);
		for (auto& i : v) {
			cin >> i.id >> i.weight >> i.height;
		}
		cout << Solution::fun(v) << endl;
	}

	return 0;
}