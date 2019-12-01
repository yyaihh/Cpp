#include<iostream>
#include<vector>
using namespace std;
class Solution {
	int f(int x, int y) {
		int z;
		while (z = x % y) {
			x = y;
			y = z;
		}
		return y;
	}
public:
	vector<int> fun(vector<pair<int, vector<int>>>& vv) {
		int n = 0;
		vector<int> res(vv.size());
		for (auto& j : vv) {
			int& c = res[n++];
			c = j.first;
			for (auto& i : j.second) {
				if (i <= c) {
					c += i;
				}
				else {
					c += f(c, i);
				}
			}
		}
		return res;
	}
};
int main() {
	int a, c;

	vector<pair<int,vector<int>>> vv;
	pair<int, vector<int>> tmp;
	Solution s;
	int n = 5;
	//while (n--)getchar();
	while (cin >> a >> c) {
		tmp.second.resize(a);
		tmp.first = c;
		for (int i = 0; i < a; cin >> tmp.second[i++]);
		vv.push_back(tmp);
		tmp.second.clear();
	}
	for (auto& i : s.fun(vv)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}