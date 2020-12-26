#pragma once

#include "Person.h"
#include "iostream"

//Teacher class
class Teacher :virtual public person
{
public:
	char dept[20];//所在系部
	char special[20]; //专业
	char title[20]; //职称
	void Input()
	{
		person::input();
		cout << "Input dept:"; cin >> dept;
		cout << "Input special:"; cin >> special;
		cout << "Input title:"; cin >> title;
	}
	void Output()
	{
		person::Output();
		cout << "所在系: " << dept << "  " << "专业: " << special << "  " << "职称: " << title << endl;
	}
};

Teacher Tea[MAX];
static int Teatop;



class TeaManager
{
public:
	int Add();//增
	int Search();//查
	void Show(); //显示信息
	void Edit(); //修改信息
	int Delete(); //删
	void Save(); //保存信息
	void Read(); //读取信息
};
int TeaManager::Add()
{
	Teacher t;
	int i, nu;
	if (Teatop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	cout << "请输入编号："; cin >> nu;
	for (i = 0; i < Teatop; i++)
	{
		if (nu == Tea[i].num)
		{
			cout << "已有编号，请从输入" << endl;
			cin >> nu;
			return 0;
		}
	}
	t.Input(); Tea[Teatop] = t; Teatop++;
	cout << "添加成功！" << endl;
	return 1;
}
int TeaManager::Search()
{
	int j, n;
	cout << "请输入编号："; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
		cout << "没有此人！" << endl;
	else
		Tea[j].Output();
	return 1;
}
void TeaManager::Show()
{
	int i;
	if (Teatop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		Tea[i].Output();
}
void TeaManager::Edit()
{
	Teacher t1;
	int j, n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "没有此人！" << endl; return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Tea[j] = t1;
	cout << "编辑成功！" << endl;
}
int TeaManager::Delete()
{
	int j, n;
	cout << "请输入要删除的人的编号："; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "没有此人！" << endl; return 0;
	};
	for (j; j < Teatop; j++)
	{
		Tea[j] = Tea[j + 1];
	}
	Teatop--;
	cout << "删除成功！" << endl;
	return 1;
}
void TeaManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Teatop.dat", ios::out);
	outfile1 << Teatop;
	outfile.open("Tea_data.dat", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		outfile.write((char*)&Tea[i], sizeof(Tea[i]));
	outfile.close();
	cout << "保存成功！" << endl;
}
void TeaManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Teatop.dat", ios::in);
	infile1 >> Teatop;
	infile.open("Tea_data.dat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		infile.read((char*)&Tea[i], sizeof(Tea[i]));
	infile.close();
	cout << "读取成功！" << endl;
}
void Tea_mune(TeaManager TM)
{
	int b;
	char c;
	do {
		cout << "教师管理" << endl;
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
		case 1:TM.Add();  getchar(); break;
		case 2:TM.Search(); getchar(); break;
		case 3:TM.Show(); getchar(); break;
		case 4:TM.Edit(); getchar(); break;
		case 5:TM.Delete(); getchar(); break;
		case 6:cout << "共有教师人数：" << Teatop << endl; getchar(); break;
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