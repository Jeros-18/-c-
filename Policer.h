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
		cout << "������ò: " << polices << "  " << "ְ��: " << post1 << endl;

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
		cout << "��������" << endl;
		return 0;
	}
	cout << "�������ţ�"; cin >> nu;
	for (i = 0; i < Policersop; i++)
	{
		if (nu == Policers[i].num)
		{
			cout << "���б�ţ��������" << endl;
			return 0;
		}
	}
	t.Input();
	Policers[Policersop] = t;
	Policersop++;
	cout << "��ӳɹ���" << endl;
	return 1;
}
int PolicerManager::Search()
{
	int j, n;
	cout << "�������ţ�"; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
		cout << "û�д��ˣ�" << endl;
	else
		Policers[j].Output();
	return 1;
}
void PolicerManager::Show()
{
	int i;
	if (Policersop == 0)
	{
		cout << "��¼Ϊ�գ�" << endl; return;
	}
	for (i = 0; i < Policersop; i++)
		Policers[i].Output();
}
void PolicerManager::Edit()
{
	Policer t1;
	int j, n;
	cout << "������Ҫ�༭���˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "û�д��ˣ�" << endl; return;
	};
	cout << "�����޸ĺ����Ϣ����Ų��ܸ�:" << endl;
	t1.Input();
	Policers[j] = t1;
	cout << "�༭�ɹ���" << endl;
}
int PolicerManager::Delete()
{
	int j, n;
	cout << "������Ҫɾ�����˵ı�ţ�"; cin >> n;
	for (j = 0; j < Policersop; j++)
	{
		if (n == Policers[j].num) break;
	}
	if (j == Policersop)
	{
		cout << "û�д��ˣ�" << endl; return 0;
	};
	for (j; j < Policersop; j++)
	{
		Policers[j] = Policers[j + 1];
	}
	Policersop--;
	cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}
void Policers_mune(PolicerManager TM)
{
	int b;
	char c;
	do {
		cout << "������Ա����" << endl;
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
		case 6:cout << "��������Ա������" << Policersop << endl; getchar(); break;
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