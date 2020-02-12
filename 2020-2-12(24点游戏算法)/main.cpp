#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool Is_24(vector<int> v, double res) {
		if (v.empty()) {
			return 24.0 == res;
		}
		for (size_t i = 0; i < v.size();++i) {
			vector<int> tmp(v);
			tmp.erase(tmp.begin() + i);
			if(Is_24(tmp, res + v[i]) || Is_24(tmp, res - v[i]) ||
				Is_24(tmp, res * v[i]) || Is_24(tmp, res / v[i])){
                return true;
            }
		}
		return false;
	}
};
int main() {
	Solution s;
	vector<int> v(4);
	while (cin >> v[0] >> v[1] >> v[2] >> v[3]) {
		s.Is_24(v, 0.0) ? cout << "true\n" : cout << "false\n";
	}
	system("pause");
	return 0;
}