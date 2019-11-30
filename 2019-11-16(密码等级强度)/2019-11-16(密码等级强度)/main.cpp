#include<iostream>
#include<string>
using namespace std;
class Solution {
	int f(string& s) {
		int sum = 0;
		int count[4] = { 0 };
		int size = s.size();
		if (size <= 4) {
			sum = 5;
		}
		else if (size > 4 && size < 8) {
			sum = 10;
		}
		else {
			sum = 25;
		}
		for (auto& i : s) {
			if (i >= 'a'&&i <= 'z') {
				++count[0];
			}
			else if (i >= 'A'&&i <= 'Z') {
				++count[1];
			}
			else if (i >= '0'&&i <= '9') {
				++count[2];
			}
			else {
				++count[3];
			}
		}
		if (count[0] && count[1]) {
			sum += 20;
		}
		else if (count[0] || count[1]) {
			sum += 10;
		}
		if (count[2] == 1) {
			sum += 10;
		}
		else if(count[2] > 1){
			sum += 20;
		}
		if (count[3] == 1) {
			sum += 10;
		}
		else if (count[3] > 1) {
			sum += 25;
		}
		if (count[0] && count[2] && count[1] && count[3]) {
			sum += 5;
		}
		else if ((count[0] || count[1]) && count[2] && count[3]) {
			sum += 3;
		}
		else if ((count[0] || count[1]) && count[2]) {
			sum += 2;
		}
		return sum;
	}
public:
	string fun(string& s) {
		int sum = f(s);
		if (sum >= 90) {
			return "VERY_SECURE";
		}
		else if (sum >= 80) {
			return "SECURE";
		}
		else if (sum >= 70) {
			return "VERY_STRONG";
		}
		else if (sum >= 60) {
			return "STRONG";
		}
		else if (sum >= 50) {
			return "AVERAGE";
		}
		else if (sum >= 25) {
			return "WEAK";
		}
		else {
			return "WERY_WEAK";
		}
	}
};
int main() {
	string str;
	Solution f;
	while (cin >> str) {
		cout << f.fun(str) << endl;
	}
	system("pause");
	return 0;
}