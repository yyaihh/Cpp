//���ӣ�https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
//��Դ��ţ����
//
//
//�����ַ�����abcfbc���͡�abfcab�������С�abc��ͬʱ�����������ַ����У���ˡ�abc�������ǵĹ��������С����⣬��ab������af���ȶ������ǵ��ִ���
//���ڸ������������ַ������������ո񣩣����æ�������ǵ�����������еĳ��ȡ�
//
//�������� :
//��������������ݡ�
//
//ÿ�����ݰ��������ַ���m��n�����ǽ�������ĸ�����ҳ��Ȳ�����1024��
//
//
//������� :
//��Ӧÿ�����룬�������������еĳ��ȡ�
//ʾ��1
//����
//abcfbc abfcab<br / >programming contest<br / >abcd mnp
//���
//4 < br / > 2 < br / > 0

// write your code here cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	static int fun(string& s1, string& s2) {
		int size1 = s1.size(), size2 = s2.size();
		vector<int> v(size2 + 1, 0);
		for (int i = 0, cur; i < size1; ++i) {
			for (int j = 1, old = v[0]; j <= size2; ++j) {
				cur = v[j];
				if (s1[i] == s2[j - 1]) {
					v[j] = max(v[j], old + 1);
				}
				else {
					v[j] = max(v[j], v[j - 1]);
				}
				old = v[j];
			}
		}
		return v[size2];
	}
};

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		cout << Solution::fun(s1, s2) << endl;
	}
	return 0;
}