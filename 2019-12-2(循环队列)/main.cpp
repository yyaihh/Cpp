#include<iostream>
#include"Circilar_queue.h"
int main() {
	Circularqueue<int> cq(10);
	for (int i = 0; i < 10; ++i) {
		cq.push(i + 1);
	}
	for (int i = 0; i < 10; ++i) {
		cout << cq.front() << ' ';
		cq.pop();
	}
	return 0;
}