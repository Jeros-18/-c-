
#include"stdlib.h"

#include "Policer.h"
#include "Teacher.h"
#include "Tester.h"
#include "login.h"

int main()
{
	TeaManager Tmer1;
	TestManager Tetmer;
	PolicerManager Polimer;
	user uesr;

	uesr.Display();
	cin.get();
	
	int a = 1, m = 0;
	char c;
	while (a)
	{
		system("cls");
		cout << endl;
		cout << "              ****��ӭʹ�ø�У��Ա��Ϣ����ϵͳ****" << endl;
		cout << "               =================================" << endl;
		cout << "               | 1.��ʦ����                    |" << endl;
		cout << "               | 2.ʵ��Ա����                  |" << endl;
		cout << "               | 3.����Ա����                  |" << endl;
		cout << "               | 0.�˳�                        |" << endl;
		cout << "               =================================" << endl;
		cout << "��ѡ��:"; cin >> a;

		switch (a)
		{
		case 1:Tea_mune(Tmer1); getchar(); break;
		case 2:Test_mune(Tetmer); getchar(); break;
		case 3:Policers_mune(Polimer); getchar(); break;
		case 0:break;
		default:cout << "\n error" << endl;
			cout << "���س�������" << endl;
			_flushall();
			c = getchar();
			break;
		}
	}

	cout << endl << "ллʹ��" << endl;
	_flushall();
	c = getchar();
	
	return 0;
}