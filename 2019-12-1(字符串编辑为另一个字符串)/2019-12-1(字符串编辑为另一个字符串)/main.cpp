#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int calStringDistance(string& s1, string& s2) { 
		int size1 = s1.size();
		int size2 = s2.size();
		int left_up;
		vector<vector<int>>vv(size1 + 1, vector<int>(size2 + 1));
		vv[0][0] = 0;//vv[x][y]����a�ַ���ǰx���ַ��޸ĳ�b�ַ���ǰy���ַ�
		//��ʼ���߽�
		for (int i = 0; i <= size2; vv[0][i] = i, ++i);
		for (int i = 0; i <= size1; vv[i][0] = i, ++i);
		//��ʼ���
		for (int i = 1; i <= size1; ++i) {
			for (int j = 1; j <= size2; ++j) {
				left_up = vv[i - 1][j - 1];
				if (s1[i - 1] != s2[j - 1]) {
					 ++left_up;
				}  
				vv[i][j] = min(min(vv[i - 1][j] + 1, vv[i][j - 1] + 1), left_up);
				//ȡ��һ��, ��һ��, ����
			}
		}
		return vv[size1][size2];
	}
};
int main() {
	string s1, s2;
	Solution f;
	while (cin >> s1 >> s2) { 
		cout << f.calStringDistance(s1, s2) << endl;
	}
	return 0;
}