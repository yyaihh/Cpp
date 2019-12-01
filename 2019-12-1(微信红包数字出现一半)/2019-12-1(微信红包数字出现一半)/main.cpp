#include<iostream>
#include<vector>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return gifts[0];
		int count1 = 1;
		int count2 = 1;
		bool flag = true;
		int num;
		int pre;
		auto end = gifts.end();
		for (auto i = gifts.begin() + 1; i < end; ++i) {
			if (flag) {
				flag && *i^*(i + 1) ? flag = false : (++count2, num = *i);
			}
			else {
				*i^*(i + 1) ? flag = true : ++count1;
			}
			if (flag && count1 > count2) {
				num = *i;
				count2 = count1;
				count1 = 1;
			}
		}
		count1 = 0;
		for (auto i : gifts) {
			i ^ num ? 0 : ++count1;
		}
		return (count1 > n / 2) ? num : 0;
	}
};