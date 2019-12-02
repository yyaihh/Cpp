#include<iostream>
#include<vector>
using namespace std;
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		int size1 = board.size();
		int size2 = board.size();
		for (int i = 1; i < size1; board[i][0] += board[i - 1][0], ++i);
		for (int i = 1; i < size2; board[0][i] += board[0][i - 1], ++i);
		for (int i = 1; i < size1; ++i) {
			for (int j = 1; j < size2; ++j) { 
				board[i][j] += board[i - 1][j] < board[i][j - 1] ? board[i][j - 1] : board[i - 1][j];
			}
		}
		int max = 0;
		for (int i = 0; i < size1; ++i) {
			max < board[i][size2 - 1] ? max = board[i][size2 - 1] : max;
		}
		for (int i = 0; i < size2; ++i) {
			max < board[size1 -1 ][i] ? max = board[size1 - 1][i] : max;
		}
		return max;
	}
};
int main() {
	Bonus s;
	vector <vector<int>> vv = { {1,2,3} ,{4,5,6}, {7,8,9} };
	int a = s.getMost(vv);
	return 0;
}