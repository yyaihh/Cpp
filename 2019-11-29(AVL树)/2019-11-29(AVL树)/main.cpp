#include<iostream>
#include"AVLTree.h"
using namespace std;
int main() {
	AVLTtree<int> AVL;
	Print<int> p;
	AVL.insert(10);
	AVL.insert(9);
	AVL.insert(8);
	AVL.insert(7);
	AVL.insert(6);
	AVL.insert(5);
	AVL.insert(4);
	AVL.insert(3);
	AVL.insert(2);
	AVL.insert(1);
	p.InorderPrint(AVL.getroot());
	AVL.erase(5);
	p.InorderPrint(AVL.getroot());
	AVL.erase(1);
	p.InorderPrint(AVL.getroot());
	AVL.erase(10);
	p.InorderPrint(AVL.getroot());
	AVL.erase(8);
	p.InorderPrint(AVL.getroot());
	AVL.erase(3);
	p.InorderPrint(AVL.getroot());
	AVL.erase(2);
	p.InorderPrint(AVL.getroot());
	AVL.erase(4);
	p.InorderPrint(AVL.getroot()); 
	AVL.erase(6);
	p.InorderPrint(AVL.getroot());
	AVL.erase(7);
	p.InorderPrint(AVL.getroot());
	AVL.erase(9);
	p.InorderPrint(AVL.getroot());
	system("pause");
	return 0;
}