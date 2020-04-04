#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
    vector<TreeNode*>* pv;
    void judge(TreeNode* root) {
        if (root) {
			judge(root->left);
			pv->push_back(root);
			judge(root->right);
		}
	}
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree == nullptr) return nullptr;
        vector<TreeNode*> v;
        pv = &v;
        judge(pRootOfTree);
        int size = v.size() - 1, i;
        for(i = 0; i < size ; ++i){
            v[i]->right = v[i + 1];
        }
        v[i]->right = nullptr;
        for(i = size; i > 0; --i){
            v[i]->left = v[i - 1];
        }
        v[i]->left = nullptr;
        return v[0];
    }
};

int main() {
	TreeNode* a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = new TreeNode(i);
	}
	a[5]->left = a[3];
	a[3]->right = a[4];
	a[3]->left = a[2];
	a[2]->left = a[0];
	a[0]->right = a[1];
	a[5]->right = a[8];
	a[8]->left = a[6];
	a[6]->right = a[7];
	a[8]->right = a[9];
	TreeNode* head = a[5];
	Solution s;
	s.Convert(head);
	return 0;
}
