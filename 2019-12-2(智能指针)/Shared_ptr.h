#pragma once
template<class T> 
class Shared_ptr {
	T* m_ptr;
	int* m_pRefCount;//���ü���
public:
	Shared_ptr(T* ptr = nullptr)
		:m_ptr(ptr),
		m_pRefCount(new int(1))
	{}
	~Shared_ptr() { Release(); }
	Shared_ptr(const Shared_ptr<T>& sp)
		: m_ptr(sp.m_ptr)
		, m_pRefCount(sp.m_pRefCount) 
	{
		AddRefCount();
	}
	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp){
		if (m_ptr != sp.m_ptr){
			Release();// �ͷŹ���ľ���Դ
			// ��������¶������Դ�����������ü���
			m_ptr = sp.m_ptr;
			m_pRefCount = sp.m_pRefCount;
			AddRefCount();
		}
		return *this;
	}
	void Release() {
		if (--(*m_pRefCount) == 0) {
			delete m_ptr;
			delete m_pRefCount;
		}
	}
	void AddRefCount() { ++(*m_pRefCount); }
	int UseCount() { return *m_pRefCount; }
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
	T* get() { return m_ptr; }
};