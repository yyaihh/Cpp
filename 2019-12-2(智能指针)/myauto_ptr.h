#pragma once
#pragma once
template<class T>
class Auto_ptr {
	T* m_ptr;
public:
	Auto_ptr(T* ptr = nullptr)
		:m_ptr(ptr)
	{}
	~Auto_ptr() {
		if (m_ptr) {
			delete m_ptr;
			m_ptr = nullptr;
		}
	}
	T& operator*() {
		return *m_ptr;
	}
	T* operator->() {
		return m_ptr;
	}
};