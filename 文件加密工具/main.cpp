#include<iostream>
#include"rsa.h"
using namespace std; 
void test() {
	RSA rsa;
	Key k = rsa.getKey();
	cout << k.m_ekey << endl;
	cout << k.m_dkey << endl;
	cout << k.m_nkey << endl;
	rsa.encrypt("test.txt", "test_rsa.txt");
	rsa.decrypt("test_rsa.txt", "test_.txt");
}
void test1() {
	char n1[] = "1234567345643123333333333333333456777777777777777777543234565434565432";
	const char* n2 = "6234563425656643425675434235654321345671324567543245734256765345677586";
	const char* n3 = "6234563425656643425675434235654321345671324567543245734256765345677586";
	string s = n1;
	s += n2;
	s += n3;
	bm::int1024_t bn1(n1);
	bm::int1024_t bn2(s);
	bm::cpp_int bn3 = bn1 * bn2;
	std::cout << bn1 << std::endl << std::endl;
	std::cout << bn2 << std::endl << std::endl;
	std::cout << bn3 << std::endl << std::endl;
	
}
void test3() {
	bm::int1024_t n;
	br::mt19937 gen((size_t)time(0));
	br::uniform_int_distribution<bm::int1024_t> dist(bm::int1024_t(0), bm::int1024_t(1) << 128);
	for (int i = 0; i < 10; ++i) {
		std::cout << dist(gen) << std::endl;
	}
}
int main() {
	test();
	return 0;
}
