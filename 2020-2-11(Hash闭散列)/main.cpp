#include<iostream>
#include"Hash.h"
using namespace std;

int main() {
	HashTable<int, int> ht;

	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));
	ht.insert(pair<int, int>(23, 11));
	ht.insert(pair<int, int>(27, 13));
	ht.insert(pair<int, int>(33, 13));
	ht.insert(pair<int, int>(36, 13));
	ht.insert(pair<int, int>(27, 13));
	ht.insert(pair<int, int>(33, 13));
	ht.insert(pair<int, int>(36, 13));
	ht.erase(33);
	int n = ht.find(27);
	int m = ht.find(222);
	ht.clear();
	ht.insert(pair<int, int>(1, 5));
	ht.insert(pair<int, int>(2, 7));
	ht.insert(pair<int, int>(5, 6));
	ht.insert(pair<int, int>(6, 8));
	ht.insert(pair<int, int>(12, 9));
	ht.insert(pair<int, int>(16, 4));
	ht.insert(pair<int, int>(23, 11));
	ht.insert(pair<int, int>(27, 13));
	ht.insert(pair<int, int>(33, 13));
	ht.insert(pair<int, int>(36, 13));

	ht.insert(pair<int, int>(27, 13));
	ht.insert(pair<int, int>(33, 13));
	ht.insert(pair<int, int>(36, 13));
	system("pause");
	return 0;
}