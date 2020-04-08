#include<iostream>
using namespace std;

void fun(char* str, int len, int k) {
	k %= len;
	reverse(str, str + len);
	reverse(str, str + len - k);
	reverse(str + len - k, str + len);
}
void Reverse(char* start, char* end) {
	for (char tmp; start < end; ++start, --end) {
		tmp = *start;
		*start = *end;
		*end = tmp;
	}
}
void fun1(char* str, int len, int k) {
	k %= len;
	Reverse(str, str + len);
	Reverse(str, str + len - k);
	Reverse(str + len - k, str + len);
}
int main() {
	char str[20] = "abcdefg";
	fun1(str, strlen(str), 2);
	cout << str;
	return 0;
}