#include"login.h"
LogIn::LogIn() {

}

//登录菜单调用
void LogIn::Show_menu() {
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃*********欢迎使用电影评分系统*********┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              1.用    户              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              2.管 理 员              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              3.系统帮助              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              0.退出系统              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
}


//系统帮助调用
void LogIn::help_Menu(){
	cout << "\t\t\t【系统提示】请联系工作人员!" << endl;
}

//退出系统
void LogIn::exit_Menu() {
	cout << "\t\t\t【系统提示】欢迎您的下次使用！" << endl;
	system("pause");
	exit(0);
}

LogIn::~LogIn() {

}