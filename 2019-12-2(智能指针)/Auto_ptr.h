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
	// һ�������������죬�ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap�����������ָ��Ͽ���ϵ��
	// �����ͽ����һ��ռ䱻�������ָ�����,�����������ɳ���������
	AutoPtr(AutoPtr<T>& ap)
		: m_ptr(ap.m_ptr) {
		ap.m_ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap) {
		// ����Ƿ�Ϊ�Լ����Լ���ֵ
		if (this != &ap){ //������Ǹ��Լ���ֵ
			// ��ǰ����ָ������Ѿ��й����ָ����. �����ͷŵ�ǰ������ָ����ָ�ڴ�
			if (m_ptr)
				delete m_ptr;
			// ת��ap����Դ����ǰ������
			m_ptr = ap.m_ptr;
			ap.m_ptr = nullptr;
		}
		return *this;
	}
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }
};