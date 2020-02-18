#pragma once
//增加迭代器版
#include<vector>
using namespace std;

template <class V>
class HashBucketNode {
public:
	V m_val;
	HashBucketNode * m_next;
	HashBucketNode(const V& val = V()) :
		m_val(val),
		m_next(nullptr)
	{}

	template<class K, class V, class KeyOfVal, class HF>
	friend class Iterator;

	template<class K, class V, class KeyOfVal, class HF>
	friend class HashBucket;
};
class dealInt {
public:
	int operator()(const int& key) {
		return key;
	}
};

template<class K, class V, class KeyOfVal, class HF = dealInt>
class Iterator {
public:
	HashBucket<K, V, KeyOfVal, HF>* m_hbpos;//直到桶在哪儿, 方便找上一个或下一个桶
	HashBucketNode<V>* m_node;//具体节点
	Iterator(HashBucket<K, V, KeyOfVal, HF>* hbpos = nullptr, HashBucketNode<V>* node = nullptr) :
		m_hbpos(hbpos),
		m_node(node)
	{}

	Iterator(const Iterator& it) :
		m_hbpos(it.m_hbpos),
		m_node(it.m_node)
	{}

	V& operator*() {
		return m_node->m_val;
	}

	V* operator->() {
		return &(m_node->m_val);
	}

	Iterator operator++() {
		HashBucketNode<V>* t = m_node;
		m_node = m_node->m_next;
		if (!m_node) {//为空
			size_t tmp = m_hbpos->HashFunc(KeyOfVal()(t->m_val)) + 1;//下一个桶的下标
			for (; tmp < m_hbpos->capacity(); ++tmp) {
				if (m_hbpos->m_table[tmp]) {
					m_node = m_hbpos->m_table[tmp];
					break;
				}
			}
		}
		return *this;
	}

	Iterator operator++(int) {
		Iterator tmp = *this;
		this->operator++();
		return tmp;
	}

	bool operator==(const Iterator& data) const {
		return m_node == data.m_node;
	}

	bool operator!=(const Iterator& data) const {
		return m_node != data.m_node;
	}
};
template<class K, class V, class KeyOfVal, class HF = dealInt>
class HashBucket {
	vector<HashBucketNode<V>*> m_table;
	size_t m_size;
	static long long s_m_primeTable[30];
	size_t m_primePos;

	template<class K, class V, class KeyOfVal, class HF>
	friend class Iterator;

	typedef Iterator<K, V, KeyOfVal, HF> Iterator;

	size_t HashFunc(const K& key) {
		return HF()(key) % capacity();
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
	HashBucket(const size_t capacity = s_m_primeTable[0]) :
		m_table(capacity, nullptr),
		m_size(0),
		m_primePos(0)
	{}

	~HashBucket() {
		clear();
	}

	size_t capacity() {
		return m_table.size();
		//return s_m_primeTable[m_primePos];
	}
	Iterator begin() {
		for (size_t i = 0; i < capacity(); ++i) {
			if (m_table[i]) {
				return Iterator(this, m_table[i]);
			}
		}
		return Iterator(this, nullptr);
	}
	Iterator end() {
		return Iterator(this, nullptr);
	}
	pair<Iterator, bool> insert(const V& val) {
		checkCapacity();//首先检查是否需要扩容
		int k = HashFunc(KeyOfVal()(val));
		HashBucketNode<V>* cur = m_table[k];
		while (cur) {
			if (KeyOfVal()(cur->m_val) == KeyOfVal()(val)) {
				return pair<Iterator, bool>(Iterator(this, cur), false);
			}
			cur = cur->m_next;
		}
		cur = new HashBucketNode<V>(val);
		cur->m_next = m_table[k];
		m_table[k] = cur;
		++m_size;
		return pair<Iterator, bool>(Iterator(this, m_table[k]), true);//因为是头插, 所以返回头
	}

	Iterator find(const K& Keyval) {
		int k = HashFunc(Keyval);
		HashBucketNode<V>* cur;
		for (cur = m_table[k]; cur; cur = cur->m_next) {
			if (KeyOfVal()(cur->m_val) == Keyval) {
				break;
			}
		}
		return Iterator(this, cur);
	}

	pair<Iterator, bool> erase(const K& Keyval) {
		Iterator f = find(Keyval);
		int n = HashFunc(Keyval);
		if (f.m_node) {
			Iterator tmp = f;
			if (m_table[n] == f.m_node) {
				m_table[n] = m_table[n]->m_next;
			}
			else {
				for (HashBucketNode<V>* cur = m_table[n]; cur->m_next; cur = cur->m_next) {
					if (cur->m_next == f.m_node) {
						cur->m_next = cur->m_next->m_next;
						break;
					}
				}
			}
			++tmp;
			delete f.m_node;
			--m_size;
			return pair<Iterator, bool>(tmp, true);
		}
		return pair<Iterator, bool>(Iterator(this, nullptr), false);
	}

	size_t size() {
		return m_size;
	}
	bool empty() {
		return 0 == m_size;
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

	/*1、Count 判断某一个Key值是否在哈希表里
	  2、BucketCount 返回桶的个数
	  3、BucketSize 返回某个桶中的元素个数*/
};
template<class K, class V, class KeyofValue, class HF>
long long HashBucket<K, V, KeyofValue, HF>::s_m_primeTable[30] = {
	11, 23, 47, 89, 179,
	353, 709, 1409, 2819, 5639,
	11273, 22531, 45061, 90121, 180233,
	360457, 720899, 1441807, 2883593, 5767169,
	11534351, 23068673, 46137359, 92274737, 184549429,
	369098771, 738197549, 1476395029, 2952790016u, 4294967291u
};
	