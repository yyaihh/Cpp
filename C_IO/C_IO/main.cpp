#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<time.h>
int decode(int key) {
	key %= 26;
	FILE* fp1 = fopen("加密文本.txt", "r");//需要有这个文件
	if (fp1 == NULL) {
		printf("加密文本打开失败\n");
		return -1;
	}
	FILE* fp2 = fopen("解密文本.txt", "w");
	if (fp2 == NULL) {
		printf("解密文本打开失败\n");
		return -1;
	}
	char c;
	while ((c = fgetc(fp1)) != EOF) {
		if (c > 96 && c < 123) {
			if (c - key < 'a')
				c = c + 26 - key;
			else
				c = c - key;
		}
		else if (c > 64 && c < 92) {
			if (c - key < 'A')
				c = c + 26 - key;
			else
				c = c - key;
		}
		fputc(c, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int main() {
	clock_t start;
	int key;
	scanf("%d", &key);
	start = clock();
	decode(key);
	printf("用时:%dms\n", clock() - start);
	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<ctime>
//int Read(char* str) {
//	FILE* fp = fopen("加密文本.txt", "r");//需要有这个文件
//	if (fp == NULL) {
//		printf("加密文本打开失败\n");
//		return -1;
//	}
//	fscanf(fp, "%s", str);
//	fclose(fp);
//
//	return 0;
//}
//int Write(char* str) {
//	FILE* fp = fopen("解密文本.txt", "w");
//	if (fp == NULL) {
//		printf("解密文本打开失败\n");
//		return -1;
//	}
//	fprintf(fp, "%s", str);
//	fclose(fp);
//	return 0;
//}
//
//void decode(char* str1, char* str2, int key) {
//	key = key % 26;
//	for (int i = 0; i < strlen(str1); i++)
//	{
//		if ((str1[i] >= 'a' && str1[i] <= 'z'))
//		{
//			if (str1[i] - key < 'a')
//				str2[i] = str1[i] + 26 - key;
//			else
//				str2[i] = str1[i] - key;
//		}
//		else if (str1[i] >= 'A' && str1[i] <= 'Z')
//		{
//			if (str1[i] - key < 'A')
//				str2[i] = str1[i] + 26 - key;
//			else
//				str2[i] = str1[i] - key;
//		}
//		else
//			str2[i] = str1[i];
//	}
//}
//
//
//
//int main() {
//	int key = 0;
//	printf("请输入密钥\n");
//	scanf("%d", &key);
//	clock_t start;
//	start = clock();
//	char str1[1024] = { 0 };//解密前
//	char str2[1024] = { 0 };//解密后
//	Read(str1);
//	//解密操作
//	decode(str1, str2, key);
//	Write(str2);
//	printf("用时:%dms\n", clock() - start);
//	return 0;
//}
