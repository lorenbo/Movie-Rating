#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual void showinfo() = 0;//�����������ʾ�û���Ϣ��
	int p_no;//�û����
	string p_name;//�û�����
	string p_access;//�û�Ȩ��
};
