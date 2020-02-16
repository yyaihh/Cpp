#include<iostream>
#include"unordered_map.h"
#include<unordered_map>
#include"HashBucket.h"
using namespace std;

class KeyofValueint {
public:
	int operator()(int key) {
		return key;
	}
};

void test1() {
	HashBucket<int, int, KeyofValueint> hb;
	hb.insert(6);
	Iterator<int, int, KeyofValueint> q = hb.insert(9).first;
	hb.insert(17);
	hb.insert(16);
	hb.insert(19);
	hb.insert(27);
	hb.insert(61);
	hb.insert(98);
	hb.insert(26);
	hb.insert(63);
	hb.insert(39);
	hb.insert(28);
	pair<Iterator<int, int, KeyofValueint>, bool> p = hb.insert(100);
	pair<Iterator<int, int, KeyofValueint>, bool> p2 = hb.insert(100);
	cout << *p.first << endl;
	p = hb.erase(9);
	p2 = hb.erase(10101);
	cout << *p.first << endl << endl;
	for (auto & e : hb) {
		cout << e << endl;
	}
	cout << "\n\n\n\n";
}
void test2() {
	gh::unordered_map<int, int> ump;
	ump.insert(pair<int, int>(6, 10));
	auto q = ump.insert(pair<int, int>(9, 30)).first;
	ump.insert(pair<int, int>(17, 48));
	ump.insert(pair<int, int>(16, 32));
	ump.insert(pair<int, int>(19, 56));
	ump.insert(pair<int, int>(27, 89));
	ump.insert(pair<int, int>(61, 565));
	ump.insert(pair<int, int>(98, 34));
	ump.insert(pair<int, int>(26, 78));
	ump.insert(pair<int, int>(63, 67));
	ump.insert(pair<int, int>(39, 67));
	ump.insert(pair<int, int>(28, 67));
	pair<gh::unordered_map<int, int>::iterator, bool> p = ump.insert(pair<int, int>(100, 89));
	pair<gh::unordered_map<int, int>::iterator, bool> p2 = ump.insert(pair<int, int>(100, 23));
	cout << (*(p.first)).first << "  " << (*(p.first)).second << endl;
	p = ump.erase(9);
	p2 = ump.erase(10101);
	cout << (*(p.first)).first << "  " << (*(p.first)).second << endl;
	for (auto & e : ump) {
		cout << e.first << "  " << e.second << endl;
	}
}
int main() {
	test1();
	test2();
	system("pause");
	return 0;
}
