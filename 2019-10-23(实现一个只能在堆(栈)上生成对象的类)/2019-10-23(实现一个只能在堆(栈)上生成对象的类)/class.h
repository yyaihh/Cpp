#pragma once
using namespace std;

class T1 {
	T1(int val):b(val) {

	}
	T1(T1& x):b(x.b){
		
	}
public:
	int b;
	static T1* newT1_p(int val = 0) {
		return new T1(val);
	}
	static T1& newT1(int val = 0) {
		return *new T1(val);
	}
};
class T2 {
	~T2() {
		delete this;
	}
public:
	int b;
	T2(int val = 0) :b(val) {

	}
	void Destroy() {
		this->~T2();
	}
};
class T3 {
	void* operator new(size_t val) {}
public:
	int a;
	T3(int val = 0) :a(val) {

	}
};