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
		cout << "����ʵ����: " << testroom << "  " << "ְ��: " << post << endl;
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
		cout << "��������" << endl;
		return 0;
	}
	cout << "�������ţ�"; cin >> nu;
	for (i = 0; i < Testop; i++)
	{
		if (nu == Test[i].num)
		{
			cout << "���б�ţ��������" << endl;
			return 0;
		}
	}
	t.Input();
	Test[Testop] = t;
	Testop++;
	cout << "��ӳɹ���" << endl;
	return 1;
}
int TestManager::Search()
{
	int j, n;
	cout << "�������ţ�"; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
		cout << "û�д��ˣ�" << endl;
	else
		Test[j].Output();
	return 1;
}
void TestManager::Show()
{
	int i;
	if (Testop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl; return;
	}
	for (i = 0; i < Testop; i++)
		Test[i].Output();
}
void TestManager::Edit()
{
	Tester t1;
	int j, n;
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "û�д��ˣ�" << endl; return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Test[j] = t1;
	cout << "�༭�ɹ���" << endl;
}
int TestManager::Delete()
{
	int j, n;
	cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	for (j = 0; j < Testop; j++)
	{
		if (n == Test[j].num) break;
	}
	if (j == Testop)
	{
		cout << "û�д��ˣ�" << endl; return 0;
	};
	for (j; j < Testop; j++)
	{
		Test[j] = Test[j + 1];
	}
	Testop--;
	cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Test_mune(TestManager TM)
{
	int b;
	char c;
	do {
		cout << "ʵ����Ա����" << endl;
		cout << "==========================================================================================" << endl;
		cout << "| 1.���    ";
		cout << "2.��ѯ    ";
		cout << "3.��ʾ    ";
		cout << "4.�༭    ";
		cout << "5.ɾ��    ";
		cout << "6.ͳ��    ";
		cout << "7.����    ";
		cout << "8.��ȡ    ";
		cout << "0.�˳� |" << endl;
		cout << "==========================================================================================" << endl;
		cout << "��ѡ��"; cin >> b;
		switch (b)
		{
		case 1:TM.Add(); getchar(); break;
		case 2:TM.Search(); getchar(); break;
		case 3:TM.Show(); getchar(); break;
		case 4:TM.Edit(); getchar(); break;
		case 5:TM.Delete(); getchar(); break;
		case 6:cout << "����ʵ��Ա������" << Testop << endl; getchar(); break;
		case 7:TM.Save(); getchar(); break;
		case 8:TM.Read(); getchar(); break;
		default:cout << "\n error" << endl; getchar(); break;
		case 0:break;
		}
		cout << "���س�������" << endl;
		_flushall();
		c = getchar();
		system("cls");
	} while (b != 0);
}
