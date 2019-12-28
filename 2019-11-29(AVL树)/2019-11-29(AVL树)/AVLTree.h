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

	void rRound(TreeNode<T>* pre) {//右单旋
		TreeNode<T>* cur = pre->m_left;

		cur->m_parent = pre->m_parent;
		if (pre->m_parent) {//如果pre的父节点存在
			if (pre == pre->m_parent->m_left) {
				pre->m_parent->m_left = cur;
			}
			else {
				pre->m_parent->m_right = cur;
			}
		}
		else {//如果pre的父节点不存在, 说明pre是根节点root
			m_root = cur;
		}

		pre->m_left = cur->m_right;
		if (cur->m_right) {//如果存在, 让其父节点指向pre
			cur->m_right->m_parent = pre;
		}
		cur->m_right = pre;
		pre->m_parent = cur;

		pre->m_bf = cur->m_bf = 0;
	}

	void lRound(TreeNode<T>* pre) {//左单旋
		TreeNode<T>* cur = pre->m_right;

		cur->m_parent = pre->m_parent;
		if (pre->m_parent) {//如果pre的父节点存在
			if (pre == pre->m_parent->m_left) {
				pre->m_parent->m_left = cur;
			}
			else {
				pre->m_parent->m_right = cur;
			}
		}
		else {//如果pre的父节点不存在, 说明pre是根节点root
			m_root = cur;
		}

		pre->m_right = cur->m_left;
		if (cur->m_left) {//如果存在, 让其父节点指向pre
			cur->m_left->m_parent = pre;
		}
		cur->m_left = pre;
		pre->m_parent = cur;

		pre->m_bf = cur->m_bf = 0;
	}

	void lrRound(TreeNode<T>* pre) {//左右双旋
		TreeNode<T>* cur = pre->m_left;
		TreeNode<T>* cur_right = cur->m_right;
		int flag = cur_right->m_bf;

		lRound(cur);
		rRound(pre);

		//当左右双旋完成后, cur_right, pre, cur的平衡因子都变为0
		//cur_right本该就为0, 所以无需更改, 但pre和cur是否为0还要视情况而定
		if (flag == 1) {
			cur->m_bf = -1;//pre->m_bf == 0
		}
		else {
			pre->m_bf = 1;//cur->m_bf == 0
		}
	}

	void rlRound(TreeNode<T>* pre) {//右左双旋
		TreeNode<T>* cur = pre->m_right;
		TreeNode<T>* cur_left = cur->m_left;
		int flag = cur_left->m_bf;

		rRound(cur);
		lRound(pre);

		//当左右双旋完成后, cur_right, pre, cur的平衡因子都变为0
		//cur_left本该就为0, 所以无需更改, 但pre和cur是否为0还要视情况而定
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

		//先按照二叉搜索的插入方式先插, 若是不平衡, 则调整
		if (val < pre->m_data) {
			pre->m_left = newp;
		}
		else {
			pre->m_right = newp;
		}
		newp->m_parent = pre;//父节点也需要指向

		cur = newp;//使cur指向新节点, pre是其父节点, 之后一直保持pre是cur的父节点
		while (pre) {//到根节点则不能再向上判断, 则说明插入后无需调整
			if (pre->m_left == cur) {
				pre->m_bf--;
			}
			else {
				pre->m_bf++;
			}
			if (pre->m_bf == 0) {//如果插入后, 其父节点平衡因子变为0
				//所以往上所有的平衡因子都不会发生变化, 所以插入后平衡, 无需调整
				break;
			}
			else if (pre->m_bf == -1 || pre->m_bf == 1) {//继续往上找
				cur = pre;
				pre = pre->m_parent;
			}
			else if (pre->m_bf == -2) {
				if (cur->m_bf == -1) {//右单旋
					rRound(pre);
				}
				else {//m_bf == 1, 左右双旋
					lrRound(pre);
				}
				break;
			}
			else if (pre->m_bf == 2) {
				if (cur->m_bf == 1) {//左单旋
					lRound(pre);
				}
				else {//m_bf == -1, 右左双旋
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
				pre = cur;//不能放在if外面
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
			if (cur == m_root) {//cur为根节点
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