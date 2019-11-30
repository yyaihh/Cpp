//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//using namespace std;
//
//class Solution {
//public:
//	string fun(vector<string> vs, int n) {
//		map<string, int> mp = { {"3",1},{"4",2},{"5",3},{"6",4},{"7",5},{"8",6},
//					{"9",7},{"10",8},{"J",9},{"Q",10}, {"K",11},{"A",12},{"2",13},{"joker",10000},
//					{"JOKER",10000}, };
//		int size = vs.size();
//		if (size == 7) { 
//			if (n == 2) {
//				if (mp[vs[0]] + mp[vs[1]] == 2000) {
//					return "joker JOKER";
//				}
//			}
//			else {
//				if (mp[vs[6]] + mp[vs[5]] == 2000) {
//					return "joker JOKER";
//				}
//			}
//		}
//	}
//};
//
//int main() {
//	string str;
//	string tmp;
//	vector<string> vs;
//	bool flag = false;
//	int n;
//	Solution s;
//	while (getline(cin, str)) { 
//		auto end = str.end();
//		for (auto i = str.begin(); i != end; ++i) { 
//			while (*i != ' ') {
//				if (*i != '-') {
//					tmp += *i;
//					++i;
//				}
//				else {
//					n = vs.size();
//					break;
//				}
//				if (i != end) flag = true;
//			}
//			vs.push_back(tmp);
//			tmp.clear();
//			if (flag)break;
//		}
//		cout << s.fun(vs,size) << endl;
//	}
//	system("pause");
//	return 0;
//}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else {
			int dash = line.find('-');
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			int c1 = count(car1.begin(), car1.end(), ' ') + 1;
			int c2 = count(car2.begin(), car2.end(), ' ') + 1;
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2) {
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else {
				if (c1 == 4)//Õ¨µ¯
					cout << car1 << endl;
				else if (c2 == 4)//Õ¨µ¯
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}