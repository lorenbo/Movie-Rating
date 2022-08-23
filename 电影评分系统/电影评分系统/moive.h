#pragma once
#include<iostream>
#include<string>
using namespace std;

class Moive
{
public:
	Moive(int no, string name, string types, string nation, string actor, int data,double grade,double m_sun,int m_num);
	double score_movie(double a, double b, double c, double d);
	void showinfo();

	int m_no;//电影编号
	string m_name;//电影名称
	string m_types;//电影类型
	string m_nation;//电影国籍
	string m_actor;//电影主演
	int m_data;//电影时长
	double m_grade = 0;//电影评分
	double m_sum=0;//评分总和
	int m_num=0;//评分次数
};
