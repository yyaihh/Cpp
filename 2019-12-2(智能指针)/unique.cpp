#include<iostream>
#include<memory>
using namespace std;
class A {
public:
	int m_data;
	~A() {
		cout << "����\n";
	}
};
void deleter(A* p) {
	cout << "deletet����";
	delete[] p;
}
void test() {
	A* p = new A;
	unique_ptr<A> up1(p);
	unique_ptr<A> up2;
	unique_ptr<A> up3;
	up1->m_data = 10;

	//����unique_ptr& operator=(unique_ptr&& x);
	cout << "����unique_ptr& operator=(unique_ptr&& x)\n";
	up2 = unique_ptr<A>(new A);//����1

	cout << up1->m_data << endl;
	cout << up1.get() << endl;
	up3 = move(up1);//����2
	cout << up3->m_data << endl;
	cout << up1.get() << endl;

	//����unique_ptr& operator=(nullptr_t);
	cout << "����unique_ptr& operator=(nullptr_t)\n";
	up2 = nullptr; //ֻ��=nullptr, NULL, 0��ֵΪ0�ĳ���
	cout << up1.get() << endl;

	//ɾ������ʹ��
	cout << "ɾ������ʹ��\n";
	unique_ptr<A, void(*)(A*)> up4(new A[5], deleter);
	shared_ptr<A> sp(new A[4], deleter);
}
int main_() {
	test();
	system("pause");
 	return 0;
}