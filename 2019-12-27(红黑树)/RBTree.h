#pragma once
#include<iostream>
using namespace std;
enum Color {
	RED,
	BLACK
};
template<class T>
class RBTreeNode{
	T m_data;
	RBTreeNode<T>* m_left;
	RBTreeNode<T>* m_right;
	RBTreeNode<T>* m_parent;
	Color m_color;
public:
	RBTreeNode(const T& val = T(), Color color = RED) :
		m_data(val), m_left(nullptr),
		m_right(nullptr), m_parent(nullptr),
		m_color(color) 
	{}
	template<class T>
	friend class RBTree;
};
template<class T>
class RBTree {
	RBTreeNode<T>* m_head;
	void rRound(RBTreeNode<T>* pre) {//右单旋
		RBTreeNode<T>* cur = pre->m_left;

		cur->m_parent = pre->m_parent;
		if (pre->m_parent != m_head) {
			if (pre == pre->m_parent->m_left) {
				pre->m_parent->m_left = cur;
			}
			else {
				pre->m_parent->m_right = cur;
			}
		}
		else {
			m_head->m_parent = cur;
			cur->m_parent = m_head;
		}

		pre->m_left = cur->m_right;
		if (cur->m_right) {//如果存在, 让其父节点指向pre
			cur->m_right->m_parent = pre;
		}
		cur->m_right = pre;
		pre->m_parent = cur;

	}

	void lRound(RBTreeNode<T>* pre) {//左单旋
		RBTreeNode<T>* cur = pre->m_right;

		cur->m_parent = pre->m_parent;
		if (pre->m_parent != m_head) {
			if (pre == pre->m_parent->m_left) {
				pre->m_parent->m_left = cur;
			}
			else {
				pre->m_parent->m_right = cur;
			}
		}
		else {
			m_head->m_parent = cur;
			cur->m_parent = m_head;
		}

		pre->m_right = cur->m_left;
		if (cur->m_left) {//如果存在, 让其父节点指向pre
			cur->m_left->m_parent = pre;
		}
		cur->m_left = pre;
		pre->m_parent = cur;
	}

	RBTreeNode<T>* leftMost() {
		RBTreeNode<T>* cur = m_head->m_parent;
		for (; cur->m_left; cur = cur->m_left);
		return cur;
	}
	RBTreeNode<T>* rightMost() {
		RBTreeNode<T>* cur = m_head->m_parent;
		for (; cur->m_right; cur = cur->m_right);
		return cur;
	}
public:
	RBTree() {
		m_head = new RBTreeNode<T>;
	}
	RBTreeNode<T>*& getRoot() {
		return m_head->m_parent;
	}
	bool insert(const T& val) {
		RBTreeNode<T>*& root = m_head->m_parent;
		if (root == nullptr) {//情况1
			root = new RBTreeNode<T>(val, BLACK);
			root->m_parent = m_head;
		}
		else {

		}
		
		return true;
	}
};
