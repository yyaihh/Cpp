#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template <class T>
class TreeNode {
	T m_data;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
	TreeNode<T>* m_parent;
	int m_bf;//平衡因子
public:
	TreeNode(const T& data = T())
		:m_data(data), m_left(nullptr), m_bf(0),
		m_right(nullptr), m_parent(nullptr)
	{}
	template <class T>
	friend class AVLTtree;
};
template <class T>
class AVLTtree {
	TreeNode<T>* m_root;
	void destroy(TreeNode<T>* root) {
		if (root) {
			destroy(root->m_left);
			destroy(root->m_right);
			delete root;
		}
	}

public:
	AVLTtree()
		:m_root(nullptr)
	{}
	~AVLTtree() {
		destroy(m_root);
	}
	bool insert(const T val) {
		TreeNode<T>* newp = new T(val);
		if (m_root == nullptr) {
			m_root = newp;
			return true;
		}

		TreeNode<T>* cur = m_root;
		TreeNode<T>* pre = nullptr;
		while (cur) {
			pre = cur;
			if (val < cur->m_data) {
				cur = cur->m_left;
			}
			else if (val > cur->m_data) {
				cur = cur->m_right;
			}
			else {
				delete newp;
				return false;
			}
		}

		if (val < pre->m_data) {
			pre->m_left = newp;
		}
		else {
			pre->m_right = newp;
		}
		newp->m_parent = pre;

		//先按照二叉搜索的插入方式先插, 若是不平衡, 则调整
		while () {
			if (pre->m_left == cur) {
				pre->m_bf--;
			}
			else {
				pre->m_bf++;
			}
		}
		//情况1, 


	}
	void InorderPrint() {
		stack<TreeNode<T>*> s;
		vector<T> res;
		TreeNode<T>* cur = m_root;
		while (cur) {
			for (; cur; cur = cur->m_left) {
				s.push(cur);
			}
			do {
				cur = s.top();
				res.push_back(cur->m_data);
				s.pop();
			} while (cur->m_right == nullptr && !s.empty());
			cur = cur->m_right;
		}
		for (auto& i : res) {
			cout << i << ' ';
		}
		cout << endl;
	}
};