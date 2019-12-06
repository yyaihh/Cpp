#include<iostream>
#include<memory>
using namespace std;
class A {
public:
	int m_data;
	~A() {
		cout << "析构\n";
	}
};
void deleter(A* p) {
	cout << "deletet调用";
	delete[] p;
}
void test() {
	A* p = new A;
	unique_ptr<A> up1(p);
	unique_ptr<A> up2;
	unique_ptr<A> up3;
	up1->m_data = 10;

	//调用unique_ptr& operator=(unique_ptr&& x);
	cout << "调用unique_ptr& operator=(unique_ptr&& x)\n";
	up2 = unique_ptr<A>(new A);//情形1

	cout << up1->m_data << endl;
	cout << up1.get() << endl;
	up3 = move(up1);//情形2
	cout << up3->m_data << endl;
	cout << up1.get() << endl;

	//调用unique_ptr& operator=(nullptr_t);
	cout << "调用unique_ptr& operator=(nullptr_t)\n";
	up2 = nullptr; //只能=nullptr, NULL, 0等值为0的常量
	cout << up1.get() << endl;

	//删除器的使用
	cout << "删除器的使用\n";
	unique_ptr<A, void(*)(A*)> up4(new A[5], deleter);
	shared_ptr<A> sp(new A[4], deleter);
}
int main_() {
	test();
	system("pause");
 	return 0;
}