#include<list>
#include<vector>
using namespace std;
template<class T>
class Circularqueue {
	list<T> m_data; 
	int m_size;
public:
	Circularqueue(int n) 
		:m_size(n) 
	{}
	bool push(const T& value) {
		if (m_data.size() == m_size) {
			return false;
		}
		m_data.push_back(value);
		return true;
	}
	void pop() {
		m_data.pop_front();
	}
	T& front() {
		return m_data.front();
	}
	T& rear() {
		return m_data.back();
	}
	bool empty() {
		return m_data.empty();
	}
	bool isfull() {
		return m_data.size() == m_size;
	}
};