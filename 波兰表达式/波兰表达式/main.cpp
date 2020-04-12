// write your code here cpp
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		//二叉树后序变中序的过程
		//可以直接用vector做, 找到符运算符, 前两个就是需要计算的值, 然后将这三个位置换成计算的值
		stack<int> num;
		int leftnum, rightnum;
		for (auto& str : tokens) {
			if (str.size() >1 || str[0] >= '0' && str[0] <= '9') {
				num.push(atoi(str.c_str()));
			}
			else {
				rightnum = num.top();
				num.pop();
				leftnum = num.top();
				switch (str[0]) {
				case '+':
					num.top() = leftnum + rightnum;
					break;
				case '-':
					num.top() = leftnum - rightnum;
					break;
				case '*':
					num.top() = leftnum * rightnum;
					break;
				case '/':
					num.top() = leftnum / rightnum;
					break;
				}
			}
		}
		return num.top();
	}
};

int main() {
	Solution s;
	int n;
	while (cin >> n) {
		vector<string> vs(n);
		for (auto& s : vs) {
			cin >> s;
		}

		cout << s.evalRPN(vs) << endl;
	}
}