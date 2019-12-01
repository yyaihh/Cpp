#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	char fun(string& s) {
		pair<int, int> count[255] = { pair<int,int>(0,0) };
		int n = 0;
		for (auto& i : s) {
			if (count[i].first == 0) {
				count[i].first = ++n;
			}
			count[i].second += 1;
		}
		int tmp = 255;
		int tmp2 = 255;
		for (int i = 0; i < 255; ++i) {
			if (count[i].second == 1) {
				if (count[i].first < tmp) {
					tmp = count[i].first;
					tmp2 = i;
				}
			}
		}
		if (tmp2 < 255) { 
			return (char)tmp2;
		}
		return -1;
	}
};
int main() {
	string s;
	Solution f;
	char c;
	while (cin >> s) {
		c = f.fun(s);
		if (c == char(-1)) {
			cout << -1 << endl;
		}
		else {
			cout << c << endl;
		}
	}
	system("pause");
	return 0;
}