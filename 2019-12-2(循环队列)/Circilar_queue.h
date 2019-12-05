#include<list>
#include<queue>
using namespace std;
template<class T>
class Circularqueue {
	deque<int> m_data;
	int m_size;
public:
	Circularqueue(int n)
		:m_size(n)
	{}
	int front() {
		if (m_data.empty()) return -1;
		return m_data.front();
	}
	int rear() {
		if (m_data.empty()) return -1;
		return m_data.back();
	}
	bool push(const T& value) {
		if (m_data.size() == m_size) {
			return false;
		}
		m_data.push_back(value);
		return true;
	}
	bool pop() {
		if (empty())return false;
		m_data.pop_front();
		return true;
	}
	bool empty() {
		return m_data.empty();
	}
};