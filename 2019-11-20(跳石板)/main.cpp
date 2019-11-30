//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//using namespace std;
//class Solution {
//	int fun(int x, int y) {
//		int z;
//		while (z = x % y) {
//			x = y;
//			y = z;
//		}
//		return y;
//	}
//	bool f1(int num) {
//		double m = sqrt(num);;
//		for (int j = 2; j <= m; j++)
//			if (num%j == 0)
//				return false;
//		return true;
//	}
//	pair<bool,int> f(int x, int flag) {
//		int tmp = flag - 1;
//		int n = (int)sqrt(x);
//		if (f1(x)) {
//			return pair<bool, int>(false, 0);
//		}
//		/*if (tmp < 1 || n == 1) {
//			return pair<bool, int>(false, 0);
//		}*/
//		while (x%tmp && tmp >= n) {
//			--tmp;
//		}
//		if (x%tmp == 0) {
//			return pair<bool, int>(true, tmp);
//		}
//		return pair<bool, int>(false, 0);
//	}
//public:
//	int set_number(int N, int M) {
//		if (N == M) {
//			return 0;
//		}
//		if (N > M) {
//			return -1;
//		}
//		int count = 0;
//		int X = N;
//		pair<bool, int> p;
//		while (N < M) {
//			p = f(N, X);
//			if (p.first) {
//				X = p.second;
//			}
//			else {
//				return -1;
//			}
//			if (N + X <= M) {
//				N += X;
//				/*if (M - N != 0 && f1(M - N)) {
//					return -1;
//				}*/
//				++count;
//				X = N;
//			}
//		}
//		if (count == 0 || N > M) {
//			return -1;
//		}
//		return count;
//	}
//};
//int main() {
//	int N, M;
//	Solution s;
//	cin >> N >> M;
//	cout << s.set_number(N, M) << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100001
class Solution {
public:
	int set_number(int N, int M) {
		vector<int> v(M + 1, MAX);
		v[N] = 0;//从出发点到出发点位置步数为0
		for (int i = N; i <= M; i++) {
			if (v[i] == MAX) {//这个石板不能跳
				continue;
			}
			for (int j = 2; j*j <= i; j++) {
				if (i%j == 0) {
					if (i + j <= M) {
						v[i + j] = min(v[i] + 1, v[i + j]);
						//从位置i一步走到下一位置 i+j, 和原本走到i+j位置的步数相比取最小步数
					}
					if (i + (i / j) <= M) {
						v[i + (i / j)] = min(v[i] + 1, v[i + (i / j)]);
						//从位置i一步走到下一位置 i+i/j, 和原本走到i+i/j位置的步数相比取最小步数
					}
				}
			}
		}
		if (v[M] == MAX) {
			return -1;
		}
		return v[M];
	}
};
int main() {
	int N, M;
	Solution s;
	while (cin >> N >> M) {
		cout << s.set_number(N, M) << endl;
	}

	return 0;
}