#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(const int v = 0) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
	TreeNode* _reConstructBinaryTree(int prebegin, int preend, int vinbegin, int vinend) {
		if (prebegin > preend || vinbegin > vinend) {
			return nullptr;
		}
		TreeNode* node = new TreeNode((*m_pre)[prebegin]);
		for (int i = vinbegin; i <= vinend; ++i) {
			if ((*m_pre)[prebegin] == (*m_vin)[i]) {
				node->left = _reConstructBinaryTree(prebegin + 1, prebegin + (i - vinbegin),
													vinbegin, i - 1);
				node->right = _reConstructBinaryTree(prebegin + (i - vinbegin) + 1, preend,
													i + 1, vinend);
			}
		}
		return node;
	}
	vector<int>* m_pre, *m_vin;
public:
	TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
		m_pre = &pre;
		m_vin = &vin;
		return _reConstructBinaryTree(0, pre.size() - 1, 0, vin.size() - 1);
	}
};


double Power(double b, int e) {
	double res = 1.0, tmp = b;
	if (e < 0) {
		tmp = 1 / b;
		e = -e;
	}
	for (; e; e >>= 1) {
		if (e & 1) {
			res = res * tmp;
		}
		tmp = tmp * tmp;
	}
	return res;
}

int main() {
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	Solution s;
	TreeNode* node = s.reConstructBinaryTree(pre, vin);
	double b;
	int e;
	while (cin >> b >> e) {
		cout << pow(b, e) << endl;
		cout << Power(b, e) << endl;
	}
	return 0;
}