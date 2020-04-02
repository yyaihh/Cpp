#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int>>& m) {
		vector<int> res;
		int size1 = m.size();
		int size2 = m[0].size();
		int left = 0, right = size2, up = 0, down = size1;
		while (left < right && up < down) {
			res.insert(res.end(), m[up].begin() + left, m[up].begin() + right);//×óµ½ÓÒ
			++up;

			if (up == down) break;
			for (int i = up; i < down; ++i) {
				res.push_back(m[i][right - 1]);
			}
			--right;

			if (left == right) break;
			res.insert(res.end(), m[down - 1].rbegin() + size2 - right, m[down - 1].rbegin() + size2 - left);//×óµ½ÓÒ
			--down;

			if (up == down) break;
			for (int i = down - 1; i >= up; --i) {
				res.push_back(m[i][left]);
			}
			++left;
		}
		return res;
	}
};


int main() {
	Solution s;
	vector<int> v = { 1, 2, 3, 4 ,5 ,6 };
	vector<vector<int>> vv = { {1, 2}, {3, 4} };
	for (auto& i : s.printMatrix(vv)) {
		cout << i  << ' ';
	}
	return 0;
}