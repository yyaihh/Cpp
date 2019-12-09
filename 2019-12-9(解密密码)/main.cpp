// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	void fun(string& s) {
		for (auto& i : s) {
			if (i == ' ')continue;
			i > 'E' ? i -= 5 : i += 21;
		}
	}
};
int main() {
	string str;
	Solution s;
	while (getline(cin, str)) {
		s.fun(str);
		cout << str << endl;
	}
	return 0;
}