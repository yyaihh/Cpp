#include<iostream>
#include<unordered_map>
using namespace std;
void test1() {
	pair<int, int> p1(1, 2);
	pair<int, int> p2(3, 4);
	pair<int, int> p3(5, 6);
	pair<int, int> p4(7, 8);
	unordered_map<int, int> mp1;
	unordered_map<int, int> mp2 = { p1, p2, p3, p4 };
	unordered_map<int, int> mp3(mp2);
	unordered_map<int, int> mp4(mp2.begin(), mp2.end());
	unordered_map<int, int>::iterator i;
	cout << "mp2:\n";
	for (i = mp2.begin(); i != mp2.end(); ++i) {
		cout << '(' << (*i).first << ',' << (*i).second << ") ";
	}
	cout << "\nmp3:\n";
	for (i = mp3.begin(); i != mp3.end(); ++i) {
		cout << '(' << (*i).first << ',' << (*i).second << ") ";
	}
	cout << "\nmp4:\n";
	for (i = mp4.begin(); i != mp4.end(); ++i) {
		cout << '(' << (*i).first << ',' << (*i).second << ") ";
	}
}
int main() {
	test1();
	return 0;
}
