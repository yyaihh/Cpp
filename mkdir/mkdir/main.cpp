// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> fun(vector<string>& data) {
		vector<string> res;
		sort(data.begin(), data.end());
		for (int i = 0, size = data.size() - 1; i < size; ++i) {
			if ((data[i + 1] + '/').find(data[i] + '/') == string::npos) {
				res.push_back(data[i]);
			}
		}
		res.push_back(data[data.size() - 1]);
		return res;
	}
};

int main() {
	int n;
	Solution s;
	while (cin >> n) {
		vector<string> data(n);
		for (auto& s : data) {
			cin >> s;
		}
		for (auto& s : s.fun(data)) {
			cout << "mkdir -p " << s << endl;
		}
		cout << endl;
	}
	return 0;
}