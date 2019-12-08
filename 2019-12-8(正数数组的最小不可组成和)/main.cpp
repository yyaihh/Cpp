#include<iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
	/**
	*  正数数组中的最小不可组成和
	*  输入：正数数组arr
	*  返回：正数数组中的最小不可组成和
	*/
	int getFirstUnFormedNum(vector<int> arr, int len) {
		set<int> S;
		vector<int> tmp;
		int min = INT_MAX;
		for (auto& cur : arr) {
			if (cur < min) {
				min = cur;
			}
			for (auto& i : S) {
				tmp.push_back(i + cur);
			}
			S.insert(tmp.begin(), tmp.end());
			S.insert(cur);
			tmp.clear();
		}
		for (int i = min; ; ++i) {
			/*if (S.find(i) == S.end()) {
				return i;
			}*/
			if ((S.insert(i)).second) {
				return i;
			}
		}
		return -1;
	}
};
int main() {
	vector<int> v;
	int n;
	Solution s;
	while (cin >> n) {
		v.resize(n);
		for (auto& i : v) {
			cin >> i;
		}
		cout << s.getFirstUnFormedNum(v, n) << endl;
	}
	system("pause");
	return 0;
}