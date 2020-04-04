#include<iostream>
#include<vector>
#include<string>
using namespace std;
//class Solution {
//
//public:
//	static string str[8];
//	void dealletterCombinations(string& digits, size_t pos, vector<string>& alldata) {
//		static string tmp = digits;
//		if (pos < digits.size()) {
//			for (auto i : str[digits[pos] - '2']) {
//				tmp[pos] = i;
//				dealletterCombinations(digits, pos + 1, alldata);
//			}
//		}
//		else {
//			alldata.push_back(tmp);
//		}
//	}
//	vector<string> letterCombinations(string& digits) {
//		vector<string> res;
//		if (digits.empty()) {
//			return res;
//		}
//		dealletterCombinations(digits, 0, res);
//		return res;
//	}
//};
class Solution {
	static string str[8];
	vector<string>* pres;
	const string* ps;
	int size;
	void dealletterCombinations(int pos) {
		static string tmp(size, 0);
		if (pos < size) {
			for (auto i : str[(*ps)[pos] - '2']) {
				tmp[pos] = i;
				dealletterCombinations(pos + 1);
			}
		}
		else {
			pres->push_back(tmp);
		}
	}
public:
	vector<string> letterCombinations(const string& s) {
		vector<string> res;
		if (s.empty()) return res;
		size = s.size();
		pres = &res;
		ps = &s;
		for (auto i : s) {
			if (i < '2') {
				return res;
			}
		}
		dealletterCombinations(0);
		return res;
	}
};
string Solution::str[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

int main() {
	string test = "2";
	Solution fun;
	for (auto i : fun.letterCombinations(test)) {
		cout << i << endl;
	}

	system("pause");
	return 0;
}
