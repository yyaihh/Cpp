//#include<iostream>
//using namespace std;
//class A {
//	int m_a;
//public:
//	virtual void funcA() {
//		cout << "类A的funcA" << endl;
//	}
//	virtual void func() {
//		cout << "类A的func" << endl;
//	}
//};
//class B {
//public:
//	virtual void funcB() {
//		cout << "类B的funcB" << endl;
//	}
//	virtual void func() {
//		cout << "类B的func" << endl;
//	}
//};
//class C :public A, public B {
//public:
//	virtual void func() {
//		cout << "类C的func" << endl;
//	}
//	virtual void funcC() {
//		cout << "类C的funcC" << endl;
//	}
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[]) {
//	 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i) {
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main_() {
//	C c;
//	A a;
//	a.func();
//	VFPTR* vTableb = (VFPTR*)(*(int*)&a);
//	PrintVTable(vTableb);
//	vTableb = (VFPTR*)(*(int*)&c);
//	PrintVTable(vTableb);
//	system("pause");
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class A {
//	int m_a;
//public:
//	virtual void func() {
//		cout << "类A的func" << endl;
//	}
//	virtual int func1() {
//		cout << "类A的func1" << endl;
//		return 0;
//	}
//};
//class B :public A {
//public:
//	virtual void func() {
//		cout << "类B的func" << endl;
//	}
//	virtual void func2() {
//		cout << "类B的func2" << endl;
//	}
//};
//int main() {
//	A a1;
//	A a2;
//	B b;
//	system("pause");
//	return 0;
//}