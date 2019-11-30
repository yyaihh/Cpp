#include<iostream>
#include<string>
using namespace std;
class Date {
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int year, int month, int day)
		:m_year(year),
		m_month(month),
		m_day(day)
	{
	}
	bool operator==(Date& t) {
		if (&t == this) {
			return true;
		}
		return m_year == t.m_year && m_month == t.m_month && m_day == t.m_day;
	}
};
template<class T>
class Solution {
public:
	bool SIsEqual(T a, T b) {
		return a == b;
	}
};
template<class T>
class Solution <T*>{
public:
	bool SIsEqual(T* a, T* b) {
		return *a == *b;
	}
};
template<class T>
bool IsEqual(T a, T b) {
	Solution<T> f;
	return f.SIsEqual(a,b);
}
int main() {
	string s1 = "abc";
	string s2 = "abc";
	string s3 = "abcd";
	Date d1(2019, 10, 2);
	Date d2(2019, 10, 2);
	Date d3(2019, 10, 3);
	int num1 = 10, num2 = 10;
	IsEqual(s1, s2) ? cout << "s1==s2" << endl : cout << "s1!=s2" << endl;
	IsEqual(s1, s3) ? cout << "s1==s3" << endl : cout << "s1!=s3" << endl;
	IsEqual(d1, d2) ? cout << "d1==d2" << endl : cout << "d1!=d2" << endl;
	IsEqual(d1, d3) ? cout << "d1==d3" << endl : cout << "d1!=d3" << endl;
	IsEqual(num1,num2) ? cout << "num1==num2" << endl : cout << "num1!=num2" << endl;
	cout << endl;
	IsEqual(&s1, &s2) ? cout << "s1==s2" << endl : cout << "s1!=s2" << endl;
	IsEqual(&d1, &d2) ? cout << "d1==d2" << endl : cout << "d1!=d2" << endl;
	IsEqual(&num1, &num2) ? cout << "num1==num2" << endl : cout << "num1!=num2" << endl;
	system("pause");
	return 0;
}