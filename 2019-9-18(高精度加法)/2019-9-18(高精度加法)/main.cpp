#include "Solution.h"
int main() {
	string s1("1000");
	string s2("2000");
	Solution mul;
	cout << "s1= " << s1 << endl;
	cout << "s2= " << s2 << endl;
	cout << s1 << " + " << s2 << " = ";
	cout << mul.Add(s1, s2) << endl;
	system("pause");
	return 0;
}