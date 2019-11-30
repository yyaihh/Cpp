#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int StrToInt(string& str) {
		if (str.empty()) {
			return 0;
		}
		int flag = 1;//正负标签
		auto i = str.begin();
		if (*i == '-') {
			flag = -1;
			++i;
		}
		else if (*i == '+') {
			++i;
		}
		long long tmp = 0;
		double max = pow(2, 31) - 1;
		double min = -pow(2, 31);
		auto end = str.end();
		for (; i < end; ++i) {
			if (*i > '9' || *i < '0') {
				return 0;
			}
			tmp = (int)*i - 48 + tmp * 10;
		}
		tmp = flag * tmp;
		if (tmp < min) {
			return 0;
		}
		if (tmp > max) {
			return 0;
		}
		return (int)tmp;
	}
};
class UnusualAdd {
	pair<string, string> fun(int A, int B) {
		string tmp;
		if (A < 0) {
			A = -A;
		}
		if (B < 0) {
			B = -B;
		}
		while (A) {
			tmp += (A % 10 + '0');
			A /= 10;
		}
		string a(tmp.rbegin(), tmp.rend());
		tmp.clear();
		while (B) {
			tmp += (B % 10 + '0');
			B /= 10;
		}
		string b(tmp.rbegin(), tmp.rend());
		pair<string, string> p;
		p.first = a;
		p.second = b;
		return p;
	}
public:
	int addAB(int A, int B) {
		if (A == 0) {
			return B;
		}
		if (B == 0) {
			return A;
		}
		Solution f;
		pair<string, string> p = fun(A, B);
		string num1=p.first;
		string num2=p.second;
		string stmp, res;
		string nummax = num1;
		string nummin = num2;
		int leftmax = 0, leftmin = 0;
		int rightmax = num1.size() - 1;
		int rightmin = num2.size() - 1;
		stmp.resize(rightmax + 3 + rightmin, '0');
		if (rightmax < rightmin) {
			swap(rightmax, rightmin);
			swap(leftmax, leftmin);
			swap(nummax, nummin);
		}
		int n = 0;
		int m = stmp.size() - 1;
		for (; rightmin >= leftmin; --rightmin, --rightmax, --m) {
			n = nummax[rightmax] + stmp[m] + nummin[rightmin] - 3 * '0';//相加结果
			stmp[m] = n % 10 + ' 0';
			stmp[m - 1] += n / 10;//进位
		}
		for (; rightmax >= leftmax; --rightmax, --m) {
			n = stmp[m] - '0' + nummax[rightmax] - '0';
			stmp[m] = n % 10 + '0';
			stmp[m - 1] += (n / 10);//进位
		}
		int i = 1, j = stmp.size();
		for (; (i < j) && (stmp[i] == '0'); ++i);
		if (i >= j) {
			return 0;
		}

		for (; i < j; ++i) {
			res.push_back(stmp[i]);
		}
		auto end = res.rend();
		int num = 0;
		int mm = 1;
		for (auto i = res.rbegin(); i != end; ++i,mm*=10) {
			num += (*i - '0')*mm;
		}
		return num;
	}
};


int main() {
	int A, B;
	cin >> A >> B;
	UnusualAdd mul;
	cout << mul.addAB(A, B) << endl;
	system("pause");
	return 0;
}
