//// write your code here cpp
//#include<iostream>
//#include<queue>
//#include<functional>
//using namespace std;
//
//
//int main() {
//	int N;
//	priority_queue<int, deque<int>, greater<int>> pq;
//	while (cin >> N) {
//		int* a = new int[N];
//		for (int i = 0; i < N; ++i) {
//			cin >> a[i];
//		}
//		for (int i = 0, flag = 1,n = 1; i < N; ++i) {
//			pq.push(a[i]);
//			while (!pq.empty() && pq.top() == flag) {
//				cout << n++ << ' ' << a[i] << endl;
//				++flag;
//				pq.pop();
//			}
//		}
//		delete[] a;
//	}
//	return 0;
//}

// write your code here cpp
#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;

class Solution {

public:
	vector<int> fun(vector<int>& v) {
		int flag = 1, size = v.size(), pre = 1;;
		vector<int> res;
		set<int> s;
		for (auto& i : v) {
			s.insert(i);
			while (s.size() && *(s.begin()) == flag) {
				res.push_back(i);
				++flag;
				s.erase(s.begin());
			}
		}
		return res;
	}
};

int main() {
	int N, n;
	Solution s;
	while (cin >> N) {
		vector<int> v(N);
		for (auto& i : v) {
			cin >> i;
		}
		n = 1;
		for (auto& i : s.fun(v)) {
			cout << n++ << ' ' << i << endl;
		}
	}
	//vector<int> v = { 1,2,3,4,5 };
	//map<int, int> mp;
	//for (auto&i : v) {
	//	mp[i];
	//}
	//for (auto& i : mp) {
	//	cout << i.first << ' ' << i.second << endl;
	//}
	return 0;
}