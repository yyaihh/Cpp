#pragma once
#include<vector>
using namespace std;
enum State {
	EMPTY,
	EXIST,
	DELETE
};
class dealInt {
public:
	int operator()(const int key) {
		return key;
	}
};
template <class K, class V, class SW = dealInt>
class HashTable {
	struct elem {//哈希表元素, pair包含键值与数据, m_state为标志位
		pair<K, V> m_val;
		State m_state;

		elem(const K& key = K(), const V& val = V(), State state = EMPTY) :
			m_val(key, val),
			m_state(state)
		{}
	};
	vector <elem> m_table;
	size_t m_size;
	static long long s_m_primeTable[30];
	int m_prime;
	//并没有记录哈希表的capacity的值, 因为m_table的size值就为其容量, 详见构造函数

	size_t HashFun(const K& key) {//哈希函数,使用除留余数法
		return SW()(key) % capacity();//仿函数先求出能够计算的整型(因为key值不一定是整型)
	}

	void reserve() {
		vector<elem> tmp;
		m_table.swap(tmp);
		m_table.resize(s_m_primeTable[++m_prime]);
		m_size = 0;//交换后的m_table的为空

		for (auto& e : tmp) {
			if (e.m_state == EXIST) {
				insert(e.m_val);
			}
		}
	}

public:
	HashTable(size_t capacity = s_m_primeTable[0]) :
		m_table(capacity),
		m_size(0),
		m_prime(0)
	{}

	size_t capacity() {
		return m_table.size();
	}

	bool insert(const pair<K, V>& val) {
		if (m_size * 10 / capacity() > 7) {//数据所占总容量70%以上时, 需要扩容
			//因为此时哈希冲突发生的概率变得非常大, 所以需要扩容
			reserve();
		}
		int k = HashFun(val.first);

		while (m_table[k].m_state == EXIST) {//若发生冲突, 此处运用线性探测法解决
			//即, 依次往后找, 知道找到空位置
			if (m_table[k].m_val == val) {//若已有相同的, 即插入失败
				return false;
			}
			++k;
			if (k == capacity()) {//当找到最后(最后已经判断完), 需要重头再来
				k = 0;
			}//此处不会出现重复循环判断的, 因为在70%时就会扩容, 所以一定会有空闲的位置
		}

		m_table[k].m_val = val;
		m_table[k].m_state = EXIST;
		++m_size;
		return true;
	}

	int find(const K& key) {
		int k = HashFun(key);
		while (m_table[k].m_state != EMPTY) {//如果等于空直接跳出循环, 没找到返回-1
			if (m_table[k].m_state == EXIST && m_table[k].m_val.first == key) {
				return k;
			}
			++k;

			if (k == capacity()) {
				k = 0;
			}
		}
		return -1;
	}

	bool erase(const K& key) {
		int k = find(key);//先找有没有

		if (k != -1) {//有
			--m_size;
			m_table[k].m_state = DELETE;
			return true;
		}

		return false;//没有则删除失败
	}

	size_t size() {
		return m_size;
	}

	bool empty() {
		return m_size == 0;
	}

	void Swap(const HashTable& ht) {
		m_table.swap(ht.m_table);
		size_t tmp = m_size;
		m_size = ht.m_size;
		ht.m_size = tmp;
	}
	void clear() {
		m_size = 0;
		m_table.clear();
		m_table.resize(s_m_primeTable[0]);
		m_prime = 0;
	}
};
template <class K, class V, class SW>
long long HashTable<K, V, SW>::s_m_primeTable[30] = {
		11,         23,         47,         89,        179,
		353,        709,       1409,       2819,       5639,
		11273,      22531,      45061,      90121,     180233,
		360457,     720899,    1441807,    2883593,    5767169,
		11534351,   23068673,   46137359,   92274737,  184549429,
		369098771,  738197549, 1476395029, 2952790016u, 4294967291u 
};