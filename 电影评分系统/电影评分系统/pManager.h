#pragma once
#include<iostream>
#include"user.h"
#include"manager.h"
#include"moive.h"
#include<fstream>
#define FILENAME "userFile.txt"
using namespace std;

class pManager {
public:
	pManager();//初始化属性
	~pManager();//释放堆区数据

	void show_Menu();//登录菜单
	void exit_Menu();//退出系统
	void add_user();//管理员增加用户
	void p_save();//保存数据（将人员写入文件中）
	void init_per();//更新人员信息
	int get_pernum();//显示人数
	void del_per();//删除人员
	int is_exist(int i);//通过编号判断是否存在该用户
	void updata_per();//更改人员信息
	void user_face();////用户登录成功界面
	void user_log();//用户进行登录
	void manager_log();//管理员进行登录
	void manage_face();////管理登录成功界面
	void sel_face();//用户搜索电影界面
	void table();//人员表头
	void show_per();//显示所有人

	int m_PerNum;//记录人员人数
	User** m_PerArray;//人员数组指针
	bool fileisempt;//判断文件是否为空(标志）

};	
	 