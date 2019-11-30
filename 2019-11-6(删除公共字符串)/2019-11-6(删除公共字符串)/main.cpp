#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
	string func(string& s1, string& s2) {
		string res;
		auto end1 = s1.end();
		auto end2 = s2.end();
		bool flag;
		for (auto i = s1.begin(); i != end1; ++i) {
			flag = true;
			for (auto j = s2.begin(); j != end2; ++j) {
				if (*i == *j) {
					flag = false;
					break;
				}
			}
			if (flag) {
				res += *i;
			}

		}
		return res;
	}
};
int main() {
	string str1;
	string str2;
	char c;
	c = getchar();
	while (c != '\n') {
		str1 += c;
		c = getchar();
	}
	c = getchar();
	while (c != '\n') {
		str2 += c;
		c = getchar();
	}
	Solution f;
	string str3 = f.func(str1, str2);
	cout << str3 << endl;
	system("pause");
	return 0;
}