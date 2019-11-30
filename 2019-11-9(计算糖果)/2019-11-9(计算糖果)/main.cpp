#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> fun(int A_B, int B_C, int AB, int BC) {
		vector<int> res;
		res.resize(3);
		res[0] = (A_B + AB) / 2;
		res[1] = (B_C + BC) / 2;
		if (AB - A_B != 2 * res[1]) {
			res.clear();
			return res;
		}
		res[2] = res[1] - B_C;
		return res;
	}
};
int main() {
	int A_B, B_C, AB, BC;
	cin >> A_B >> B_C >> AB >> BC;
	Solution f;
	vector<int> v = f.fun(A_B, B_C, AB, BC);
	if (v.empty()) {
		cout << "No";
		return 0;
	}
	for (auto i : v) {
		cout << i << ' ';
	}
	system("pause");
	return 0;
}