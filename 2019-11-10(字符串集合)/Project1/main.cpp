#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string fun(string& s) {
		vector<int>tmp1;
		vector<int>tmp2;
		string res;
		tmp1.resize(26, 0);
		tmp2.resize(26, 0);
		for (auto i : s) {
			if (i >= 'a'&&i <= 'z') {
				if (tmp1[i - 'a']++ == 0) {
					res += i;
				}
			}
			else {
				if (tmp2[i - 'A']++ == 0) {
					res += i;
				}
			}
		}
		return res;
	}
};
int main() {
	string s;
	Solution f;
	while (cin >> s) {
		cout << f.fun(s);
	}
	system("pause");
	return 0;
}
