#pragma once
#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>//高精度库
#include<boost/multiprecision/random.hpp>//随机数库
#include<boost/multiprecision/miller_rabin.hpp>//素性检测
namespace br = boost::random;
namespace bm = boost::multiprecision;

#define NUMBER 128

typedef struct {
	bm::int1024_t m_ekey;//公钥e
	bm::int1024_t m_dkey;//私钥d
	bm::int1024_t m_nkey;//公共模数n
}Key;

class RSA {
	Key m_key;
	bm::int1024_t GetPrime();
	bool isPrime(bm::int1024_t& num);
	bm::int1024_t getNkey(bm::int1024_t& prime1, bm::int1024_t& prime2);//获取公共模数n
	bm::int1024_t getOrla(bm::int1024_t& prime1, bm::int1024_t& prime2);//欧拉函数, 得到f(n)
	bm::int1024_t getEkey(bm::int1024_t& orla);//获取公钥
	bm::int1024_t getDkey(bm::int1024_t& ekey, bm::int1024_t& orla);//获取私钥
	bm::int1024_t exGcd(bm::int1024_t a, bm::int1024_t b, bm::int1024_t* x, bm::int1024_t* y);//求模反元素
	bm::int1024_t getGcd(bm::int1024_t num1, bm::int1024_t num2);//最大公约数
	bm::int1024_t _encrypt(bm::int1024_t data, bm::int1024_t ekey, bm::int1024_t nkey);//加密,需要加密数据和公钥(e, n)
	bm::int1024_t _decrypt(bm::int1024_t data, bm::int1024_t dkey, bm::int1024_t nkey);//解密,需要要解密的数据和私钥(d, n)
	void getKeys();
public:
	RSA();
	Key getKey();
	void encrypt(const char* filename, const char* outname);//加密
	void decrypt(const char* filename, const char* outname);//解密
};