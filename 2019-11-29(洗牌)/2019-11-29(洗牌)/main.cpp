#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> fun(vector<pair<int, vector<int>>>& vv) {
		vector<vector<int>> res;
		vector<int> tmp;
		int size = 0;
		for (auto& i : vv) {
			size = i.second.size();
			tmp.reserve(size);
			while (i.first--) {
				for (int j = size / 2 - 1, k = size -1; j >= 0; --j, --k) {
					tmp.push_back(i.second[k]);
					tmp.push_back(i.second[j]);
				}
				vector<int> t(tmp.rbegin(), tmp.rend());
				i.second = t;
				tmp.clear();
			}
			res.push_back(i.second);
		}
		return res;
	}
};
int main() {
	int T;
	cin >> T;
	vector<pair<int,vector<int>>> vv(T);
	int n, k;
	for (auto& i : vv) {
		cin >> n >> k;;
		i.first = k;
		i.second.resize(2 * n);
		for (int j = 0; j < 2 * n; ++j) {
			cin >> i.second[j];
		}
	}
	Solution s;
	vector<vector<int>> vf= s.fun(vv);
	int size;
	for (auto j : vf) {
		size = j.size();
		for (int i = 0; i < size; ++i) {
			cout << j[i];
			if (i + 1 != size) {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}