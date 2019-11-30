#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int len= board.size();
		int count = 0;
		bool flag;
		for (auto i : board) {
			flag = true;
			for (auto j : i) {
				if (j != 1) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
		for (int i = 0; i < len; ++i) {
			flag = true;
			for (int j = 0; j < len; ++j) { 
				if (board[j][i] != 1) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
		flag = true;
		for (int i = 0; i < len; ++i) {
			if (board[i][i] != 1) {
				flag = false;
			}
		}
		if (flag) {
			return true;
		}
		flag = true;
		for (int i = 0, j = len - 1; i < len; ++i, --j) { 
			if (board[i][j] != 1) {
				flag = false;
			}
		}
		if (flag) {
			return true;
		}
		return false;
	}
};
int main() {
	
	Board f;

	system("pause");
	return 0;
}