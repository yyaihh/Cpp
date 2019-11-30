#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string& str) {
		if (str.empty()) {
			return 0;
		}
		int flag = 1;//Õý¸º±êÇ©
		auto i = str.begin();
		if (*i == '-') {
			flag = -1;
			++i;
		}
		else if (*i == '+') {
			++i;
		}
		long long tmp = 0;
		double max = pow(2, 31) - 1;
		double min = -pow(2, 31);
		auto end = str.end();
		for (; i < end; ++i) {
			if (*i > '9' || *i < '0') {
				return 0;
			}
			tmp = (int)*i - 48 + tmp * 10;
		}
		tmp = flag * tmp;
		if (tmp < min) {
			return 0;
		}
		if (tmp > max) {
			return 0;
		}
		return (int)tmp;
	}
};
int main() {
	string str;
	cin >> str;
	Solution f;
	cout << f.StrToInt(str);
	system("pause");
	return 0;
}