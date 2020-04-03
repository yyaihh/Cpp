#include<iostream>
#include<unordered_map>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
	unordered_map<RandomListNode*, RandomListNode*>* pum;
	void judge(RandomListNode* pHead, RandomListNode* Head) {
		RandomListNode* p, *q;
		if (pHead == nullptr) return;
		for (p = pHead, q = Head; p->random; p = p->random, q = q->random) {
			if (pum->find(p->random) == pum->end()) {
				q->random = new RandomListNode(p->random->label);
			}
			else {
				q->random = (*pum)[p->random];
				break;
			}
		}
		judge(pHead->next, Head->next);
	}

public:
	RandomListNode* Clone(RandomListNode* pHead) {
		if (pHead == nullptr) return nullptr;
		unordered_map<RandomListNode*, RandomListNode*> um;
		pum = &um;
		RandomListNode* Head = new RandomListNode(pHead->label);
		for (RandomListNode* p = pHead->next, *head = Head; p; p = p->next, head = head->next) {
			head->next = new RandomListNode(p->label);
			um[p] = head->next;
		}
		judge(pHead, Head);
		return Head;
	}
};


int main() {
	RandomListNode* a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = new RandomListNode(i + 1);
	}
	for (int i = 0; i < 9; ++i) {
		a[i]->next = a[i + 1];
	}
	a[0]->random = new RandomListNode(-1);
	a[1]->random = new RandomListNode(-2);
	a[1]->random->random = a[5];
	Solution s;
	RandomListNode* head = s.Clone(a[0]);
	return 0;
}