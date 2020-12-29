/*
存储四类员工共有的属性
*/
#pragma once
#include <fstream>
#include <iostream>
using namespace std;
const int MAX = 10;
class person
{
public:
	int num;//编号
	char name[20];//姓名
	char sex[4];//性别
	int age;//年龄
public:
	void input()
	{
		cout << "Input num:"; cin >> num;
		cout << "Input name:"; cin >> name;
		cout << "Input sex:"; cin >> sex;
		cout << "Input age:"; cin >> age;
	}
	void Output()
	{
		cout << "编号: " << num << "  " << "姓名: " << name << "  " << "性别: " << sex << "  " << "年龄: " << age << "	";
	}
};