#include<iostream>

using namespace std;
template<class T, size_t N = 10>
class Array {
	T m_array[N];
	size_t m_size;
public:
	Array() :m_size(N) {}
	T& operator[](size_t index) {
		return m_array[index];
	}
	const T& operator[](size_t index)const {
		return m_array[index];
	}
	size_t size()const {
		return m_size;
	}
	bool empty()const {
		return 0 == m_size;
	}
};
class Test {
public:
	template<class T, size_t N = 10>
	void Solution(Array<T,N>& a) {
		int size = a.size();
		for (int i = 0; i < size; ++i) {
			a[i] = i + 1;
		}
		for (int i = 0; i < size; ++i) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
};
int main_() {
	Test test;
	Array<int> a;
	Array<int, 15> b;
	const int N = 12;
	Array<int, N> c;
	test.Solution(a);
	test.Solution(b);
	test.Solution(c);
	system("pause");
	return 0;
}