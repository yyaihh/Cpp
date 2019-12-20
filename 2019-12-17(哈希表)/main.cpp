#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//template<class T>
/*#include<stdio.h>
#include<math.h>
int IsPrimeNum(int x)
{
	double m = sqrt(x);
	int j;
	for (j = 2; j <= m; j++){
		if (x%j == 0) return 0;
	}
	return 1;
}
int main(){
	int num,left,right,size;
	printf("请输入一个大于6的偶数\n");
	while(scanf("%d",&num)==0 || num<7 || num%2 ){
		printf("输入有误, 请重新输入大于6的偶数\n");
	}
	size = num/2;
	for(left = 3;left<size;left+=2){
		if(IsPrimeNum(left)){
			right = num - left;
			if(IsPrimeNum(right)){
				printf("%d+%d = %d\n",left,right,num);
				break;
			}
		}
	}
	return 0;
}*/
/*#include<stdio.h>
int main() {
	int count = 0;//换法
	int balance,two,five,money;
	scanf("%d",&money);
	for (two = 0; two <= money / 2; ++two) {
		for (five = 0; five <= money / 5; ++five) {
			balance = money - (2 * two + 5 * five);
			if (balance >= 0) {//
				printf("%d个5分,%d个2分,%d个1分\n",five,two,balance);
				++count;
			}
		}
	}
	printf("换法有%d种\n",count);
	return 0;
}
*/
/*
#include<stdio.h>

int main(){
	int n,i;
	char ch ='A';
	while(scanf("%d",&n)==0||n>6||n<0){
		printf("请输入小于7的正整数");
	}
	for(;n>0;--n){
		for(i=n;i>0;--i,++ch){
			printf("%c ",ch);
		}
		putchar('\n');
	}
	return 0;
}*/
/*#include<stdio.h>
int sign(double x){
	if(x>0){
		return 1;
	}
	if(x<0){
		return -1;
	}
	return 0;
}
int main(){
	double x;
	scanf("%lf",&x);
	printf("sign(%.2f) = %d\n",x,sign(x));
	return 0;
}*/
/*
#include<stdio.h>
#include<math.h>
double dist(double x1, double y1, double x2, double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	double x1, y1,x2, y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	printf("距离:%.2lf\n",dist(x1, y1,x2, y2));
	return 0;
}*/
/*#include<stdio.h>

int main(){
	int i,n,index, a[10];
	while(scanf("%d",&n)&&(n>10||n<1));
	for(i =0;i<n;++i){
		scanf("%d",&a[i]);
	}
	index = 0;
	for(i =1;i<10;++i){
		if(a[index]<a[i]){
			index = i;
		}
	}
	printf("%d  %d",a[index], index);
	return 0;
}*/
/*#include<stdio.h>

int main(){
	double a;
	int b;
	scanf("%2d%5lf",&b,&a);
	printf("%d %lf\n",b,a);

	return 0;
}*/
/*#include<stdio.h>

int main(){
	/*int n, num, i, max;
	int a[10] = { 0 };
	printf("请输入n的值\n");
	scanf("%d", &n);
	for(i = 0;i < n; ++i){
		printf("请输入第%d个数\n",i+1);
		scanf("%d",&num);
		while(num){
			a[num%10]++;
			num /= 10;
		}
	}
	max = 0;//下标
	for(i = 1; i < 10; ++i){
		if(a[max]<a[i]){
			max = i;
		}
	}
	printf("最多的数字是%d\n", max);
	char* s="abcdefggi";
	printf("%5.3s\n",s);
	printf("%.3s\n",s);
	printf("%20shehe\n",s);
	return 0;
}*/
//#include<stdio.h>
//int main() {
//	void change(int* p, int m, int n);
//	int i, n, m, a[100] = { 0 }, *p = a;
//	printf("please enter the n\n");
//	scanf_s("%d", &n);
//	printf("please enter n numbers:\n");
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	printf("please enter the m\n");
//	scanf_s("%d", &m);
//	change(a, m, n);
//	for (; p < a + n; p++)
//		printf("%d ", *p);
//	putchar('\n');
//	return 0;
//}
//void change(int* p, int m, int n)
//{
//	int i;
//	for (i = n; i >= 0; --i) {
//		p[i + m] = p[i];
//	}
//	for (i = 0; i < m; ++i) { 
//		p[i] = p[i + n];
//		p[i + n] = 0;
//	}
//}
//#include<stdio.h>
//int main()
//{
//	void change(int* p, int m);
//	int i, n, m, a[100] = { 0 }, *p = a;
//	printf("please enter the n\n");
//	scanf_s("%d", &n);
//	printf("please enter n numbers:\n");
//	for (i = 0; i < n; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	printf("please enter the m\n");
//	scanf_s("%d", &m);
//	change(a, m);
//	for (p = a; p < a + n; p++)
//		printf("%d", *p);
//	return 0;
//}
//void change(int* p, int m)
//{
//	int i = 0, *p1 = p, t;
//	while (i < m)
//	{
//		t = *p;
//		for (p = p + m; p > p1 + 1; p--)
//		{
//			*p = *(p - 1);
//		}
//		*p = t;
//		i++;
//	}
//}
//#include <stdio.h>
//#include <stdlib.h>
//#define N 6 //学生个数
//#define M 6 //课程个数
//void stu_aver(double(*a)[M + 1]) {//计算学生平均成绩
//	double sum;
//	int i, j;
//	for (i = 0; i < N; ++i) {
//		sum = 0.0;
//		for (j = 0; j < M; ++j) {
//			sum += a[i][j];
//		}
//		a[i][M] = sum / M;
//	}
//}
//void input(char(*c)[20], char(*s)[20], double(*a)[M + 1]) {//输入
//	int i, j;
//	for (i = 0; i < M; ++i) {
//		printf("请输入第%d门课的课程名\n", i + 1);
//		scanf("%s", c[i]);
//	}
//	for (i = 0; i < N; ++i) {
//		printf("请输入第%d名学生的姓名\n", i + 1);
//		scanf("%s", s[i]);
//		printf("请输入这名学生的成绩\n");
//		for (j = 0; j < M; ++j) {
//			printf("请输入%s成绩:", c[j]);
//			scanf("%lf", &a[i][j]);
//		}
//	}
//	system("cls");
//}
//void print_1(char(*c)[20]) {
//	int i;
//	putchar('\t');
//	for (i = 0; i < M; ++i) {
//		printf("%s\t", c[i]);
//	}
//	printf("平均成绩");
//}
//void print_2(char(*s)[20], double(*a)[M + 1], int i) {
//	int j;
//	printf("\n%s\t", s[i]);
//	for (j = 0; j < M + 1; ++j) {
//		printf("%.2f\t", a[i][j]);
//	}
//}
//void print(char(*c)[20], char(*s)[20], double(*a)[M + 1]) {//打印
//	int i;
//	print_1(c);
//	for (i = 0; i < N; ++i) {
//		print_2(s, a, i);
//	}
//	putchar('\n');
//}
//void fail(char(*c)[20], char(*s)[20], double(*a)[M + 1]) {
//	int i, j, flag, flag_2 = 0;
//	for (i = 0; i < N; ++i) {
//		flag = 0;
//		for (j = 0; j < M; ++j) {
//			if (a[i][j] < 60.0) {
//				if (flag == 0) {
//					flag = 1;
//				}
//				else {
//					if (flag_2 == 0) {
//						printf("两门及以上不及格的学生有\n");
//						print_1(c);
//						flag_2 = 1;
//					}
//					print_2(s, a, i);
//					putchar('\n');
//					break;
//				}
//			}
//		}
//	}
//	if (flag_2 == 0) {
//		printf("没有两门及以上不及格的学生\n");
//	}
//}
//int main() {
//	char c[N][20];//课程名字
//	char s[M][20];//学生姓名
//	double a[N][M + 1];//学生成绩
//	input(c, s, a);//输入
//	stu_aver(a);//学生平均成绩
//	print(c, s, a);//打印
//	fail(c, s, a);
//	system("pause");
//	return 0;
//}
typedef struct stu {
	long num;
	char name[10];
	int age;
}s;
int main() {
	s a;
	printf("%d\n", sizeof(a));
	printf("%d\n", offsetof(s, num));
	printf("%d\n", offsetof(s, name));
	printf("%d\n", offsetof(s, age));
	printf("%d\n", sizeof(a.name));
	system("pause");
	return 0;
}