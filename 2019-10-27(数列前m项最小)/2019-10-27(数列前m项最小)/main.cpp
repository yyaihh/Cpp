#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<deque>
class Solution {
public:
	void fun(vector<int>& t, int m) {
		int size = t.size();
		queue<int> qu;
		deque<int> qm;
		if (size < 1) {
			return ;
		}
		if (size == 1) {
			cout << t[0] << endl;
			return;
		}
		int min = t[0];
		qm.push_back(min);
		qu.push(min);
		cout << 0 << endl;
		cout << m << endl;
		int i, tmp;
		for (i = 1; i < m; ++i) {
			tmp = qm.back();
			cout << qm.front() << endl;
			int&num = t[i];
			if (num <= min) {
				min = num;
			}
			qu.push(num);
			qm.push_back(min);
		}
		for (; i < size; ++i) {
			tmp = qm.front();
			qm.pop_front();
			cout << tmp << endl;
			if (tmp == m) {
				min = qm.front();
			}
			int&num = t[i];
			if (num <= min) {
				min = num;
			}
			qm.push_back(min);
			qu.push(num);
		}
	}
};
int main() {

	int a[] = { 9,7,8,10,1,3,6 };
	Solution p;
	vector<int> t(a, a + sizeof(a)/sizeof(a[0]));
	p.fun(t,2);
	system("pause");
	return 0;
}