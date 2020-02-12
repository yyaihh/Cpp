#include<iostream>
#include"HashBucket.h"
using namespace std;

class KeyofValueint {
public:
	int operator()(int key)
	{
		return key;
	}
};

int main() {
	gh::HashBucket<int, int, KeyofValueint> hb;
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
	gh::iterator<int, int, KeyofValueint> begin;
	gh::iterator<int, int, KeyofValueint> end;
	if (begin == end) {

	}
	for (auto & e : hb)
	{
		cout << e << endl;
	}

	return 0;
}