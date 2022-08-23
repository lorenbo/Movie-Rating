#pragma once
#include<iostream>
#include"moive.h"
#include<fstream>
#define mFILENAME "moiveFile.txt"
using namespace std;

class mManager
{
public:
	mManager();//初始化属性
	~mManager();//释放堆区数据

	bool fileisempt;//判断文件是否为空(标志）
	int m_MoiNum;//记录电影数量
	Moive** m_MoiArray;//电影数组指针

	void add_moive();//增加电影
	void m_save();//保存数据（将电影写入文件中）
	void init_moi();//更新电影信息
	int get_moinum();//获得电影数量
	void show_moi();//显示电影
	void table();//电影表头
	void del_moi();//删除电影（电影名称）
	int is_exist(string m);//判断该电影是否存在(传入电影信息名称，国籍，类型)
	void sel_moi(string name);//查找电影(名称)
	void sel_type();//按类型查找电影
	void sel_nat();//按国籍查找电影
	void updata_moi();//更改一个电影信息（名称、编号）
	void gra_moi();//给电影评分


};
