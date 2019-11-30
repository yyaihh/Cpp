#include<iostream>
#include<list>
using namespace std;
class Solution {
	void f1(list<int>::iterator& i) {
		if (i == end) {
			i = begin;
			cur = begin;
		}
		else {
			++i;
		}
	}
	void f2(list<int>::iterator& i) {
		if (i == begin) {
			i = end;
			cur = ------end;
		}
		else {
			--i;
		}
	}
	void f3(list<int>::iterator j) { 
		for (int i = 0; i < 4; ++i, j++) {
			cout << *j << ' ';
			if (j == end) {
				break;
			}
		}
	}
	list<int>::iterator end ;
	list<int>::iterator begin;
	list<int>::iterator cur;
public:
	void fun(int num) {
		list<int> l(num);
		int n = 1;
		for (auto& i : l) {
			i = n++;
		}
		end = --l.end();
		begin = l.begin();
		cur = begin;
		char ch;
		n = 0;
		int n1 = 0;
		for (auto i = begin;; ++n) { 
			ch = getchar();
			if (ch == 'U') {
				f2(i);
				++n1;
				if (n1 % 4 == 0) {
					cur=
				}
				continue;
			}
			if (ch == 'D') {
				f1(i);
				--n1;
				continue;
			}
			if (ch == '\n') {
				int m = n / 4;
				int s = *i % 4;
				if (m > 0) {
					if (s == 0) {
						s = 4;
					}
					while (s--)f2(i);
					f3(cur);
				}
				else {
					f3(l.begin());
				}
				cout << *i << endl;
				break;
			}
		}
	}
};
int main() {
	int num;
	cin >> num;
	getchar();
	Solution s;
	s.fun(num);
	system("pause");
	return 0;
}