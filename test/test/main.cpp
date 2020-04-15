#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//#include<ctime>
using namespace std;
////class Solution {
////public:
////	double fun() {
////		srand(time(0));
////		double t = (rand() % 6 + 3);
////		return 36 + t / 10;
////	}
////};
////int main() {
////	Solution s;
////	while (1) {
////		printf("亲, 此次的体温是%.1f哦\n", s.fun());
////		printf("不满意按y再测一次哦\n");
////		char c;
////		cin >> c;
////		if (c != 'y' && c != 'Y') {
////			printf("记得按时测体温哦, 下次再见");
////			break;
////		}
////	}
////	return 0;
////}
//struct ListNode {
//	int data;
//	struct ListNode* next;
//	ListNode(int v = 0, ListNode* p = NULL) :data(v), next(p) {}
//};
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//	if (pListHead == NULL) {
//		return pListHead;
//	}
//	ListNode* old_head = pListHead;
//	ListNode* tmp = old_head->next;
//	while (old_head->next) {
//		old_head->next = tmp->next;
//		tmp->next = pListHead;
//		pListHead = tmp;
//		tmp = old_head->next;
//	}
//	ListNode* cur = pListHead;
//	int count = 1;
//	for (; cur; cur = cur->next) {
//		if (count == k) {
//			break;
//		}
//		++count;
//	}
//	return cur;
//}
//
//ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
//	ListNode* fast = pListHead;
//	ListNode* slow = pListHead;
//	int i;
//	for (i = 0; fast != NULL; i++) {
//		if (i >= k) {
//			slow = slow->next;
//		}
//		fast = fast->next;
//	}
//	return i < k ? NULL : slow;
//}
//void test() {
//	int a = 1;
//	cout << (a << 1) << endl;
//}
//class A {
//public:
//	void test2(int a) {
//		int b;
//	}
//	void  test(A * const p) {
//		int a;
//		A * const p1 = p;
//		//cout << &a << endl;
//		
//		//cout << this << endl;
//		//cout << p << endl;
//		cout << &p << endl;
//	}
//	void  test3(A * const p) {
//		int a;
//		A * const p1 = p;
//		//cout << &a << endl;
//
//		//cout << this << endl;
//		//cout << p << endl;
//		cout << &p << endl;
//	}
//};
//int main() {
//	test();
//	A a;
//	int n = 5;
//	int b[50];
//	a.test(&a);
//	a.test2(1);
//	a.test3(&a);
//	int c[50];
//	a.test(&a);
//	a.test2(1);
//	a.test3(&a);
//	int d[50];
//	a.test(&a);
//	a.test2(1);
//	a.test3(&a);
//	ListNode s[5] = { {1,&s[1]}, {2,&s[2]}, {3,&s[3]},{4,&s[4]}, {5} };
//	/*for (int i = 0; i < 4; ++i) {
//		s[i].data = i + 1;
//		s[i].next = &s[i +1];
//	}
//	s[4].data = 5;*/
//	ListNode* ret = FindKthToTail2(&s[0], 5);
//	ret ? cout << ret->data << endl : cout << "NULL" << endl;
//	ret = FindKthToTail(&s[0], 5);
//	ret ? cout << ret->data << endl : cout << "NULL" << endl;
//	return 0;
//}



class A {
	int a = 10;
public:
	static void fun(A& v) {
		cout << v.a << endl;
	}
};

