#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Gloves {
public:
	int findMinimum(int n, vector<int>& left, vector<int>& right) {
		int count1 = 0, left_min = INT_MAX;//初始化为最大值
		int count2 = 0, right_min = INT_MAX;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (left[i] == 0 || right[i] == 0) {
				count += left[i] + right[i];
			}
			else {
				count1 += left[i];
				count2 += right[i];
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);
			}
		}
		//如果有序
		//公式(a1+a2+a3+..an)-a1+1, 最大全覆盖, 再在另一边随便取一双
		return count + min(count1 - left_min + 1, count2 - right_min + 1) + 1;
	}
};
int main() {
	int n  =4;
	//cin >> n;
	vector<int> left = { 0,7,1,6 };
	vector<int> right = { 1,5,0,6 };
	//for (int i = 0; i < n; cin >> left[i], ++i);
	//for (int i = 0; i < n; cin >> right[i], ++i);
	Gloves g;
	cout << g.findMinimum(n, left, right) << endl;
	system("pause");
	return 0;
}
