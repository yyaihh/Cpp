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
		//���������������Ĺ���
		//����ֱ����vector��, �ҵ��������, ǰ����������Ҫ�����ֵ, Ȼ��������λ�û��ɼ����ֵ
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