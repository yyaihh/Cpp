#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>//高精度库
#include<boost/multiprecision/random.hpp>//随机数库
#include<boost/multiprecision/miller_rabin.hpp>//素性检测
namespace br = boost::random;
namespace bm = boost::multiprecision;

void test() {
#if 0
	br::mt19937 gen((size_t)time(0));
	br::uniform_int_distribution<int> dist(0, 100);
	int c = dist(gen);
	std::cout << c;
#else 
	bm::int1024_t m(1);
	br::mt19937 gen((size_t)time(0));
	br::uniform_int_distribution<bm::int1024_t> dist(bm::int1024_t(0), m << 256);
	bm::int1024_t c = dist(gen);
	std::cout << c;
#endif
}
int main() {
	test();
	return 0;
}