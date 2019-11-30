#include<iostream>
#include<string>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(const string& A, int n) {
		int left = 0;
		int right = 0;
		for (int i = 0; i < n; ++i) {
			const char& ch = A[i];
			if (ch != ')' && ch != '(') {
				return false;
			}
			if (right > left) {
				return false;
			}
			if (ch == '(') {
				++left;
			}
			if (ch == ')') {
				++right;
			}
		}
		return left == right;
	}
};
int main() {
	string s;
	cin >> s;
	Parenthesis p;
	cout << p.chkParenthesis(s, 6);
	system("pause");
	return 0;
}