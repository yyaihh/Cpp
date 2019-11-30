#include<iostream> 
#include"Btree.h"
#include"Btree2.h"
using namespace std;

int main() {
	Btree<int> t;
	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(1);
	t.insert(4);
	t.insert(6);
	t.insert(8);
	t.insert(0);
	t.insert(9);
	t.insert(10);
	t.InorderPrint();
	t.erase(6);
	t.InorderPrint();
	t.erase(5);
	t.InorderPrint();
	system("pause");
	return 0;
}