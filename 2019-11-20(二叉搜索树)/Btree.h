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
	bool insert(const T& val) {//����
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
		}//ѭ������, ��û���ظ��ڵ�, ����Բ���, pre������Ҫ����λ�õĵĸ��ڵ�
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
		while (cur) {//����Ҫɾ�ĸ�
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
		while (cur) {//����Ҫɾ�ĸ�
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
		if (cur == nullptr) {//û�ҵ���˵��û������ڵ�
			return false;
		}
		if (cur->m_left == nullptr) {//���Һ��Ӷ�Ϊ�ջ�������Ϊ���������(���1+���2)
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
		else if (cur->m_right == nullptr) {//�Һ���Ϊ��(���3)
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
		else {//���Һ��Ӷ���Ϊ��(���4)(ָ���滻, �������)
			TreeNode<T>* cur2 = cur->m_left;
			TreeNode<T>* pre2 = cur2;
			if (cur2->m_right) {
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
				//�ҵ�Ҫɾ���ڵ�����ӵ���������, �������Ҫɾ���ڵ�
				//Ҳ��������ĵ�һ���ڵ�
				pre2->m_right = cur2->m_left;//���Լ��������и�������, �ø��װ�����Ϊ�Һ���
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
			cout << "����\n";
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