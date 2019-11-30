#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person {
	string m_name;
	bool m_sex;
	int m_age;
public:
	Person(string name, bool sex, int age)
		:m_name(name),
		m_sex(sex),
		m_age(age)
	{}
	Person(Person& x)
		:m_name(x.m_name),
		m_sex(x.m_sex),
		m_age(x.m_age)
	{}
	void Print_Peson() {
		cout << "����: " << m_name << "  �Ա�: ";
		m_sex ? cout << "��" : cout << "Ů";
		cout << "  ����: " << m_age;
	}
};
class Student : public Person {
	int m_stunum;
public:
	Student(string name, bool sex, int age, int stunum)
		:m_stunum(stunum),
		Person(name, sex, age)
	{}
	void Print_Student() {
		Print_Peson();
		cout << "  ѧ��: " << m_stunum << endl;
	}
};