// write your code here cpp
// write your code here cpp
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
	int bfs(vector<string> & data) {
		vector<vector<int>> flag(data.size(), vector<int>(data[0].size()));
		queue<pair<int, int>> qp;
		int x, y; //当前位置
		qp.push(make_pair(0, 1));
		while (qp.size()) {
			x = qp.front().first;
			y = qp.front().second;
			if (x == 9 && y == 8) {
				return flag[9][8];
			}
			if (x > 0 && data[x - 1][y] != '#' && flag[x - 1][y] == 0) {//向上
				flag[x - 1][y] = flag[x][y] + 1;
				qp.push(make_pair(x - 1, y));
			}
			if (x < 9 && data[x + 1][y] != '#' && flag[x + 1][y] == 0) {//向下
				flag[x + 1][y] = flag[x][y] + 1;
				qp.push(make_pair(x + 1, y));
			}
			if (y > 0 && data[x][y - 1] != '#' && flag[x][y - 1] == 0) {//向左
				flag[x][y - 1] = flag[x][y] + 1;
				qp.push(make_pair(x, y - 1));
			}
			if (y < 9 && data[x][y + 1] != '#' && flag[x][y + 1] == 0) {//向右
				flag[x][y + 1] = flag[x][y] + 1;
				qp.push(make_pair(x, y + 1));
			}
			qp.pop();
		}
		return 0;
	}
};

int main() {
	vector<string> data(10);
	Solution s;
	while (cin >> data[0]) {
		for (int i = 1; i < 10; ++i) {
			cin >> data[i];
		}
		cout << s.bfs(data) << endl;
	}
	vector<string> data1 = { 
							{"#.########"},
							{"#........#"},
							{"#........#"},
							{"#........#"},
							{"#........#"},
							{"#........#"},
							{"#........#"},
							{"#........#"},
							{"#........#"},
							{"########.#"}
							};
	vector<string> data2 = {
							{"#.########"},
							{"#........#"},
							{"########.#"},
							{"#........#"},
							{"#.########"},
							{"#........#"},
							{"########.#"},
							{"#........#"},
							{"#.######.#"},
							{"########.#"}
							};
	cout << s.bfs(data1) << endl;
	cout << s.bfs(data2) << endl;
	return 0;
}