#include"HashBucket.h"
using namespace std;
namespace gh {
	template <class K, class V, class HF = dealInt>
	class unordered_map {
		typedef pair<K, V>  ValueType;
		class KeyOfVal {
		public:
			const K& operator()(const ValueType& V) {
				return V.first;
			}
		};
		typedef HashBucket<K, V, KeyOfVal, HF> HB;
		HB m_data;
	public:
		typedef Iterator<K, V, KeyOfVal, HF> iterator;
		unordered_map() :m_data(HB()) {}
		iterator begin() {
			return m_data.begin();
		}
		iterator end() {
			return m_data.end();
		}
		size_t size() {
			return m_data.size();
		}
		bool empty() {
			return m_data.empty();
		}
		pair<iterator, bool> insert(const pair<K, V>& val) {
			iterator tmp(insert(val.second));
			if (!tmp.m_node) {
				return pair<iterator, bool>(tmp, true);
			}
			return pair<iterator, bool>(tmp, false);
		}
		pair<iterator, bool> erase(const K& Keyval) {
			return pair<iterator, bool>(m_data.erase(pair<K,V>))
		}
	};
};