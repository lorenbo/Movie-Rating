#pragma once
#include<iostream>
#include"moive.h"
#include<fstream>
#define mFILENAME "moiveFile.txt"
using namespace std;

class mManager
{
public:
	mManager();//��ʼ������
	~mManager();//�ͷŶ�������

	bool fileisempt;//�ж��ļ��Ƿ�Ϊ��(��־��
	int m_MoiNum;//��¼��Ӱ����
	Moive** m_MoiArray;//��Ӱ����ָ��

	void add_moive();//���ӵ�Ӱ
	void m_save();//�������ݣ�����Ӱд���ļ��У�
	void init_moi();//���µ�Ӱ��Ϣ
	int get_moinum();//��õ�Ӱ����
	void show_moi();//��ʾ��Ӱ
	void table();//��Ӱ��ͷ
	void del_moi();//ɾ����Ӱ����Ӱ���ƣ�
	int is_exist(string m);//�жϸõ�Ӱ�Ƿ����(�����Ӱ��Ϣ���ƣ�����������)
	void sel_moi(string name);//���ҵ�Ӱ(����)
	void sel_type();//�����Ͳ��ҵ�Ӱ
	void sel_nat();//���������ҵ�Ӱ
	void updata_moi();//����һ����Ӱ��Ϣ�����ơ���ţ�
	void gra_moi();//����Ӱ����


};
