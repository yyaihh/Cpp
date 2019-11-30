#include<iostream>
#include"class.h"
using namespace std;
void test1() {
	Student* Sp = new Student("张三", true, 20, 1901);
	Person* Pp = Sp;//给指针
	Person& Pr = *Sp;//给引用
	Person a = *Sp;//给对象
	Pp->Print_Peson();
	cout << endl;
	Pr.Print_Peson(); 
	cout << endl;
	a.Print_Peson(); 
	cout << endl;
}

void test2() {
	Person* Pp = new Person("李四", false, 19);
	Student* Sp = (Student*)Pp;
	Sp->Print_Student();
}
int main_() {	
	test1();
	test2();
	system("pause");
	return 0;
}
