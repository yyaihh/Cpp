#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string fun(string& s) {
		string res;
		string tmp;
		for (auto i : s) {
			if (i>= '0'&&i <= '9') {
				tmp += i;
			}
			else if(!tmp.empty()){
				if (tmp.size() > res.size()) {
					res = tmp;
				}
				tmp.clear();
			}
		}
		if (tmp.size() > res.size()) {
			res = tmp;
		}
		return res;
	}
};
int main() {
	string s;
	getline(cin, s, '\n');
	Solution f;
	cout << f.fun(s) << endl;
	system("pause");
	return 0;
}