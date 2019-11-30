#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	static bool func(string& s1, string& s2) {
		for (auto i = s1.begin(); i != s1.end(); ++i) {
			if (*i >= 'A'&&*i <= 'Z') {
				*i = ('a' + *i - 'A');
			}
			if (*i == '?' && i > s1.begin() && *(i - 1) == '*') { 
				i = s1.erase(i);
			}
		}
		for (auto& i : s2) {
			if (i >= 'A'&&i <= 'Z') {
				i = 'a' + i - 'A';
			}
		}
		int size1 = s1.size();
		int size2 = s2.size();
		int i, j;
		for (i = 0, j = 0; i < size1&&j < size2; ++j) {
			char& c1 = s1[i];
			char& c2 = s2[j];
			if (c1 == '*') {
				int pos,tmp;
				if (i < size1) {
					pos = s1.find('*', i + 1);
					tmp = s1.find('?', i + 1);
					if (pos == string::npos) {
						pos = size1 - 1;
					}
					if (tmp == string::npos) {
						tmp = size1 - 1;
					}
					pos < tmp ? pos : pos = tmp;
				}
				else {
					return false;
				}
				if (pos == size1 - 1) {
					return true;
				}
				string s = s1.substr(i + 1, pos - i - 1);
				j = s2.find(s, j);
				if (j == string::npos) {
					return false;
				}
				j += pos - i - 2;
				i = pos;
			}
			else if (c1 == '?' || c1 == c2) {
				++i;
			}
			else {
				return false;
			}
		}
		if (i < size1 || j < size2) {
			return false;
		}
		return true;
	}
};
int main() {
	string s1, s2;
	while (getline(cin, s1) && getline(cin, s2)) { 
		Solution::func(s1, s2) ? cout << "true\n" : cout << "false\n";
	}
	system("pause");
	return 0;
}