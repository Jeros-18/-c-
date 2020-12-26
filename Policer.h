#pragma once


#include "Person.h"

class Policer : public person
{
public:
	char polices[10];
	char post1[10];
	void Input()
	{
		
		person::input();
		cout << "Input polices:"; cin >> polices;
		cout << "Input post1:"; cin >> post1;
	}
	void Output()
	{
		person::Output();
		cout << "政治面貌: " << polices << "  " << "职称: " << post1 << endl;

	}

};
Policer Policers[MAX];
static int Policersop;
class PolicerManager
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
int PolicerManager::Add()
{
	Policer t;
	int i, nu;
	if (Policersop == MAX)
	{
		cout << "人数已满" << endl;
		return 0;
	}
	cout << "请输入编号："; cin >> nu;
	for (i = 0; i < Policersop; i++)
	{
		if (nu == Policers[i].num)
		{
			cout << "已有编号，请从输入" << endl;
			return 0;
		}
	}
	t.Input();
	Policers[Policersop] = t;
	Policersop++;
	cout << "添加成功！" << endl;
	return 1;
}
int PolicerManager::Search()
{
	int j, n;
	cout << "请输入编号："; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
		cout << "没有此人！" << endl;
	else
		Policers[j].Output();
	return 1;
}
void PolicerManager::Show()
{
	int i;
	if (Policersop == 0)
	{
		cout << "记录为空！" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		Policers[i].Output();
}
void PolicerManager::Edit()
{
	Policer t1;
	int j, n;
	cout << "请输入要编辑的人的编号："; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "没有此人！" << endl; return;
	};
	cout << "输入修改后的信息，编号不能改:" << endl;
	t1.Input();
	Policers[j] = t1;
	cout << "编辑成功！" << endl;
}
int PolicerManager::Delete()
{
	int j, n;
	cout << "请输入要删除的人的编号："; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "没有此人！" << endl; return 0;
	};
	for (j; j < Policersop; j++)
	{
		Policers[j] = Policers[j + 1];
	}
	Policersop--;
	cout << "删除成功！" << endl;
	return 1;
}
void PolicerManager::Save()
{
	int i;
	ofstream outfile, outfile1;
	outfile1.open("Policersop.dat", ios::out);
	outfile1 << Policersop;
	outfile.open("Policers_data.dat", ios::binary);
	if (!outfile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		outfile.write((char*)&Policers[i], sizeof(Policers[i]));
	outfile.close();
	cout << "保存成功！" << endl;
}
void PolicerManager::Read()
{
	int i;
	ifstream infile, infile1;
	infile1.open("Policersop.dat", ios::in);
	infile1 >> Policersop;
	infile.open("Policers_data.dat", ios::binary);
	if (!infile)
	{
		cerr << "open error!" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		infile.read((char*)&Policers[i], sizeof(Policers[i]));
	infile.close();
	cout << "读取成功！" << endl;
}
void Policers_mune(PolicerManager TM)
{
	int b;
	char c;
	do {
		cout << "行政人员管理" << endl;
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
		case 6:cout << "共有行政员人数：" << Policersop << endl; getchar(); break;
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