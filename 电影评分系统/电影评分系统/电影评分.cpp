#include<iostream>
#include"login.h"
#include"user.h"
#include"manager.h"
using namespace std;


int main() {

	LogIn um;//Ĭ�ϵ�¼��Ա����
	int choice = 0;
	while (true)
	{
		um.Show_menu();//��¼�˵�����
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ����(0~3)��" << endl;
		cout << "\t\t\t";
		cin >> choice;
		if (choice < -1 || choice>3)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺" << endl;
			cout << "\t\t\t";
			cin >> choice;
		}
		switch (choice)
		{
		case 1: {
			//�û��˵�����
			User* u = new User();//Ĭ���û���Ա
			u->user_Menu();
			int user_choice = 0;
			while (true)
			{
				cout << "\t\t\t��ϵͳ��ʾ�����������ѡ����(0~5)��" << endl;
				cout << "\t\t\t";
				cin >> user_choice;
				if (user_choice < -1 || user_choice>6)
				{
					cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺" << endl;
					cout << "\t\t\t";
					cin >> choice;
				}
				if (user_choice == 0) {
					break;//�˳��û�����ҳ��
				}
				switch (user_choice)
				{
				case 1:u->add_User();//����û���Ϣ
					break;
				case 2:u->delete_User();//ɾ���û���Ϣ
					break;
				case 3:u->select_User();//��ѯ�û���Ϣ
					break;
				case 4:u->updata_User();//�޸��û���Ϣ
					break;
				case 5:u->showInfo();//��ʾ�û���Ϣ
				default:
					break;
				}
			}
			delete u;
			break;
		}
		case 2://����Ա�˵�����
		{
			Manager* m = new Manager();//Ĭ�Ϲ�����Ա
			m->manager_Menu();
			int manager_choice = 0;
			while (true)
			{
				cout << "\t\t\t��ϵͳ��ʾ�����������ѡ����(0~4)��" << endl;
				cout << "\t\t\t";
				cin >> manager_choice;
				if (manager_choice < -1 || manager_choice>5)
				{
					cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺" << endl;
					cout << "\t\t\t";
					cin >> manager_choice;
				}
				if (manager_choice == 0) {//�˳���Ӱ����ҳ��
					//um.Show_menu();
					break;
				}
				switch (manager_choice)
				{
				case 1:m->add_Movie();//��ӵ�Ӱ��Ϣ
					break;
				case 2:m->delete_Movie();//ɾ����Ӱ��Ϣ
					break;
				case 3:m->select_Movie();//��ѯ��Ӱ��Ϣ
					break;
				case 4:m->updata_Movie();//�޸ĵ�Ӱ��Ϣ
					break;
				default:
					break;
				}
			}
			delete m;
			break; 
		}

		case 3:um.help_Menu(); break;//ϵͳ��������
		case 0:um.exit_Menu(); break;//�˳�ϵͳ

		default:
			break;
		}
	}




	system("pause");
	return 0;
}
