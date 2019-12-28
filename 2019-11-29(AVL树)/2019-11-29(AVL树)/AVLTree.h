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
	int m_bf;//ƽ������
public:
	TreeNode(const T& data = T())
		:m_data(data), m_left(nullptr), m_bf(0),
		m_right(nullptr), m_parent(nullptr)
	{}
	template <class T>
	friend class AVLTtree;

	template <class T>
	friend class Print;
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

	void rRound(TreeNode<T>* pre) {//�ҵ���
		TreeNode<T>* cur = pre->m_left;

		cur->m_parent = pre->m_parent;
		if (pre->m_parent) {//���pre�ĸ��ڵ����
			if (pre == pre->m_parent->m_left) {
				pre->m_parent->m_left = cur;
			}
			else {
				pre->m_parent->m_right = cur;
			}
		}
		else {//���pre�ĸ��ڵ㲻����, ˵��pre�Ǹ��ڵ�root
			m_root = cur;
		}

		pre->m_left = cur->m_right;
		if (cur->m_right) {//�������, ���丸�ڵ�ָ��pre
			cur->m_right->m_parent = pre;
		}
		cur->m_right = pre;
		pre->m_parent = cur;

		pre->m_bf = cur->m_bf = 0;
	}

	void lRound(TreeNode<T>* pre) {//����
		TreeNode<T>* cur = pre->m_right;

		cur->m_parent = pre->m_parent;
		if (pre->m_parent) {//���pre�ĸ��ڵ����
			if (pre == pre->m_parent->m_left) {
				pre->m_parent->m_left = cur;
			}
			else {
				pre->m_parent->m_right = cur;
			}
		}
		else {//���pre�ĸ��ڵ㲻����, ˵��pre�Ǹ��ڵ�root
			m_root = cur;
		}

		pre->m_right = cur->m_left;
		if (cur->m_left) {//�������, ���丸�ڵ�ָ��pre
			cur->m_left->m_parent = pre;
		}
		cur->m_left = pre;
		pre->m_parent = cur;

		pre->m_bf = cur->m_bf = 0;
	}

	void lrRound(TreeNode<T>* pre) {//����˫��
		TreeNode<T>* cur = pre->m_left;
		TreeNode<T>* cur_right = cur->m_right;
		int flag = cur_right->m_bf;

		lRound(cur);
		rRound(pre);

		//������˫����ɺ�, cur_right, pre, cur��ƽ�����Ӷ���Ϊ0
		//cur_right���þ�Ϊ0, �����������, ��pre��cur�Ƿ�Ϊ0��Ҫ���������
		if (flag == 1) {
			cur->m_bf = -1;//pre->m_bf == 0
		}
		else {
			pre->m_bf = 1;//cur->m_bf == 0
		}
	}

	void rlRound(TreeNode<T>* pre) {//����˫��
		TreeNode<T>* cur = pre->m_right;
		TreeNode<T>* cur_left = cur->m_left;
		int flag = cur_left->m_bf;

		rRound(cur);
		lRound(pre);

		//������˫����ɺ�, cur_right, pre, cur��ƽ�����Ӷ���Ϊ0
		//cur_left���þ�Ϊ0, �����������, ��pre��cur�Ƿ�Ϊ0��Ҫ���������
		if (flag == 1) {
			pre->m_bf = -1;//cur->m_bf == 0
		}
		else {
			cur->m_bf = 1;//pre->m_bf == 0
		}
	}
public:
	AVLTtree()
		:m_root(nullptr)
	{}
	~AVLTtree() {
		destroy(m_root);
	}
	TreeNode<T>* getroot() {
		return m_root;
	}
	bool insert(const T val) {
		TreeNode<T>* newp = new TreeNode<T>(val);
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

		//�Ȱ��ն��������Ĳ��뷽ʽ�Ȳ�, ���ǲ�ƽ��, �����
		if (val < pre->m_data) {
			pre->m_left = newp;
		}
		else {
			pre->m_right = newp;
		}
		newp->m_parent = pre;//���ڵ�Ҳ��Ҫָ��

		cur = newp;//ʹcurָ���½ڵ�, pre���丸�ڵ�, ֮��һֱ����pre��cur�ĸ��ڵ�
		while (pre) {//�����ڵ������������ж�, ��˵��������������
			if (pre->m_left == cur) {
				pre->m_bf--;
			}
			else {
				pre->m_bf++;
			}
			if (pre->m_bf == 0) {//��������, �丸�ڵ�ƽ�����ӱ�Ϊ0
				//�����������е�ƽ�����Ӷ����ᷢ���仯, ���Բ����ƽ��, �������
				break;
			}
			else if (pre->m_bf == -1 || pre->m_bf == 1) {//����������
				cur = pre;
				pre = pre->m_parent;
			}
			else if (pre->m_bf == -2) {
				if (cur->m_bf == -1) {//�ҵ���
					rRound(pre);
				}
				else {//m_bf == 1, ����˫��
					lrRound(pre);
				}
				break;
			}
			else if (pre->m_bf == 2) {
				if (cur->m_bf == 1) {//����
					lRound(pre);
				}
				else {//m_bf == -1, ����˫��
					rlRound(pre);
				}
				break;
			}
		}
		return true;
	}
	bool erase(const T &val) {
		TreeNode<T>* cur = m_root;
		TreeNode<T>* pre = m_root;
		while (cur) {
			if (val < cur->m_data) {
				//pre->m_bf++;
				pre = cur;//���ܷ���if����
				cur = cur->m_left;
			}
			else if (val > cur->m_data) {
				//pre->m_bf--;
				pre = cur;
				cur = cur->m_right;
			}
			else {
				break;
			}
		}

		if (cur == nullptr) {
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
			if (cur == m_root) {//curΪ���ڵ�
				m_root = cur->m_left;
			}
			else {
				if (cur->m_data > pre->m_data) {
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