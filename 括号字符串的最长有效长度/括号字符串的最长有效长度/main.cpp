#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	static int fun(string& s) {
		int left = 0, right = 0, res = 0;
		for (auto c : s) {
			if (c == '(') {
				++left;
			}
			else if (c == ')') {
				++right;
				if (right == left) {
					if (left > res) res = left;
				}
				else if (right > left) {
					left = right = 0;
				}
			}
			else {
				left = right = 0;
			}
		}
		left = right = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == ')') {
				++right;
			}
			else if (s[i] == '(') {
				++left;
				if (right == left) {
					if (right > res) res = left;
				}
				else if (left > right) {
					left = right = 0;
				}
			}
			else {
				left = right = 0;
			}
		}
		return 2 * res;
	}
};

int main() {
	string str;
	while (cin >> str) {
		cout << Solution::fun(str) << endl;
		int Max = 0;
		vector<int>dp(str.size(), 0);
		for (int i = str.size() - 2; i >= 0; i--)
		{
			if (str[i] == '(')
			{
				int j = i + 1 + dp[i + 1];
				if (j < str.size() && str[j] == ')')
				{
					dp[i] += dp[i + 1] + 2;
					if (j + 1 < str.size())
						dp[i] += dp[j + 1];
				}
				if (Max < dp[i])
					Max = dp[i];
			}
		}
		cout << Max << endl;
	}
	return 0;
}