#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
	static bool f(string& num1, string& num2) {
		int size1 = num1.size(), size2 = num2.size(), i;
		if (size1 == size2) {
			return num1 < num2;
		}
		for (i = 0; i < size1 && i < size2; ++i) {
			if (num1[i] < num2[i]) return true;
			if (num1[i] > num2[i]) return false;
		}
		for (char end = num2[i - 1]; i < size1; ++i) {
			if (num1[i] < end) return true;
			if (num1[i] > end) return false;
		}
		for (char end = num1[i - 1]; i < size2; ++i) {
			if (num2[i] < end) return false;
			if (num2[i] > end) return true;
		}
		return true;
	}
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string> vs;
		for (auto& i : numbers) {
			vs.push_back(to_string(i));
		}
		sort(vs.begin(), vs.end(), f);
		string res;
		for (auto& i : vs) {
			res += i;
		}
		return res;
	}
};

int main() {
	vector<int> v = {3, 32, 321};
	Solution s;
	cout << s.PrintMinNumber(v) << endl;
	return 0;
}