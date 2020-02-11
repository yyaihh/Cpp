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
	struct elem {//��ϣ��Ԫ��, pair������ֵ������, m_stateΪ��־λ
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
	//��û�м�¼��ϣ���capacity��ֵ, ��Ϊm_table��sizeֵ��Ϊ������, ������캯��

	size_t HashFun(const K& key) {//��ϣ����,ʹ�ó���������
		return SW()(key) % capacity();//�º���������ܹ����������(��Ϊkeyֵ��һ��������)
	}

	void reserve() {
		vector<elem> tmp;
		m_table.swap(tmp);
		m_table.resize(s_m_primeTable[++m_prime]);
		m_size = 0;//�������m_table��Ϊ��

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
		if (m_size * 10 / capacity() > 7) {//������ռ������70%����ʱ, ��Ҫ����
			//��Ϊ��ʱ��ϣ��ͻ�����ĸ��ʱ�÷ǳ���, ������Ҫ����
			reserve();
		}
		int k = HashFun(val.first);

		while (m_table[k].m_state == EXIST) {//��������ͻ, �˴���������̽�ⷨ���
			//��, ����������, ֪���ҵ���λ��
			if (m_table[k].m_val == val) {//��������ͬ��, ������ʧ��
				return false;
			}
			++k;
			if (k == capacity()) {//���ҵ����(����Ѿ��ж���), ��Ҫ��ͷ����
				k = 0;
			}//�˴���������ظ�ѭ���жϵ�, ��Ϊ��70%ʱ�ͻ�����, ����һ�����п��е�λ��
		}

		m_table[k].m_val = val;
		m_table[k].m_state = EXIST;
		++m_size;
		return true;
	}

	int find(const K& key) {
		int k = HashFun(key);
		while (m_table[k].m_state != EMPTY) {//������ڿ�ֱ������ѭ��, û�ҵ�����-1
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
		int k = find(key);//������û��

		if (k != -1) {//��
			--m_size;
			m_table[k].m_state = DELETE;
			return true;
		}

		return false;//û����ɾ��ʧ��
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