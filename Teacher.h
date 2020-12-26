#pragma once

#include "Person.h"
#include "iostream"

//Teacher class
class Teacher :virtual public person
{
public:
	char dept[20];//����ϵ��
	char special[20]; //רҵ
	char title[20]; //ְ��
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
		cout << "����ϵ: " << dept << "  " << "רҵ: " << special << "  " << "ְ��: " << title << endl;
	}
};

Teacher Tea[MAX];
static int Teatop;



class TeaManager
{
public:
	int Add();//��
	int Search();//��
	void Show(); //��ʾ��Ϣ
	void Edit(); //�޸���Ϣ
	int Delete(); //ɾ
	void Save(); //������Ϣ
	void Read(); //��ȡ��Ϣ
};
int TeaManager::Add()
{
	Teacher t;
	int i, nu;
	if (Teatop == MAX)
	{
		cout << "��������" << endl;
		return 0;
	}
	cout << "�������ţ�"; cin >> nu;
	for (i = 0; i < Teatop; i++)
	{
		if (nu == Tea[i].num)
		{
			cout << "���б�ţ��������" << endl;
			cin >> nu;
			return 0;
		}
	}
	t.Input(); Tea[Teatop] = t; Teatop++;
	cout << "��ӳɹ���" << endl;
	return 1;
}
int TeaManager::Search()
{
	int j, n;
	cout << "�������ţ�"; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
		cout << "û�д��ˣ�" << endl;
	else
		Tea[j].Output();
	return 1;
}
void TeaManager::Show()
{
	int i;
	if (Teatop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl; return;
	}
	for (i = 0; i < Teatop; i++)
		Tea[i].Output();
}
void TeaManager::Edit()
{
	Teacher t1;
	int j, n;
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "û�д��ˣ�" << endl; return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Tea[j] = t1;
	cout << "�༭�ɹ���" << endl;
}
int TeaManager::Delete()
{
	int j, n;
	cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	for (j = 0; j < Teatop; j++)
	{
		if (n == Tea[j].num) break;
	}
	if (j == Teatop)
	{
		cout << "û�д��ˣ�" << endl; return 0;
	};
	for (j; j < Teatop; j++)
	{
		Tea[j] = Tea[j + 1];
	}
	Teatop--;
	cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Tea_mune(TeaManager TM)
{
	int b;
	char c;
	do {
		cout << "��ʦ����" << endl;
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
		case 1:TM.Add();  getchar(); break;
		case 2:TM.Search(); getchar(); break;
		case 3:TM.Show(); getchar(); break;
		case 4:TM.Edit(); getchar(); break;
		case 5:TM.Delete(); getchar(); break;
		case 6:cout << "���н�ʦ������" << Teatop << endl; getchar(); break;
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