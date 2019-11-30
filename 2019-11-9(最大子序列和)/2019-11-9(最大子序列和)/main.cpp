#pragma once
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	inline int GetMax(int a, int b) {
		return a > b ? a : b;
	}
	int fun(vector<int>& arr) {
		int Sum = arr[0];   //临时最大值
		int MAX = arr[0];   //比较之后的最大值
		int _size = arr.size();
		for (int i = 1; i < _size; i++) {
			Sum = GetMax(Sum + arr[i], arr[i]); //状态方程
			if (Sum > MAX) MAX = Sum;
		}
		return MAX;
	}
};

int main() {
	vector<int>v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	Solution fun;
	cout << fun.fun(v) << endl;
	system("pause");
	return 0;
}
