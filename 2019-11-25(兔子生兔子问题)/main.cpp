#include<iostream>
using namespace std;
class Solution {
public:
	static long fun(int num) {
		long m_sum2 = 0, m_sum1 = 1;
		int tmp;
		for (int i = 1; i < num; ++i) {
			tmp = m_sum2;
			m_sum2 += m_sum1;
			m_sum1 = tmp;
		}
		return m_sum1 + m_sum2;
	}
};
int main() {
	int num;
	while (cin >> num) {
		cout << Solution::fun(num) << endl;
	}
	system("pause");
	return 0;
}