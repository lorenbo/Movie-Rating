#include<iostream>
#include"pManager.h"
#include"mManager.h"
#include"manager.h"
#include"user.h"
#include<iomanip>
#include<cstdlib>
using namespace std;

int main() {
	pManager pm;//
	mManager mm;
	int choice;
	string name;
	while (true)
	{
		pm.show_Menu();
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��:" << endl;
		cout << "\t\t\t";
		cin >> choice;
		switch (choice)
		{
		case 0:
			system("cls");
			pm.exit_Menu();
			break;
		case 1:
			pm.user_log();//�û���¼
			while (true)
			{
				pm.user_face();//��¼�ɹ����û��˵���
				cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��:" << endl;
				cout << "\t\t\t";
				int choice2;
				cin >> choice2;
				system("cls");
				switch (choice2)
				{
				case 0://�˳�ϵͳ
					system("cls");
					pm.exit_Menu();
					break;
				case 1://������Ӱ
					int c;
					while (true)
					{
						pm.sel_face();
						cout << "\t\t\t��ϵͳ��ʾ������������Ҫ������Ӱ�Ĳ���" << endl;
						cout << "\t\t\t";
						cin >> c;
						if (c == 4)
						{
							break;
						}
						switch (c)
						{
						case 1:
							mm.sel_moi(name);//����������
							system("pause");
							system("cls");
							break;
						case 2:
							mm.sel_type();//����������
							system("pause");
							system("cls");
							break;
						case 3:
							mm.sel_nat();//����������
							system("pause");
							system("cls");
							break;
						case 0:
							system("cls");
							pm.exit_Menu();
							return 0;
						default:
							system("cls");
							break;
						}
					}
					system("cls");
					continue;
				case 2://��Ӱ���
					mm.table();
					mm.show_moi();
					mm.gra_moi();
					system("cls");
					continue;
				case 3://���ؽ���
					system("cls");
					break;
				default:
					system("cls");
					break;
				}
				system("cls");
				break;
			}
			break;
		case 2://����Ա��¼
			pm.manager_log();
			while (true)
			{
				pm.manage_face();
				cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��:" << endl;
				cout << "\t\t\t";
				int choice3;
				cin >> choice3;
				if (choice3 == 9)
				{
					break;
				}
				switch (choice3)
				{
				case 1:
					pm.table();
					pm.show_per();
					system("pause");
					break;
				case 2:
					pm.add_user();
					system("pause");
					break;
				case 3:
				     pm.del_per();//ɾ
					system("pause");
					break;
				case 4:
					pm.updata_per();//��
					system("pause");
					break;
				case 5:
					mm.table();//��Ӱ��ͷ
					mm.show_moi();
					system("pause");
					break;
				case 6:
					mm.add_moive();
					system("pause");
					break;
				case 7:
					mm.del_moi();
					system("pause");
					break;
				case 8:
					mm.table();
					mm.show_moi();
					mm.updata_moi();//�ĵ�Ӱ
					system("pause");
					system("cls");
					break;
				default:
					system("cls");
					return 0;
				}
				system("cls");
				
			}
		

		default:
			system("cls");
			break;
		}	
	}
	system("pause");
}