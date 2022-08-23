#include<iostream>
#include"login.h"
#include"user.h"
#include"manager.h"
using namespace std;


int main() {

	LogIn um;//默认登录人员对象
	int choice = 0;
	while (true)
	{
		um.Show_menu();//登录菜单调用
		cout << "\t\t\t【系统提示】请输入你的选择项(0~3)：" << endl;
		cout << "\t\t\t";
		cin >> choice;
		if (choice < -1 || choice>3)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：" << endl;
			cout << "\t\t\t";
			cin >> choice;
		}
		switch (choice)
		{
		case 1: {
			//用户菜单调用
			User* u = new User();//默认用户人员
			u->user_Menu();
			int user_choice = 0;
			while (true)
			{
				cout << "\t\t\t【系统提示】请输入你的选择项(0~5)：" << endl;
				cout << "\t\t\t";
				cin >> user_choice;
				if (user_choice < -1 || user_choice>6)
				{
					cout << "\t\t\t【系统提示】输入格式错误，请重新输入：" << endl;
					cout << "\t\t\t";
					cin >> choice;
				}
				if (user_choice == 0) {
					break;//退出用户管理页面
				}
				switch (user_choice)
				{
				case 1:u->add_User();//添加用户信息
					break;
				case 2:u->delete_User();//删除用户信息
					break;
				case 3:u->select_User();//查询用户信息
					break;
				case 4:u->updata_User();//修改用户信息
					break;
				case 5:u->showInfo();//显示用户信息
				default:
					break;
				}
			}
			delete u;
			break;
		}
		case 2://管理员菜单调用
		{
			Manager* m = new Manager();//默认管理人员
			m->manager_Menu();
			int manager_choice = 0;
			while (true)
			{
				cout << "\t\t\t【系统提示】请输入你的选择项(0~4)：" << endl;
				cout << "\t\t\t";
				cin >> manager_choice;
				if (manager_choice < -1 || manager_choice>5)
				{
					cout << "\t\t\t【系统提示】输入格式错误，请重新输入：" << endl;
					cout << "\t\t\t";
					cin >> manager_choice;
				}
				if (manager_choice == 0) {//退出电影管理页面
					//um.Show_menu();
					break;
				}
				switch (manager_choice)
				{
				case 1:m->add_Movie();//添加电影信息
					break;
				case 2:m->delete_Movie();//删除电影信息
					break;
				case 3:m->select_Movie();//查询电影信息
					break;
				case 4:m->updata_Movie();//修改电影信息
					break;
				default:
					break;
				}
			}
			delete m;
			break; 
		}

		case 3:um.help_Menu(); break;//系统帮助调用
		case 0:um.exit_Menu(); break;//退出系统

		default:
			break;
		}
	}




	system("pause");
	return 0;
}
