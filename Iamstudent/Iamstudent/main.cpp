#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string fun(string& str) {
		string res;
		int left = str.size() - 1, count = 0;
		bool flag = false;
		for (int i = left; i >= 0; --i) {
			if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
				if (flag) {
					left = i + 1;
					res += str.substr(left, count);
					res += ' ';
					count = 0;
					flag = false;
				}
			}
			else {
				++count;
				flag = true;
				if(i == 0) res += str.substr(i, count);
			}
		}
		return res;
	}
};
int main() {
	string str;
	Solution s;
	while (getline(cin, str)) {
		cout << s.fun(str) << endl;
	}
	return 0;
}