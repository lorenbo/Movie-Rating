#include<iostream>
using namespace std;
#include"moive.h"
#include"iomanip"

Moive::Moive(int no, string name, string types, string nation, string actor, int data, double grade, double sum,int num)
{
	this->m_no = no;
	this->m_name = name;
	this->m_types = types;
	this->m_nation = nation;
	this->m_actor = actor;
	this->m_data = data;
	this->m_grade = grade;
	this->m_sum = sum;
	this->m_num = num;

}
void Moive::showinfo() {
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_no
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_name
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_types
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_nation
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_actor
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_data
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_grade
		//<< setw(16) << setiosflags(ios::left) << setprecision(2) << setfill(' ') << this->m_grade
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_num << endl;

}

double Moive::score_movie(double a, double b, double c, double d) {
	double a1 = a * 0.30;
	double b1 = b * 0.25;
	double c1 = c * 0.25;
	double d1 = d * 0.20;
	double sum = a1 + b1 + c1 + d1;
	return sum;
}