void test(string& s) {
	cout << s;
}
int func(int a)
{
	int b;
	switch (a)
	{
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 16;
	default: b = 0;
	}
	return b;
}
//#include<vector>
//class Solution_ {
//public:
//	int pivotIndex(vector<int>& nums) {
//		int left = 0, right = nums.size() - 1;
//		if (right < 2) return -1;
//		int lsum = 0, rsum = 0;
//		while (left <= right) {
//			if (lsum > rsum) {
//				rsum += nums[right];
//				--right;
//			}
//			else if (lsum < rsum) {
//				lsum += nums[left];
//				++left;
//			}
//			else {
//				if (right == left) {
//					return left;
//				}
//				lsum += nums[left];
//				rsum += nums[right];
//				++left, --right;
//			}
//		}
//		return -1;
//	}
//};
#include<vector>
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int max = nums[0], max_2 = INT_MIN, max_3 = INT_MIN;
		bool flag = true;
		for (auto& i : nums) {
			if (i > max) {
				max = i;
			}
		}
		for (auto& i : nums) {
			if (i != max && i >= max_2) {
				max_2 = i;
				flag = false;
			}
		}
		if (flag) return max;
		flag = true;
		for (auto& i : nums) {
			if (i != max && i != max_2 && i >= max_3) {
				max_3 = i;
				flag = false;
			}
		}
		if (flag) return max;
		return max_3;
	}
};
#define S "1234"
int f(int n) {
	if (n) return f(n - 1) + n;
	else return n;
}
int fun(int x, int y)
{
	if (x == y)
		return (x);
	else
		return ((x + y) / 2);
}
#include<string>
string addBinary(string& a, string& b) {
	string res;
	int size1 = a.size(), size2 = b.size(), tmp = 0, i, j;
	for (i = size1 - 1, j = size2 - 1; i >= 0 && j >= 0; --i, --j) {
		if (a[i] == b[j]) {
			tmp ? res += '1' : res += '0';
			a[i] == '1' ? tmp = 1 : tmp = 0;
		}
		else {
			tmp ? res += '0' : res += '1';
		}
	}
	for (; i >= 0; --i) {
		if (a[i] == '1') {
			tmp ? res += '0' : res += '1';
		}
		else {
			tmp ? tmp = 0, res += '1' : res += '0';
		}
	}
	for (; j >= 0; --j) {
		if (b[j] == '1') {
			tmp ? res += '0' : res += '1';
		}
		else {
			tmp ? tmp = 0, res += '1': res += '0';
		}
	}
	if (tmp) res += '1';
	reverse(res.begin(), res.end());
	return res;
}
int myAtoi(string str) {
	int len = str.size(), pos = 0;
	if (len == 0) return 0;
	while (pos < len && str[pos] == ' ') ++pos;
	if (pos == len) return 0;
	int flag = 1;
	char& ch = str[pos];
	if (ch == '-') {
		++pos;
		flag = -1;
	}
	else if (ch == '+') {
		++pos;
		flag = 1;
	}
	else if (ch < '0' || ch > '9') {
		return 0;
	}
	long long res = 0, tmp = flag;
	int start = pos;
	while (start < len && str[start] == '0') ++start;
	while (pos < len && str[pos] >= '0' && str[pos] <= '9') ++pos;
	for (int i = pos - 1; i >= start; --i, tmp *= 10) {
		res += (tmp * (str[i] - '0'));
		if (tmp > INT_MAX) {
			return INT_MAX;
		}
		if (tmp < INT_MIN) {
			return INT_MIN;
		}
	}
	if (res > INT_MAX) {
		return INT_MAX;
	}
	if (res < INT_MIN) {
		return INT_MIN;
	}
	return (int)res;
}
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> res(2, -1);
	if (nums.empty()) return res;
	int size = nums.size(), left = 0, right = size - 1, mid;
	while (left < right) {
		mid = (right + left) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else {//>=
			right = mid;
		}
	}
	if (nums[left] != target) return res;
	res[0] = left;
	right = size - 1;
	while (left < right) {
		mid = (right + left) / 2;
		if (nums[mid] <= target) {
			left = mid + 1;
		}
		else {//<=
			right = mid;
		}
	}
	nums[left] == target ? res[1] = left : res[1] = left - 1;
	return res;
}
int x = 10;
int func(int i, int j)
{
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func(i - 3, j / 2);
}
int main() {
	//A a;
	//A::fun(a);
	//cout << func(1) << endl;
	//int n = 2;
	//const char *p = "abcdefgh", *r;
	//long *q;
	//q = (long*)p;
	//q++;
	//r = (char*)q;
	//printf("%s\n", r);
	//char str[] = "ABCD", *p1 = str;
	//printf("%d\n", *(p1 + 4));
	//Solution s;
	//vector<int> v = {1, 2};
	//cout << s.thirdMax(v) << endl;
	//cout << f(4) << endl;
	//int a = 4, b = 5, c = 6;
	//printf("%d\n", fun(2 * a, fun(b, c)));
	string a1 = "2147483648";
	string b = "  0000000000012345678";
	cout << myAtoi(a1) << endl;
	vector<int> v = { 5,7,7,8,8,10 };
	int n = 8;
	/*for (auto &i : searchRange(v, n)) {
		cout << i << ' ';
	}*/
	char s[] = "abcdefgh", *p = s;
	p += 3;
	//printf("%d\n", strlen(strcpy(p, "ABCD")));
	/*int a[] = { 2,4,6,8 }, *p2 = a, i;
	for (i = 0; i < 4; i++)
		a[i] = *p2++;
	printf("%d\n", a[2]);*/
	//cout << func(15, 20);
	/*int a11 = 1; 
	int b11 = 2;
	for (; a11 < 8; a11++) {
		b11 += a11; a11 += 2;
	}
	printf("%d，%d\n", a11, b11);
*/
	int mm = 2, nn = 0;
	int tmp = mm > nn ? mm : nn;
	cout << tmp << endl;
	cout << (mm > nn) ? mm : nn;
	return 0;
}