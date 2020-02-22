#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int compress(string& chars) {
		int size = chars.size();
		if (size == 1) return 1;
		int read = 1, write = 1, pre = 0, b, count = 1;
		for (; read < size; ++read){
			if (chars[pre] == chars[read]) {
				++count;
			}
			else {
				if (count > 1) {
					b = write;
					for (; count; count /= 10) {
						chars[write++] = count % 10 + '0';
					}
					count = 1;
					reverse(chars.begin() + b, chars.begin() + write);
				}
				pre = write;
				chars[write++] = chars[read];
			}
		}
		if (count > 1) {
			b = write;
			for (; count; count /= 10) {
				chars[write++] = count % 10 + '0';
			}
			reverse(chars.begin() + b, chars.begin() + write);
		};
		chars.resize(write);
		return write;
	}
};

int main() {
	Solution s;
	string v = { 'a', 'a','b','c','c','c' };
	s.compress(v);
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}
	return 0;
}
