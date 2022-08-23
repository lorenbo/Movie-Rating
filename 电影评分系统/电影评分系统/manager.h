#pragma once
#include<iostream>
#include"person.h"
#include<string>
using namespace std;

class Manager:public Person
{
public:
	Manager(int no, string name, string access);
	virtual void showinfo();
};

