#include<iostream>
#include<list>
#include<string>
using namespace std;
class Solution {
public:
	void fun(int num, string& s) {
		list<int> l(num);
		int n = 1;
		for (auto& i : l) {
			i = n++; 
		}
		int flag = 1;
		num >= 4 ? n = 4 : n = num;
		auto i = l.begin();
		for (auto&c : s) {
			if (c == 'U') {
				flag == 1 ? flag : --flag;
				i == l.begin() ? flag = n, i = --l.end() : --i;
			}
			else if (c == 'D') {
				flag == n ? flag : ++flag;
				i == --l.end() ? flag = 1, i = l.begin(): ++i;
			}
		}
		auto f = i;
		while (--flag) --i; 
		for (int j = 0; j < 4 && i != l.end(); ++j, ++i) { 
			cout << *i << ' ';
		}
		cout << endl << *f << endl;
	}
};
int main() {
	int num;
	string str;
	Solution s;
	while (cin >> num >> str) { 
		s.fun(num, str);
	}
	system("pause");
	return 0;
}