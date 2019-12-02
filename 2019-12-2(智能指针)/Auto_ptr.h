#pragma once
template<class T>
class AutoPtr {
	T* m_ptr;
public:
	AutoPtr(T* ptr = NULL)
		: m_ptr(ptr)
	{}
	~AutoPtr(){
		if (m_ptr)
			delete m_ptr;
	}
	// 一旦发生拷贝构造，就将ap中资源转移到当前对象中，然后另ap与其所管理的指针断开联系，
	// 这样就解决了一块空间被多个智能指针管理,最后析构而造成程序奔溃问题
	AutoPtr(AutoPtr<T>& ap)
		: m_ptr(ap.m_ptr) {
		ap.m_ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap) {
		// 检测是否为自己给自己赋值
		if (this != &ap){ //如果不是给自己赋值
			// 当前智能指针可能已经有管理的指针了. 就先释放当前所管理指针所指内存
			if (m_ptr)
				delete m_ptr;
			// 转移ap中资源到当前对象中
			m_ptr = ap.m_ptr;
			ap.m_ptr = nullptr;
		}
		return *this;
	}
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
};