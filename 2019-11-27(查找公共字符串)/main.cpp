#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	static string fun(string& s1, string& s2) {
		string res;
		if (s1.size() < s2.size()) {
			string tmp = s1;
			s1 = s2;
			s2 = tmp;
		}
		int size1 = s1.size();
		int size2 = s2.size();
		int left = 0, len = 0, k = 0;
		for (int j = 0; j < size2&&size2-j>k; ++j) {
			for (k = 1; j + k < size2 && s1.find(s2.substr(j, k), 0) != string::npos; ++k) {
				if (k > len) {
					len = k;
					left = j;
				}
			}
			if (k == len + 1 &&k + j == size2&& s1.find(s2.substr(j, k), 0) != string::npos) {
				++len;
			}
		}
		res = s2.substr(left, len);
		return res;
	}
};
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << Solution::fun(s1, s2) << endl;
	}
	system("pause");
	return 0;
}