#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 10000
class Solution {
	int* arr = new int[MAX];
public:
	int* fun() {
		int left = 0;
		int right = 1;
		int cur = 1;
		for (int i = 0; i < MAX; ++i) {
			cur = left + right;
			arr[i] = cur % MAX;
			left = right % MAX;
			right = arr[i];
		}
		return arr;
	}
};
int main() {
	int n, tmp;
	Solution s;
	int m = 0;
	int* arr = s.fun();
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			printf("%04d", arr[tmp - 1]);
		}
		cout << endl;
	}
	delete[] arr;
	return 0;
}