#pragma once
#include<iostream>
#include"user.h"
#include"manager.h"
#include"moive.h"
#include<fstream>
#define FILENAME "userFile.txt"
using namespace std;

class pManager {
public:
	pManager();//��ʼ������
	~pManager();//�ͷŶ�������

	void show_Menu();//��¼�˵�
	void exit_Menu();//�˳�ϵͳ
	void add_user();//����Ա�����û�
	void p_save();//�������ݣ�����Աд���ļ��У�
	void init_per();//������Ա��Ϣ
	int get_pernum();//��ʾ����
	void del_per();//ɾ����Ա
	int is_exist(int i);//ͨ������ж��Ƿ���ڸ��û�
	void updata_per();//������Ա��Ϣ
	void user_face();////�û���¼�ɹ�����
	void user_log();//�û����е�¼
	void manager_log();//����Ա���е�¼
	void manage_face();////�����¼�ɹ�����
	void sel_face();//�û�������Ӱ����
	void table();//��Ա��ͷ
	void show_per();//��ʾ������

	int m_PerNum;//��¼��Ա����
	User** m_PerArray;//��Ա����ָ��
	bool fileisempt;//�ж��ļ��Ƿ�Ϊ��(��־��

};	
	 