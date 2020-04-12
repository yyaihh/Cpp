//链接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
//来源：牛客网
//
//有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
//
//输入描述 :
//输入包含多组数据。
//
//每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：
//
//1. “.”：黑色的瓷砖；
//2. “#”：白色的瓷砖；
//3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
//
//
//输出描述 :
//对应每组数据，输出总共能够到达多少块黑色的瓷砖。
//示例1
//输入
//9 6 
/*
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
*/

//输出
//45

// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	vector<string>* pvs;
	vector<vector<bool>>* pvv;
	int right, down;
	int judge(int x, int y) {
		if (x < 0 || x >= down || y < 0 || y >= right || (*pvv)[x][y]) return 0;
		(*pvv)[x][y] = true;
		return judge(x - 1, y) + judge(x + 1, y) + judge(x, y - 1) + judge(x, y + 1) + 1;
	}
public:
	int fun(vector<string>& vs) {
		pvs = &vs;
		right = vs[0].size(), down = vs.size();
		vector<vector<bool>> vv(down, vector<bool>(right));//标志
		int x, y;
		pvv = &vv;
		for (int i = 0; i < down; ++i) {
			y = vs[i].find('@');
			if (y != string::npos) {
				x = i;
				break;
			}
		}
		for (int i = 0; i < down; ++i) {
			for (int j = 0; j < right; ++j) {
				vs[i][j] == '#' ? vv[i][j] = true : vv[i][j] = false;
			}
		}
		return judge(x, y);
	}
};
int main() {
	int m, n;
	Solution s;
	while (cin >> m && cin >> n) {
		vector<string> vs(m);
		for (auto& s : vs) {
			cin >> s;
		}
		cout << s.fun(vs) << endl;
	}
	return 0;
}