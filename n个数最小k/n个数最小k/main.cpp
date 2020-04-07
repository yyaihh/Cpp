#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> fun(vector<int> input, int k) {
		if (input.size() < k) {
			return vector<int>(0);
		}
		sort(input.begin(), input.end());
		input.resize(k);
		return input;
	}
};

int main() {
	int k = 4;
	vector<int> v = {5,6,4,3,2,1};
	Solution s;
	for (auto e : s.fun(v, k)) {
		cout << e << ' ';
	}
	return 0;
}