#pragma once
#include<iostream>
#include"person.h"
using namespace std;

class User:public Person
{
public:
	User(int no,string name,string access);
	void showinfo();
};

