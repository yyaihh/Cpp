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
		typedef HashBucket<K, ValueType, KeyOfVal, HF> HB;
		HB m_data;
	public:
		typedef Iterator<K, ValueType, KeyOfVal, HF> iterator;
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
		void clear() {
			m_data.clear();
		}
		pair<iterator, bool> insert(const ValueType& val) {
			return m_data.insert(val);
		}
		pair<iterator, bool> erase(const K& Keyval) {
			return m_data.erase(Keyval);
		}
		iterator find(const K& Keyval) {
			return m_data.find(Keyval);
		}
		V& operator[](const K& key) {
			/*pair<iterator, bool> tmp = insert(ValueType(key, V()));
			iterator tmp2 = tmp.first;
			return (*tmp2).second;*/
			return (*insert(ValueType(key, V())).first).second;
		}
		const V& operator[](const K& key) const {
			return (*insert(ValueType(key, V())).first).second;
		}
		size_t bucket_count()const {//返回哈希桶中桶的个数
			return m_data.bucket_count();
		}
		size_t bucket_size(size_t n)const {//返回n号桶中的元素个数
			return m_data.bucket_size(n);
		}
		size_t bucket(const K& key) {//返回key对应几号桶
			return m_data.bucket(key);
		}
	};
};