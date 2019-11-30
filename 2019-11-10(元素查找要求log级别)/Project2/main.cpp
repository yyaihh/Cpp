#include<iostream>
#include<vector>
using namespace std;

class Solution {
	
public:
	//log级别算法不能遍历
	//下面应该是n
	int f(int pos, int n, int num, const vector<int>& A) {
		for (int i = pos; i < n; ++i) {
			if (A[i] == num) {
				return i;
			}
		}
	}
	int fun(const vector<int>& A, int n, int num) {
		bool flag = true;
		int pos;
		if (n > 2) {
			if (A[0] > A[1]&&A[1]>A[2]) {
				flag = false;
			}
		}
		if (flag) {
			for (int i = 0; i < n-1; ++i) {
				if (num == A[i]) {
					return i;
				}
				if (A[i] > A[i + 1]) {
					pos = i;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < n - 1; ++i) {
				if (num == A[i]) {
					return i;
				}
				if (A[i] < A[i + 1]) {
					pos = i;
					break;
				}
			}
		}
		if (flag ) {
			if (num < A[n - 1]) {
				return f(pos, n, num, A);
			}
		}
		else {
			if (num > A[n - 1]) {
				return f(pos, n, num, A);
			}
		}
		return -1;
	}
};
int main() {
	vector<int> v;
	int n, num;
	cin >> n >> num;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	Solution f;
	cout << f.fun(v, n, num);
	system("pause");
	return 0;
}