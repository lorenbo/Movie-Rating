#include<iostream>
#include"manager.h"
#include<iomanip>
using namespace std;

void Manager::showinfo()
{
	//cout << "人员编号：" << this->p_no
	//	<< "\t名字：" << this->p_name
	//	<<"\t权限："<<this->p_access<< endl;
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_access << endl;
}
Manager::Manager(int no, string name, string access)
{
	this->p_no = no;
	this->p_name = name;
	this->p_access = access;
}