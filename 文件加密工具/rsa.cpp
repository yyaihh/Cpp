#include<fstream>
#include"rsa.h"
using namespace std;

RSA::RSA() {
	getKeys();
}
bm::int1024_t RSA::getNkey(bm::int1024_t& prime1, bm::int1024_t& prime2) {
	return prime1 * prime2;
}
bm::int1024_t RSA::getOrla(bm::int1024_t& prime1, bm::int1024_t& prime2) {//prime1和prime2必须互质
	return (prime1 - 1) * (prime2 - 1);
}
bm::int1024_t RSA::getEkey(bm::int1024_t& orla) {
	bm::int1024_t ekey;
	br::mt11213b gen((size_t)time(0));
	br::uniform_int_distribution<bm::int1024_t> dist(bm::int1024_t(0), (bm::int1024_t(orla)));
	do {
		ekey = dist(gen);
	} while (ekey < 2 || getGcd(ekey, orla) != 1);
	return ekey;
}
bm::int1024_t RSA::getDkey(bm::int1024_t& ekey, bm::int1024_t& orla) {
	bm::int1024_t x, y;
	exGcd(ekey, orla, &x, &y);
	//变换, 让解密密钥是一个比较小的数
	return (x % orla + orla) % orla;
}
bm::int1024_t RSA::getGcd(bm::int1024_t num1, bm::int1024_t num2) {
	bm::int1024_t num;
	while ((num = num1 % num2)) {
		num1 = num2;
		num2 = num;
	}
	return num2;
}
bm::int1024_t RSA::exGcd(bm::int1024_t a, bm::int1024_t b, bm::int1024_t* x, bm::int1024_t* y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	bm::int1024_t gcd = exGcd(b, a % b, x, y);
	bm::int1024_t x1 = *x, y1 = *y;
	*x = y1;
	*y = x1 - a / b * y1;
	return gcd;
}
bm::int1024_t RSA::_encrypt(bm::int1024_t Ai, bm::int1024_t ekey, bm::int1024_t nkey) {
	//data^ekey % nkey
	//只和ekey的位数有关
	bm::int1024_t res = 1;
	for (; ekey; ekey >>= 1) {
		if (ekey & 1) {
			res = (res*Ai) % nkey;
		}
		Ai = (Ai*Ai) % nkey;
	}
	return res;
}
bm::int1024_t RSA::_decrypt(bm::int1024_t data, bm::int1024_t dkey, bm::int1024_t nkey) {
	return _encrypt(data, dkey, nkey);
}
bool RSA::isPrime(bm::int1024_t& num) {
	br::mt11213b gen((size_t)time(0));
	if (miller_rabin_test(num, 25, gen)) {
		if (miller_rabin_test((num - 1) / 2, 25, gen)) {
			return true;
		}
	}
	return false;
}
bm::int1024_t RSA::GetPrime() {
	bm::int1024_t res;
	br::mt19937 gen((size_t)time(0));
	br::uniform_int_distribution<bm::int1024_t> dist(bm::int1024_t(0), (bm::int1024_t(1) << 256));
	do {
		res = dist(gen);
	} while (!isPrime(res));
	return res;
}
void RSA::getKeys() {
	bm::int1024_t prime1, prime2 = GetPrime();
	while ((prime1 = GetPrime()) == prime2);
	m_key.m_nkey = getNkey(prime1, prime2);
	bm::int1024_t orla = getOrla(prime1, prime2);
	m_key.m_ekey = getEkey(orla);
	m_key.m_dkey = getDkey(m_key.m_ekey, orla);
}
Key RSA::getKey() {
	return m_key;
}
void RSA::encrypt(const char* filename, const char* outname) {
	ifstream fin(filename, ifstream::binary);
	ofstream fout(outname, ifstream::binary);
	if (!fin.is_open()) {
		perror("input file open failed!");
		return;
	}
	char* buffer = new char[NUMBER];
	bm::int1024_t* bufferOut = new bm::int1024_t[NUMBER];
	//char* bufferOut = new char[NUMBER];
	while (!fin.eof()) {
		fin.read(buffer, NUMBER);
		streamsize ret = fin.gcount();
		for (streamsize i = 0; i < ret; ++i) {
			bufferOut[i] = _encrypt(buffer[i], m_key.m_ekey, m_key.m_nkey);
		}
		fout.write((char*)bufferOut, ret * sizeof(bm::int1024_t));
	}
	delete[] bufferOut;
	delete[] buffer;
	fin.close();
	fout.close();
}
void RSA::decrypt(const char* filename, const char* outname) {
	ifstream fin(filename, ifstream::binary);
	ofstream fout(outname, ifstream::binary);
	if (!fin.is_open()) {
		perror("file open failed");
	}
	bm::int1024_t* buffer = new bm::int1024_t[NUMBER];
	//char* buffer = new char[NUMBER];
	char* bufferOut = new char[NUMBER];
	while (!fin.eof()) {
		fin.read((char*)buffer, NUMBER * sizeof(bm::int1024_t));
		streamsize ret = fin.gcount() / sizeof(bm::int1024_t);
		for (streamsize i = 0; i < ret; ++i) {
			bufferOut[i] = (char)_decrypt(buffer[i], m_key.m_dkey, m_key.m_nkey);
		}
		fout.write(bufferOut, ret);
	}
	delete[] bufferOut;
	delete[] buffer;
	fin.close();
	fout.close();
}