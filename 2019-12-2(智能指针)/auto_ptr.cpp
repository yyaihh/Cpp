#include<iostream>
#include<memory>
using namespace std;
class A {
public:
	int m_data;
	~A() {
		cout << "Îö¹¹\n";
	}
};
int main3() {
	auto_ptr<A> ap(new A[100]);
	return 0;
}