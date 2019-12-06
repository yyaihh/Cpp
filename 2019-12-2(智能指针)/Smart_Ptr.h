#pragma once
template<class T>
class Smart_Ptr {
	T* m_ptr;
public:
	Smart_Ptr(T* ptr = nullptr)
		:m_ptr(ptr) 
	{}
	~Smart_Ptr() {
		if (m_ptr) {
			delete m_ptr;
			//m_ptr = nullptr;
		}
	}
	T& operator*() {
		return *m_ptr;
	}
	T* operator->() {
		return m_ptr;
	}
	T* get() {
		return m_ptr;
	}
};