#pragma once //防止头文件重名包含
#include<iostream>
using namespace std;
class LogIn {
public:
	LogIn();
	void Show_menu();//登录菜单调用
	void help_Menu();//系统帮助调用
	void exit_Menu();//退出系统
	~LogIn();

};