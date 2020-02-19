#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
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
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		vector<int> res(2);
		int size = nums.size();
		for (int i = 0; i < size; ++i) {
			int& n = nums[i];
			if (mp.insert(pair<int, int>(n, i + 1)).second == false) {
				if (2 * n == target) {
					res[0] = mp[n] - 1;
					res[1] = i;
					return res;
				}
			}
		}
		int n;
		for (int i = 0; i < size; ++i) {
			n = mp[target - nums[i]];
			--n;
			if (n > 0 && i != n) {
				res[0] = i;
				res[1] = n;
				return res;
			}
		}
		return res;
	}
};

int main() {
	string s1("aa");
	string s2("aab");
	Solution s;
	cout << s.canConstruct(s1, s2) << endl;
	/*int num;
	while (cin >> num) {
		cout << s.isPalindrome(num) << endl;
	}*/
	vector<int> v = { -1, -2, -3, -4, -5};
	for (auto& i : s.twoSum(v, -8)) {
		cout << i << endl;
	}
	cout << endl;
	return 0;
}