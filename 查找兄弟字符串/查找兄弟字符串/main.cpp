#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
using namespace std;

class Solution {
public:
	string fun(vector<string>& vs, string& str, int& n) {
		vector<string> res;
		int size = str.size();
		string s1 = str;
		sort(s1.begin(), s1.end());
		for (auto& s : vs) {
			if (s.size() == size && s != str) {
				string tmp = s;
				sort(tmp.begin(), tmp.end());
				if (tmp == s1) res.push_back(s);
			}
		}
		int t = n - 1;
		n = res.size();
		if (n == 0) return string();
		sort(res.begin(), res.end());
		return res[t];
	}
};

int main() {
	Solution s;
	int n;
	while (cin >> n) {
		vector<string> vs(n);
		string str;
		for (auto& s : vs) {
			cin >> s;
		}
		cin >> str >> n;
		string res = s.fun(vs, str, n);
		cout << n << endl;
		if (res != "") cout << res << endl;
	}
	return 0;
}