//链接：https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
//来源：牛客网
//
//
//例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
//现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。
//
//输入描述 :
//输入包含多组数据。
//
//每组数据包含两个字符串m和n，它们仅包含字母，并且长度不超过1024。
//
//
//输出描述 :
//对应每组输入，输出最长公共子序列的长度。
//示例1
//输入
//abcfbc abfcab<br / >programming contest<br / >abcd mnp
//输出
//4 < br / > 2 < br / > 0

// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	static int fun(string& s1, string& s2) {
		int size1 = s1.size(), size2 = s2.size();
		vector<int> v(size2 + 1, 0);
		for (int i = 0, cur; i < size1; ++i) {
			for (int j = 1, old = v[0]; j <= size2; ++j) {
				cur = v[j];
				if (s1[i] == s2[j - 1]) {
					v[j] = max(v[j], old + 1);
				}
				else {
					v[j] = max(v[j], v[j - 1]);
				}
				old = v[j];
			}
		}
		return v[size2];
	}
};

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << Solution::fun(s1, s2) << endl;
	}
	return 0;
}