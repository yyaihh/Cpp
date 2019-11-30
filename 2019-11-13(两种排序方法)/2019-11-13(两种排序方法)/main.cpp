#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string fun(vector<string>& vs) {
		int size = vs.size();
		if (size == 1) {
			return "both";
		}
		bool length = true;
		bool lexicographically = true;
		for (auto i = 0; i < size - 1 && (lexicographically || length); ++i) {
			if (length && vs[i].size() > vs[i + 1].size()) {
				length = false;
			}
			if (lexicographically && vs[i] > vs[i + 1]) {
				lexicographically = false;
			}
		}
		if (!lexicographically && !length) {
			return "none";
		}
		if (lexicographically&&length) {
			return "both";
		}
		if (lexicographically) {
			return "lexicographically";
		}
		return "lengths";
	}
};
int main() {
	vector<string>vs;
	int n;
	cin >> n;
	vs.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> vs[i];
	}
	Solution f;
	cout << f.fun(vs);
	system("pause");
	return 0;
}