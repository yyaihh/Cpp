#include<iostream>
#include"Circilar_queue.h"
int main() {
	Circularqueue<int> cq(10);
	for (int i = 0; i < 10; ++i) {
		cq.push(i + 1);
	}
	int tmp;
	for (int i = 0;!cq.empty(); ++i) {
		tmp = cq.front();
		cout << tmp << ' ';
		cq.pop();
		cq.push(tmp);
	}
	system("pause");
	return 0;
}
