#include"login.h"
LogIn::LogIn() {

}

//��¼�˵�����
void LogIn::Show_menu() {
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��*********��ӭʹ�õ�Ӱ����ϵͳ*********��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              1.��    ��              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              2.�� �� Ա              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              3.ϵͳ����              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��              0.�˳�ϵͳ              ��\t\n";
	cout << "\t\t\t��                                      ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << endl;
}


//ϵͳ��������
void LogIn::help_Menu(){
	cout << "\t\t\t��ϵͳ��ʾ������ϵ������Ա!" << endl;
}

//�˳�ϵͳ
void LogIn::exit_Menu() {
	cout << "\t\t\t��ϵͳ��ʾ����ӭ�����´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

LogIn::~LogIn() {

}