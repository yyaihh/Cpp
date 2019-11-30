#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	int size1;
	int size2;
	int count;
	bool f(vector<vector<int>>& v,int i,int j) {
		if (i - 2 >= 0 && v[i - 2][j] != 0) { 
			return false;
		}
		if (j - 2 >= 0&&v[i][j - 2] != 0) {
			return false;
		}
		return true;
	}
public:
	int fun(vector<vector<int>> v) {//复杂度O(n^2)
		count = 0;
		size1 = v.size();
		size2 = v[0].size();
		for (int i = 0; i < size1; ++i) {
			for (int j = 0; j < size2; ++j) {
				if (f(v, i, j)) {
					v[i][j] = 1;
					++count;
				}
			}
		}
		return count;
	}
	int fun1(int W, int H) {//复杂度O(1)
		int i, j, count = 0;
		i = W % 4;
		j = H % 4;
		i = (i ? (4 - i) : 0);//缺几行
		j = (j ? (4 - j) : 0);//缺几列
		int _W = W + i;
		int _H = H + j;
		count = _W * _H / 2;
		count -= (_W*j / 2 + _H * i / 2);
		if (i == j) {
			if (i == 2) {
				count += 4;
			}
			else if (i == 1) { 
				count += 1;
			}
			else if(i == 3){
				count += 5;
			}
		}
		else if (i == 2 && j == 1 || j == 2 && i == 1) { 
			count += 2;
		}
		else {
			count += 4;
		}
		return count;
	}
};
int main() {
	vector<vector<int>> v;
	int W, H;
	cin >> W >> H;
	v.resize(W);
	for (int i = 0; i < W; ++i) {
		v[i].resize(H, 0);
	}
	Solution f;
	cout << f.fun1(W, H) << endl;
	cout << f.fun(v);
	system("pause");
	return 0;
}
