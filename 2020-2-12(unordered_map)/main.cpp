#include<iostream>
#include"unordered_map.h"
#include<unordered_map>
#include"HashBucket.h"
using namespace std;

class KeyofValueint {
public:
	int operator()(int key)
	{
		return key;
	}
};
void test1() {
	HashBucket<int, int, KeyofValueint> hb;
	hb.insert(6);
	hb.insert(9);
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
	hb.insert(100);

	hb.erase(9);
	Iterator<int, int, KeyofValueint> begin;
	Iterator<int, int, KeyofValueint> end;
	if (begin == end) {

	}
	for (auto & e : hb)
	{
		cout << e << endl;
	}
}
void test2() {
	gh::unordered_map<int, int> ump;
	pair<int, int> p(10, 10);
	pair<gh::unordered_map<int, int>::iterator, bool> p2 = ump.insert(p);
	unordered_map<int, int> mp2;
	mp2.erase(10);
}
int main() {
	test1();
	test2();
	system("pause");
	return 0;
}
