#include<iostream>
#include"user.h"
#include<iomanip>
using namespace std;

void User::showinfo()
{
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->p_access << endl;
}

User::User(int no, string name, string access)
{
	this->p_no = no;
	this->p_name = name;
	this->p_access = access;
}

