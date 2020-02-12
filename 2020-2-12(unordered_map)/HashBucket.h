#pragma once
//增加迭代器版
#include<vector>
using namespace std;
namespace gh {
	template <class V>
	class HashBucketNode {
	public:
		V m_val;
		HashBucketNode * m_next;
		HashBucketNode(const V& val = V()) :
			m_val(val),
			m_next(nullptr)
		{}

		/*template<class K, class V, class KeyOfVal, class HF>
		friend class iterator;*/

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
	class iterator {
	public:
		HashBucket<K, V, KeyOfVal, HF>* m_hbpos;//哪个桶
		HashBucketNode<V>* m_node;//具体节点
		iterator(HashBucket<K, V, KeyOfVal, HF>* hbpos = nullptr, HashBucketNode<V>* node = nullptr) :
			m_hbpos(hbpos),
			m_node(node)
		{}

		iterator(const iterator& it) :
			m_hbpos(it.m_hbpos),
			m_node(it.m_node)
		{}

		V& operator*() {
			return m_node->m_val;
		}

		V* operator->() {
			return &(m_node->m_val);
		}

		iterator operator++() {
			size_t tmp = m_node->m_val;
			m_node = m_node->m_next;
			if (!m_node) {//为空
				tmp = m_hbpos->HashFunc(KeyOfVal()(tmp)) + 1;//下一个桶的下标
				for (; tmp < m_hbpos->capacity(); ++tmp) {
					if (m_hbpos->m_table[tmp]) {
						m_node = m_hbpos->m_table[tmp];
						break;
					}
				}
			}
			return *this;
		}

		iterator operator++(int) {
			iostream tmp = *this;
			this->operator++();
			return tmp;
		}

		bool operator==(const iterator& data) const{
			return m_node == data.m_node && m_hbpos == data.m_hbpos;
		}

		bool operator!=(const iterator& data) const{
			return m_node != data.m_node || m_hbpos != data.m_hbpos;
		}
	};
	template<class K, class V, class KeyOfVal, class HF = dealInt>
	class HashBucket {
		vector<HashBucketNode<V> *> m_table;
		size_t m_size;
		static long long s_m_primeTable[30];
		size_t m_primePos;

		template<class K, class V, class KeyOfVal, class HF>
		friend class iterator;
		typedef iterator<K, V, KeyOfVal, HF> iterator;

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
		iterator begin() {
			for (size_t i = 0; i < capacity(); ++i) {
				if (m_table[i]) {
					return iterator(this, m_table[i]);
				}
			}
			return iterator(this, nullptr);
		}
		iterator end() {
			return iterator(this, nullptr);
		}
		iterator insert(const V& val) {
			checkCapacity();//首先检查是否需要扩容
			int k = HashFunc(val);
			HashBucketNode<V>* cur = m_table[k];
			while (cur) {
				if (cur->m_val == val) {
					return iterator(nullptr, nullptr);
				}
				cur = cur->m_next;
			}
			cur = new HashBucketNode<V>(val);
			cur->m_next = m_table[k];
			m_table[k] = cur;
			++m_size;
			return iterator(this, m_table[k]);
		}

		iterator find(const V& val) {
			int k = HashFunc(KeyOfVal()(val));
			for (HashBucketNode<V>* cur = m_table[k]; cur; cur = cur->m_next) {
				if (cur->m_val == val) {
					return iterator(this, m_table[k]);
				}
			}
			return iterator(nullptr, nullptr);
		}

		iterator erase(const V& val) {
			iterator it = find(val);
			HashBucketNode<V>* tmp = nullptr, *cur = nullptr;
			if (it.m_node != nullptr) {//找到了, 可以删
				int n = HashFunc(KeyOfVal()(val));
				if (m_table[n]->m_val == val) {
					tmp = m_table[n];
					m_table[n] = m_table[n]->m_next;
				}
				else {
					for (cur = m_table[n]; cur->m_next; cur = cur->m_next) {
						if (cur->m_next->m_val == val) {
							tmp = cur->m_next;
							cur->m_next = cur->m_next->m_next;
							break;
						}
					
					}
				}
				iterator res(this, cur);
				if (cur) {
					++res;
				}
				--m_size;
				delete tmp;
				return res;
			}
			return iterator(nullptr, nullptr);
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
};