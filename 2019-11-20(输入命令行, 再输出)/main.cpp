#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string>* command_line(vector<string>& vs) {
		vector<string>* p = new vector<string>;
		vector<string>&res = *p;
		bool flag = true;
		int size = vs.size();
		for (int i = 0, j = 0; j < size; ++j) {
			string& s = vs[j];
			if (flag && s[0] == '¡°') {
				flag = false;
				res.push_back(s);
				continue;
			}
			if (!flag&&*(s.end() - 1) != '¡±') {
				res[i - 1] += ' ';
				res[i - 1] += s;
				continue;
			}
			if (!flag) {
				res[i - 1] += ' ';
				res[i - 1] += s;
				flag = true;
				continue;
			}
			res.push_back(s);
		}
		return p;
	}
};
int main() {
	Solution s;
	vector<string> vs1;
	string str;
	do {
		cin >> str;
		vs1.push_back(str);
		str.clear();
	} while (getchar() != '\n');
	vector<string>& vs2 = *s.command_line(vs1);
	cout << vs2.size() << endl;
	for (auto& i : vs2) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
