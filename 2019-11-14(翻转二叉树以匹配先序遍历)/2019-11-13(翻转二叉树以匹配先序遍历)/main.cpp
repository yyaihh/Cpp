#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
template<class T>
class TreeNode {
public:
	T val;
	TreeNode<T> *left;
	TreeNode<T> *right;
	TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};
template <class T>
class Tree
{
//	TreeNode<T> * m_root;

	static TreeNode<T> *  maketree(const T * val, const T & end, int &i)
	{
		if (val[i] == end)
		{
			i++;
			return nullptr;
		}

		TreeNode<T> * root = new TreeNode<T>(val[i]);
		i++;

		root->left = maketree(val, end, i);
		root->right = maketree(val, end, i);

		return root;
	}
public:
	TreeNode<T> * m_root;
	Tree() :
		m_root(nullptr)
	{

	}

	Tree(const T * val, const T & end)
	{
		int i = 0;
		m_root = maketree(val, end, i);
	}
};
class Solution {
	bool Swap(TreeNode<int>*& root) {
		/*if (!root->left || !root->right) {
			return false;
		}*/
		TreeNode<int>* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		return true;
	}
public:
	vector<int> flipMatchVoyage(TreeNode<int>* root, vector<int>& voyage) {
		vector<int> res;
		stack<TreeNode<int>*> s;
		bool flag = false;
		TreeNode<int>* f = root;
		if (root->val != voyage[0]) {
			res.push_back(-1);
			return res;
		}
		int size = voyage.size();

		for (int i = 1; root && i < size;) {
			f = root;
			if (root->right) s.push(root->right);
			if (root->left) s.push(root->left);
			if (s.empty()) {
				root = nullptr;
			}
			else {
				root = s.top();
				s.pop();
				//еп╤о
				if (root->val != voyage[i]) {
					if (flag) {
						res.clear();
						res.push_back(-1);
						return res;
					}
					flag = true;
					if (Swap(f)) {
						if (!s.empty())s.pop();
						root = f;
					}
					else {
						res.clear();
						res.push_back(-1);
						return res;
					}
				}
				else {
					if (flag) {
						flag = false;
						res.push_back(f->val);
					}
					++i;
				}
			}
		}
		return res;
	}
};
int main() {
	int a[] = { 30, 26, 11, 1, 13, 0, 8, 20, 19, 27, 3, 0, 7, 0, 0, 29, 25, 0, 6, 28, 0, 17, 18, 4, 0, 21, 23, 0, 0, 12, 0, 0, 10, 0, 0, 0, 0, 9, 5, 16, 2, 0, 0, 0, 0, 0, 0, 0, 15, 0, 22, 0, 0, 0, 14, 24 };
	int arr[] = { 30, 13, 8, 7, 17, 10, 18, 26, 11, 3, 28, 12, 27, 6, 1, 19, 29, 4, 25, 21, 5, 15, 14, 9, 23, 2, 16, 22, 24, 20 };
	Tree<int> root(a, 0);
	vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Solution p;
	for (auto i : p.flipMatchVoyage(root.m_root, v)) {
		cout << i << endl;
	}
	system("pause");
	return 0;
}
