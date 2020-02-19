#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool canConstruct(string& ransomNote, string& magazine) {
		int a[26] = { 0 };
		for (auto& c : ransomNote) {
			++a[c - 97];
		}
		for (auto& c : magazine) {
			--a[c - 97];
		}
		for (int i = 0; i < 26; ++i) {
			if (a[i] < 0) {
				return false;
			}
		}
		return true;
	}
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}
		int tmp = x;
		int res = 0;
		while (x) {
			res *= 10;
			res += (x % 10);
			x /= 10;
		}
		return res == tmp;
	}
};

int main() {
	string s1("aa");
	string s2("aab");
	Solution s;
	cout << s.canConstruct(s1, s2) << endl;
	int num;
	while (cin >> num) {
		cout << s.isPalindrome(num) << endl;
	}
	return 0;
}