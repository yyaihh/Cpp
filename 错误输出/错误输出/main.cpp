#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct mystruct {
	string file;
	int l, count;
	mystruct(string f = "", int i = 0) : file(f), l(i), count(1) {}
	bool operator==(const mystruct& s) {
		return (file == s.file) && (l == s.l);
	}
};
int main() {
	mystruct ms;
	vector<mystruct> vs;
	while (cin >> ms.file >> ms.l) {
		ms.file = ms.file.substr(ms.file.rfind('\\') + 1);
		auto ret = find(vs.begin(), vs.end(), ms);
		if (ret == vs.end()) vs.push_back(ms);
		else ret->count++;
	}
	int size = vs.size(), len, i = 0;
	if (size >= 8) i = size - 8;
	for (; i < size; ++i) {
		len = vs[i].file.size() - 16;
		if (len < 0) len = 0;
		cout << vs[i].file.substr(len) << ' ' << vs[i].l << ' ' << vs[i].count << endl;
	}
	return 0;
}