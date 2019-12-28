#pragma once
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
template <class T>
class TreeNode{
	T m_data;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
public:
	TreeNode(const T& data = T())
		:m_data(data),
		m_left(nullptr),
		m_right(nullptr)
	{}
	template <class T>
	friend class Btree;

	template <class T>
	friend class Print;
};
template <class T>
class Btree {
	TreeNode<T>* m_root;
	void destroy(TreeNode<T>* root) {
		if (root) {
			destroy(root->m_left);
			destroy(root->m_right);
			delete root;
		}
	}
public:
	Btree() 
		:m_root(nullptr)
	{}
	~Btree() {
		destroy(m_root);
	}
	TreeNode<T>* getRoot() {
		return m_root;
	}
	bool insert(const T& val) {//插入
		TreeNode<T>* newp = new TreeNode<T>;
		newp->m_data = val;
		if (m_root == nullptr) {
			m_root = newp;
			return true;
		}
		TreeNode<T>* pre = m_root;
		TreeNode<T>* cur = m_root;
		while (cur) {
			pre = cur;
			if (val > cur->m_data) {
				cur = cur->m_right;
			}
			else if (val < cur->m_data) {
				cur = cur->m_left;
			}
			else{
				delete newp;
				return false;
			}
		}//循环结束, 若没有重复节点, 则可以插入, pre就是需要插入位置的的父节点
		if (pre->m_data < val) {
			pre->m_right = newp;
		}
		else {
			pre->m_left = newp;
		}
		return true;
	}
	TreeNode<T>* find(const T& val) {
		TreeNode<T>* cur = m_root;
		while (cur) {//先找要删哪个
			if (val > cur->m_data) {
				cur = cur->m_right;
			}
			else if (val < cur->m_data) {
				cur = cur->m_left;
			}
			else {
				return cur;
			}
		}
		return nullptr;
	}
	bool erase(const T& val) {
		TreeNode<T>* pre = m_root;
		TreeNode<T>* cur = m_root;
		while (cur) {//先找要删哪个
			if (val > cur->m_data) {
				pre = cur;
				cur = cur->m_right;
			}
			else if (val < cur->m_data) {
				pre = cur;
				cur = cur->m_left;
			}
			else {
				break;
			}
		}
		if (cur == nullptr) {//没找到则说明没有这个节点
			return false;
		}
		if (cur->m_left == nullptr) {//左右孩子都为空或者左孩子为空两种情况(情况1+情况2)
			if (cur == m_root) {
				m_root = cur->m_right;
			}
			else {
				if (cur == pre->m_left) {
					pre->m_left = cur->m_right;
				}
				else {
					pre->m_right = cur->m_right;
				}
			}
		}
		else if (cur->m_right == nullptr) {//右孩子为空(情况3)
			if (cur == m_root) {
				m_root = cur->m_left;
			}
			else {
				if (cur == pre->m_right) {
					pre->m_right = cur->m_left;
				}
				else {
					pre->m_left = cur->m_left;
				}
			}
		}
		else {//左右孩子都不为空(情况4)(指针替换, 提高性能)
			TreeNode<T>* cur2 = cur->m_left;
			TreeNode<T>* pre2 = cur2;
			if (cur2->m_right) {
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
				//找到要删除节点的左孩子的最右子孙, 让其代替要删除节点
				//也就是中序的第一个节点
				pre2->m_right = cur2->m_left;//将自己的左孩子托付给父亲, 让父亲把他作为右孩子
				cur2->m_left = cur->m_left;
			}
			cur2->m_right = cur->m_right;
			if (cur == m_root) {
				m_root = cur2;
			}
			else {
				if (cur == pre->m_left) {
					pre->m_left = cur2;
				}
				else {
					pre->m_right = cur2;
				}
			}
		}
		delete cur;
		return true;
	}
};

template<class T>
class Print {
public:
	void InorderPrint(TreeNode<T>* root) {
		stack<TreeNode<T>*> s;
		vector<T> res;
		TreeNode<T>* cur = root;
		if (!cur) {
			cout << "空树\n";
			return;
		}
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