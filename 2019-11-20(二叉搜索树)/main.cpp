#include<iostream> 
#include"Btree.h"
#include"Btree2.h"
using namespace std;

int main() {
	Btree<int> t;
	Print<int> p;
	t.insert(10);
	t.insert(9);
	t.insert(8);
	t.insert(7);
	t.insert(6);
	t.insert(5);
	t.insert(4);
	t.insert(3);
	t.insert(2);
	t.insert(1);
	p.InorderPrint(t.getRoot());
	t.erase(5);
	p.InorderPrint(t.getRoot());
	t.erase(1);
	p.InorderPrint(t.getRoot());
	t.erase(10);
	p.InorderPrint(t.getRoot());
	t.erase(8);
	p.InorderPrint(t.getRoot());
	t.erase(3);
	p.InorderPrint(t.getRoot());
	t.erase(2);
	p.InorderPrint(t.getRoot());
	t.erase(4);
	p.InorderPrint(t.getRoot());
	t.erase(6);
	p.InorderPrint(t.getRoot());
	t.erase(7);
	p.InorderPrint(t.getRoot());
	t.erase(9);
	p.InorderPrint(t.getRoot());
	system("pause");
	return 0;
}