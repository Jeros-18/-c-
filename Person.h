/*
�洢����Ա�����е�����
*/
#pragma once
#include <fstream>
#include <iostream>
using namespace std;
const int MAX = 10;
class person
{
public:
	int num;//���
	char name[20];//����
	char sex[4];//�Ա�
	int age;//����
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
		cout << "���: " << num << "  " << "����: " << name << "  " << "�Ա�: " << sex << "  " << "����: " << age << "	";
	}
};