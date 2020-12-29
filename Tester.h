#pragma once


#include "Person.h"

class Tester : public person
{
public:
	char testroom[10];
	char post[10];
	void Input()
	{
		person::input();
		cout << "Input testroom:"; cin >> testroom;
		cout << "Input post:"; cin >> post;
	}
	void Output()
	{
		cout << "所在实验室: " << testroom << "  " << "职务: " << post << endl;
	}

};
Tester Test[MAX];
static int Testop;
class TestManager
{
public:
	int Add();
	int Search();
	void Show();
	void Edit();
	int Delete();
	void Save();
	void Read();
};
int TestManager::Add()
{
	Tester t;
	int i, nu;
	if (Testop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	cout << "请输入编号："; cin >> nu;
	for (i = 0; i < Testop; i++)
	{
		if (nu == Test[i].num)
		{
			cout << "已有编号，请从输入" << endl;
			return 0;
		}
	}
	t.Input();
	Test[Testop] = t;
	Testop++;
	cout << "添加成功！" << endl;
	return 1;
}
int TestManager::Search()
{
	int j, n;
	cout << "请输入编号："; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
		cout << "没有此人！" << endl;
	else
		Test[j].Output();
	return 1;
}
void TestManager::Show()
{
	int i;
	if (Testop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Testop; i++)
		Test[i].Output();
}
void TestManager::Edit()
{
	Tester t1;
	int j, n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "没有此人！" << endl; return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Test[j] = t1;
	cout << "编辑成功！" << endl;
}
int TestManager::Delete()
{
	int j, n;
	cout << "请输入要删除的人的编号："; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "没有此人！" << endl; return 0;
	};
	for (j; j < Testop; j++)
	{
		Test[j] = Test[j + 1];
	}
	Testop--;
	cout << "删除成功！" << endl;
	return 1;
}
void TestManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Testop.dat", ios::out);
	outfile1 << Testop;
	outfile.open("Test_data.dat", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Testop; i++)
		outfile.write((char*)&Test[i], sizeof(Test[i]));
	outfile.close();
	cout << "保存成功！" << endl;
}
void TestManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Testop.dat", ios::in);
	infile1 >> Testop;
	infile.open("Test_data.dat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Testop; i++)
		infile.read((char*)&Test[i], sizeof(Test[i]));
	infile.close();
	cout << "读取成功！" << endl;
}
void Test_mune(TestManager TM)
{
	int b;
	char c;
	do {
		cout << "实验人员管理" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.添加    ";
		cout << "2.查询    ";
		cout << "3.显示    ";
		cout << "4.编辑    ";
		cout << "5.删除    ";
		cout << "6.统计    ";
		cout << "7.保存    ";
		cout << "8.读取    ";
		cout << "0.退出 |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "请选择："; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); getchar(); break;
		case 2:TM.Search(); getchar(); break;
		case 3:TM.Show(); getchar(); break;
		case 4:TM.Edit(); getchar(); break;
		case 5:TM.Delete(); getchar(); break;
		case 6:cout << "共有实验员人数：" << Testop << endl; getchar(); break;
		case 7:TM.Save(); getchar(); break;
		case 8:TM.Read(); getchar(); break;
		default:cout << "\n error" << endl; getchar(); break;
		case 0:break;
		}
		cout << "按回车键继续" << endl;
		_flushall();
		c = getchar();
		system("cls");
	} while (b != 0);
}
