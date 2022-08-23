#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual void showinfo() = 0;//虚基函数（显示用户信息）
	int p_no;//用户编号
	string p_name;//用户姓名
	string p_access;//用户权限
};
