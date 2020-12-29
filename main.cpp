
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
		cout << "              ****欢迎使用高校人员信息管理系统****" << endl;
		cout << "               =================================" << endl;
		cout << "               | 1.教师管理                    |" << endl;
		cout << "               | 2.实验员管理                  |" << endl;
		cout << "               | 3.行政员管理                  |" << endl;
		cout << "               | 0.退出                        |" << endl;
		cout << "               =================================" << endl;
		cout << "请选择:"; cin >> a;

		switch (a)
		{
		case 1:Tea_mune(Tmer1); getchar(); break;
		case 2:Test_mune(Tetmer); getchar(); break;
		case 3:Policers_mune(Polimer); getchar(); break;
		case 0:break;
		default:cout << "\n error" << endl;
			cout << "按回车键继续" << endl;
			_flushall();
			c = getchar();
			break;
		}
	}

	cout << endl << "谢谢使用" << endl;
	_flushall();
	c = getchar();
	
	return 0;
}