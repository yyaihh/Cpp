#pragma once
#include<vector>
using namespace std;

template <class V>
class HashBucketNode {
	V m_val;
	HashBucketNode * m_next;

	HashBucketNode(const V& val = V()) :
		m_val(val),
		m_next(nullptr)
	{}

	template <class V, class HF>
	friend class HashSet;
};

class dealInt {
public:
	int operator()(const int& key) {
		return key;
	}
};

template<class V, class HF = dealInt>
class HashSet{
	vector<HashBucketNode<V>*> m_table;
	size_t m_size;
	static long long s_m_primeTable[30];
	size_t m_primePos;

	size_t HashFunc(const V& val) {
		return HF()(val) % capacity();
	}

	void checkCapacity() {
		int oldcapacity = capacity();
		if (oldcapacity == m_size) {//此时哈希冲突发生概率100%, 此时扩容
			vector<HashBucketNode<V>*> tmp(s_m_primeTable[++m_primePos]);
			m_table.swap(tmp);
			m_size = 0;

			for (auto e : tmp) {
				for (; e; e = e->m_next) {
					insert(e->m_val);
				}
			}
		}
	}

public:
	HashSet(const size_t capacity = s_m_primeTable[0]) :
		m_table(capacity),
		m_size(0),
		m_primePos(0)
	{}
	~HashSet() {
		clear();
	}
	size_t capacity() {
		return m_table.size();
		//return s_m_primeTable[m_primePos];
	}

	bool insert(const V& val) {
		checkCapacity();//首先检查是否需要扩容
		int k = HashFunc(val);
		HashBucketNode<V>* cur = m_table[k];
		while (cur) {
			if (cur->m_val == val) {
				return false;
			}
			cur = cur->m_next;
		}
		cur = new HashBucketNode<V>(val);
		cur->m_next = m_table[k];
		m_table[k] = cur;
		++m_size;
		return true;
	}

	int find(const V& val) {
		int k = HashFunc(val);
		for (HashBucketNode<V>* cur = m_table[k]; cur; cur = cur->m_next) {
			if (cur->m_val == val) {
				return k;
			}
		}
		return -1;
	}

	bool erase(const V& val) {
		int n = find(val);
		HashBucketNode<V>* tmp = nullptr;
		if (n != -1) {//找到了, 可以删
			if (m_table[n]->m_val == val) {
				tmp = m_table[n];
				m_table[n] = m_table[n]->m_next;
			}
			else {
				for (HashBucketNode<V>* cur = m_table[n]; cur->m_next; cur = cur->m_next) {
					if (cur->m_next->m_val == val) {
						tmp = cur->m_next;
						cur->m_next = cur->m_next->m_next;
						break;
					}
				}
			}
			--m_size;
			delete tmp;
			return true;
		}
		return false;
	}

	size_t size() {
		return m_size;
	}

	void clear() {
		HashBucketNode<V>* tmp;
		m_size = 0;
		for (auto head : m_table) {
			while (head) {
				tmp = head;
				head = head->m_next;
				delete tmp;
			}
		}
		for (auto& e : m_table) {
			e = nullptr;
		}
	}
};

template<class V, class SW>
long long HashSet<V, SW>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u
};