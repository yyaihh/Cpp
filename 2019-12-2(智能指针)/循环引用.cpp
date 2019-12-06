#include<iostream>
#include<memory>
using namespace std;
class ListNode {
	int m_data;
public:
	weak_ptr<ListNode> m_prev;
	weak_ptr<ListNode> m_next;
	~ListNode() {
		cout << "~ListNode()" << endl; 
	}
};
void test9() {
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->m_next = node2;
	node2->m_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
}
int main() {
	test9();
	system("pause");
	return 0;
}