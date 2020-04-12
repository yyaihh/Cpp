//���ӣ�https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
//��Դ��ţ����
//
//��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
//
//�������� :
//��������������ݡ�
//
//ÿ�����ݵ�һ������������ m �� n��1��m, n��20���������� m �У�ÿ�а��� n ���ַ���ÿ���ַ���ʾһ���ש����ɫ���������£�
//
//1. ��.������ɫ�Ĵ�ש��
//2. ��#������ɫ�Ĵ�ש��
//3. ��@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�
//
//
//������� :
//��Ӧÿ�����ݣ�����ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��
//ʾ��1
//����
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

//���
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
		vector<vector<bool>> vv(down, vector<bool>(right));//��־
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