//// write your code here cpp
//// write your code here cpp
//#include<iostream>
//#include<vector>
//#include<cstdio>
//using namespace std;
//
//class Solution {
//	bool IsLeap(const int year) {
//		return (year % 400 == 0) || (year % 4 == 0 && year % 100);
//	}
//public:
//	vector<pair<int, int>> func(const int year) {
//		vector<pair<int, int>> res(8);
//		res[0] = make_pair(1, 1);
//		res[4] = make_pair(7, 4);
//		res[7] = make_pair(12, 25);
//		int month[12] = { 31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (IsLeap(year)) ++month[1];
//		int n = 0;
//		for (int i = 2000; i < year; i += 4) {
//			n += IsLeap(i);
//		}
//		int m = ((((year - 2000 - n) * 365 + n * 366) % 7) + 6) % 7;//1月1号星期几
//		for (int i = 0, cur_day = 0; i < 12; ++i) {
//			for (int j = 0, count = 0, count_ = 0, cur; j < month[i]; ++j, ++cur_day) {
//				cur = (cur_day % 7 + m) % 7;//今天星期几
//				if (cur == 1) ++count;//第几周
//				else if (cur == 4) ++count_;
//				if (i == 0 || i == 1) {//1月
//					if (count == 3 && cur == 1) {
//						res[i + 1] = make_pair(i + 1, j + 1);
//					}
//				}
//				else if (i == 4) {//5
//					if (cur == 1) {
//						res[3] = make_pair(5, j + 1);
//					}
//				}
//				else if (i == 8) {//9
//					if (count == 1 && cur == 1) {
//						res[5] = make_pair(9, j + 1);
//					}
//				}
//				else if (i == 10) {//11
//					if (count_ == 4 && cur == 4) {
//						res[6] = make_pair(11, j + 1);
//					}
//				}
//			}
//		}
//		return res;
//	}
//};
//
//int main() {
//	Solution s;
//	int year;
//	while (cin >> year) {
//		vector<pair<int, int>> res = s.func(year);
//		for (auto& i : res) {
//			printf("%d-%02d-%02d\n", year, i.first, i.second);
//		}
//		cout << endl;
//	}
//	return 0;
//}
// write your code here cpp
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
	static bool IsPrime[12];
	static int month[12];
	static int UnLeapMoney;
	bool IsLeap(int year) {
		return (year % 400 == 0) || (year % 4 == 0 && year % 100);
	}
public:
	int fun(int year1, int month1, int day1, int year2, int month2, int day2) {
		int n = year2 - year1 - 1;
		int m = 0;
		int res;
		if (n > 0) {
			for (int i = year1 + 1; i < year2; i += 4) {
				m += IsLeap(i);
			}
			res = (n - m)* UnLeapMoney + m * (UnLeapMoney + 1);
		}
		for (int i = month1; i < 12; ++i) {
			IsPrime[i] ? res += month[i] : res += (2 * month[i]);
		}
		if (month1 < 2 && IsLeap(year2)) res += 1;
		IsPrime[month1 - 1] ? res += day1 : res += (day1 * 2);
		for (int i = 0; i < month2 - 1; ++i) {
			IsPrime[i] ? res += month[i] : res += (2 * month[i]);
		}
		if (month2 > 1 && IsLeap(year2)) res += 1;
		IsPrime[month2 - 1] ? res += day2 : res += (day2 * 2);
		return res;
	}
	static void init() {
		for (int i = 0; i < 12; ++i) {
			IsPrime[i] ? UnLeapMoney += month[i] : UnLeapMoney += (2 * month[i]);
		}
	}
};
bool Solution::IsPrime[12] = { true, true, true, false, true, false, true, false, false, false, true, false };
int Solution::month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int Solution::UnLeapMoney = 0;

int main(){
	int year1, month1, day1, year2, month2, day2;
	Solution::init();
	Solution s;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
		cout << s.fun(year1, month1, day1, year2, month2, day2) << endl;
	}
	return 0;
}