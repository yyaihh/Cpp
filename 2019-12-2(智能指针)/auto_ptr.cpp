#include<iostream>
#include<memory>
using namespace std;
class A {
public:
	int m_data;
};
int main() {
	//auto_ptr<A> ap(new A);
	//ap->m_data = 10;
	//cout << ap->m_data << endl;
	//auto_ptr<A> ap2(ap);
	//cout << ap2->m_data << endl;
	//auto_ptr<A> ap3;
	//ap3 = ap2;
	//cout << ap3->m_data << endl;
	//cout << ap2->m_data << endl;
	//cout << ap->m_data << endl;
	int* p = new int[100];
	auto_ptr<int> ap(p);
	return 0;
}