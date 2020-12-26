
#include"stdlib.h"

#include "Policer.h"
#include "Teacher.h"
#include "Tester.h"







int main()
{
	TeaManager Tmer1;
	TestManager Tetmer;
	PolicerManager Polimer;
	int a = 1, m = 0;
	char c;
	cout << "    *************************************";
	cout << endl << "    $         高校人员管理系统         $" << endl;
	cout << "    *************************************";
	cout << endl << "请输入密码："; cin >> m;

	if (m != 666)
	{
		cout << "密码错误！" << endl;
		_flushall();
		c = getchar();
		return 0;
	}

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