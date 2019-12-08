#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/**
	 *  ����λ�϶�����������ż��λ�϶���ż��
	 *  ���룺����arr�����ȴ���2
	 *  len��arr�ĳ���
	 *  ��arr����������λ�϶�����������ż��λ�϶���ż��
	 */
	void oddInOddEvenInEven_(vector<int>& arr, int len) {
		for (int i = 0, j = 1; i < len&&j < len;) {
			if (arr[i] % 2 == 0) {//ż��λ����ż��
				i += 2;
				continue;
			}
			if (arr[j] % 2) {//����λ��������
				j += 2;
				continue;
			}
			swap(arr[i], arr[j]);//����λ��ż��, ż��λ������
		}
	}
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		int& end = arr[len - 1];
		while (i < len&&j < len) {
			if (end % 2 == 0) {
				swap(arr[i], end);
				i += 2;
			}
			else {
				swap(arr[j], end);
				j += 2;
			}
		}
	}
};
int main() {
	Solution s;
	int n;
	vector<int> v;
	while (cin >> n) {
		v.resize(n);
		for (auto& i : v) {
			cin >> i;
		}
		s.oddInOddEvenInEven(v, n);
		for (auto& i : v) {
			cout << i << ' ';
		}
	}
}