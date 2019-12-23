#include<iostream>
#include"AVLTree.h"
using namespace std;
int main() {
	AVLTtree<int> AVL;
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
	AVL.InorderPrint();
	system("pause");
	return 0;
}