#include<iostream>
#include<vector>
using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
}TreeNode;

class Solution {
	vector <vector<int>>* vv;
	int sum;
	vector<int> v;		
public:
	vector<vector<int> > FindPath(TreeNode* root, int num) {
		vector<vector<int>> res;
		vv = &res;
		sum = num;
		return res;
	}
	void judge(TreeNode* root, vector<int> path) {
		if (root == nullptr) return;
		path.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			for (auto& i : path) {
				cout << i << ' ';
			}
			cout << endl;
		}
		judge(root->left, path);
		judge(root->right, path);
	}
};

int main() {
	Solution s;
	TreeNode root(1);
	TreeNode a(2);
	TreeNode b(3);
	TreeNode c(4);
	TreeNode d(5);
	TreeNode e(6);
	root.left = &a;
	root.right = &b;
	a.left = &c;
	b.left = &d;
	b.right = &e;
	vector<int> path;
	s.judge(&root, path);
	return 0;
}