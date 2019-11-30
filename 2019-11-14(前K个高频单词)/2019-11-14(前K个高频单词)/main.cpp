#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
class Cmp {
public:
	bool operator()(const pair<string, int>& a, const pair<string, int>& b)const {
		return a.second > b.second || (a.second == b.second&&a.first < b.first);
	}
};
bool cmp(const pair<string, int>& a, const pair<string, int>& b){
	return a.second > b.second || (a.second == b.second&&a.first < b.first);
}
class Solution {
	
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> mp;
		vector<string> vs;
		for (auto i : words) {
			mp[i]++;
		}
		vector<pair<string, int>> tmp(mp.begin(), mp.end());
		sort(tmp.begin(), tmp.end(), cmp);
		for (auto i : tmp) {
			if (k--) {
				vs.push_back(i.first);
			}
			else {
				break;
			}
		}
		return vs;
	}
	vector<string> topKFrequent1(vector<string>& words, int k) {
		map<string, int> mp;
		set<pair<string, int>, Cmp> s;
		vector<string> vs;
		for (auto i : words) {
			mp[i]++;
		}
		s.insert(mp.begin(), mp.end());
		for (auto i : s) {
			if (k--) {
				vs.push_back(i.first);
			}
			else {
				break;
			}
		}
		return vs;
	}
};

int main() {
	int k;
	string s[] = { "i", "love", "leetcode", "i", "love", "coding" };
	vector<string> words(s, s + 6);
	cin >> k;
	Solution p;
	for (auto i : p.topKFrequent(words, k)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
