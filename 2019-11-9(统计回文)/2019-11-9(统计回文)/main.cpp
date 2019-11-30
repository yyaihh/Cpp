#include<iostream>
#include<string>
using namespace std;

class Solution {
	bool f(string& s, int size) {
		for (int i = 0, j = size - 1; i < j; ++i, --j) {
			if (s[i] != s[j]) {
				return false;
			}
		}
		return true;
	}
public:
	int fun(string& s1, string& s2) {
		string tmp;
		int count = 0;
		int size = s1.size();
		int size2 = size + s2.size();
		tmp.resize(size2);
		auto end = s1.end();
		for (int i = 0; i <= size; ++i) { 
			tmp = s1;
			tmp.insert(tmp.begin() + i, s2.begin(), s2.end());
			if (f(tmp, size2)) { 
				++count;
			}
		}
		return count;
	}
};
int main() {
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	Solution f;
	cout << f.fun(str1, str2);
	system("pause");
	return 0;
}