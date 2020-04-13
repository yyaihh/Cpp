
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

class Solution {
	static unordered_map<char, char> ump;
public:
	set<string> fun(vector<string>& vs) {
		set<string> res;
		int flag;
		for (auto& s : vs) {
			string tmp;
			flag = 0;
			for (auto c : s) {
				if (c == '-') continue;
				if (flag == 3) tmp += '-';
				tmp += ump[c];
				++flag;
			}
			res.insert(tmp);
		}
		return res;
	}

};
unordered_map<char, char> Solution::ump = { make_pair('A', '2'), make_pair('B', '2'), make_pair('C', '2'), make_pair('D', '3'),
										  make_pair('E', '3'), make_pair('F', '3'), make_pair('G', '4'), make_pair('H', '4'),
										  make_pair('I', '4'), make_pair('J', '5'), make_pair('K', '5'), make_pair('L', '5'),
										  make_pair('M', '6'), make_pair('N', '6'), make_pair('O', '6'), make_pair('P', '7'),
										  make_pair('Q', '7'), make_pair('R', '7'), make_pair('S', '7'), make_pair('T', '8'),
										  make_pair('U', '8'), make_pair('V', '8'), make_pair('W', '9'), make_pair('X', '9'),
										  make_pair('Y', '9'), make_pair('Z', '9'), make_pair('1', '1'), make_pair('2', '2'),
										  make_pair('3', '3'), make_pair('4', '4'), make_pair('5', '5'), make_pair('6', '6'),
										  make_pair('7', '7'), make_pair('8', '8'), make_pair('9', '9'), make_pair('0', '0') };
int main() {
	Solution f;
	int n;
	while (cin >> n) {
		vector<string> vs(n);
		for (auto& s : vs) {
			cin >> s;
		}
		for (auto& s : f.fun(vs)) {
			cout << s << endl;;
		}
		cout << endl;
	}
	return 0;
}