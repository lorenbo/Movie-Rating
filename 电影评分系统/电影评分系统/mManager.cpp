#include"manager.h"
#include"manager.h"
#include"user.h"
#include"moive.h"
#include"mManager.h"
#include"iomanip"


mManager::mManager(){//��ʼ������
	ifstream ifs;
	ifs.open(mFILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "\t\t\t��ϵͳ��ʾ���ļ������ڣ�" << endl;
		//���г�ʼ��
		this->m_MoiNum = 0;
		this->m_MoiArray = NULL;
		this->fileisempt = true;
		ifs.close();
		return;
	}
	int num = this->get_moinum();
	this->m_MoiNum = num;
	this->m_MoiArray = new Moive * [this->m_MoiNum];//���ļ���������
	this->init_moi();//���ݸ���
}

void mManager::add_moive()////���ӵ�Ӱ
{
	cout << "\t\t\t��ϵͳ��ʾ�����������ӵ�Ӱ����" << endl;
	cout << "\t\t\t";
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_MoiNum + addnum;
		Moive** newspace = new Moive * [newsize];
		if (this->m_MoiArray != NULL)
		{
			for (int i = 0; i < this->m_MoiNum; i++)
			{
				newspace[i] = this->m_MoiArray[i];
			}
		}
		for (int i = 0; i < addnum; i++)//����µ�����
		{
			int no;
			string name;
			string types;
			string nation;
			string actor;
			int data;
			double grade = 0;
			double sum=0;
			int num=0;
			cout << "\t\t\t��" << i + 1 << "����Ӱ���" << endl;
			cout << "\t\t\t";
			while (cin >> no)
			{
				int adjust = 0;
				for (int j = 0; j < this->m_MoiNum; j++)
				{
					if (no == this->m_MoiArray[j]->m_no)
					{
						cout << "\t\t\t��ϵͳ��ʾ���˱���Ѵ���!����������" << endl;
						adjust = 1;
					}
				}
				if (adjust == 0)
				{
					break;
				}
			}
			cout << "\t\t\t��" << i + 1 << "����Ӱ������:" << endl;
			cout << "\t\t\t";
			while (cin >> name)
			{
				int adjust = 0;
				for (int j = 0; j < this->m_MoiNum; j++)
				{
					if (name == this->m_MoiArray[j]->m_name)
					{
						cout << "\t\t\t��ϵͳ��ʾ���˵�Ӱ�Ѵ���!����������" << endl;
						adjust = 1;
					}
				}
				if (adjust == 0)
				{
					break;
				}
			}
			cout << "\t\t\t�������Ӱ������:" << endl;
			cout << "\t\t\t";
			cin >> types;
			cout << "\t\t\t�������Ӱ�Ĺ���:" << endl;
			cout << "\t\t\t";
			cin >> nation;
			cout << "\t\t\t�������Ӱ������:" << endl;
			cout << "\t\t\t";
			cin >> actor;
			cout << "\t\t\t�������Ӱ��ʱ��:" << endl;
			cout << "\t\t\t";
			cin >> data;
			Moive* m = NULL;
			m = new Moive(no, name, types, nation, actor, data,grade,sum,num);
			newspace[this->m_MoiNum + i] = m;//�������ĵ�Ӱָ�룬���浽������
		}

		delete[] this->m_MoiArray;//�ͷ�ԭ�еĿռ�
		this->m_MoiArray = newspace;//�����¿ռ��ָ��
		this->m_MoiNum = newsize;//���µ�Ӱ��
		cout << "\t\t\t��ϵͳ��ʾ���ɹ����" << addnum << "���µ�Ӱ" << endl;
		this->m_save();//�������ݵ��ļ���
	}
}

int mManager::get_moinum() {//��Ӱ����
	ifstream ifs;
	ifs.open(mFILENAME, ios::in);
	int no;
	string name;
	string types;
	string nation;
	string star;
	int time;
	double grade;
	double sum;
	int num;
	int count = 0;
	while (ifs >> no && ifs >> name && ifs >> types && ifs >> nation && ifs >> star && ifs >> time && ifs >> grade && ifs>>sum && ifs>> num)
	{
		count++;
	}
	return count;
}

void mManager::m_save() {//�������ݣ�����Ӱд���ļ��У�
	ofstream ofs;
	ofs.open(mFILENAME, ios::out);

	for (int i = 0; i < this->m_MoiNum; i++)
	{
		ofs << this->m_MoiArray[i]->m_no << " "
			<< this->m_MoiArray[i]->m_name << " "
			<< this->m_MoiArray[i]->m_types << " "
			<< this->m_MoiArray[i]->m_nation << " "
			<< this->m_MoiArray[i]->m_actor << " "
			<< this->m_MoiArray[i]->m_data << " "
			<< this->m_MoiArray[i]->m_grade << " "
			<< this->m_MoiArray[i]->m_sum << " "
			<< this->m_MoiArray[i]->m_num << endl;
	}
	ofs.close();
}

void mManager::init_moi() {//���µ�Ӱ����
	ifstream ifs;
	ifs.open(mFILENAME, ios::in);
	int no;
	int data;
	string name;
	string types;
	string nation;
	string actor;
	double grade;
	double sum=0;
	int num=0;
	int index = 0;
	while (ifs >> no && ifs >> name && ifs >> types && ifs >> nation && ifs >> actor && ifs >> data && ifs >> grade && ifs>>sum && ifs >> num )
	{
		Moive* m = NULL;
		m = new Moive(no, name, types, nation, actor, data , grade ,sum,num);
		this->m_MoiArray[index] = m;//������������
		index++;
	}
	ifs.close();
}

void mManager::show_moi() {// ��ʾ���е�Ӱ
	for (int i = 0; i < this->m_MoiNum; i++)
	{
		/*cout << setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_no
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_name
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_types
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_nation
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_actor
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_data
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_grade
			<< setw(16) << setiosflags(ios::left) << setfill(' ') << this->m_MoiArray[i]->m_num << endl;*/
		this->m_MoiArray[i]->showinfo();
	}
}

void mManager::table() {//��Ӱ��ͷ
	cout <<setw(16) << setiosflags(ios::left) << setfill(' ') << "���"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "ʱ�������ӣ�"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "����"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "���ִ���" << endl;
}

void mManager::del_moi() {//ɾ����Ӱ����Ӱ���ƣ�
	if (this->fileisempt)
	{
		cout << "\t\t\t��ϵͳ��ʾ���ļ�Ϊ�գ�" << endl;
	}
	else
	{
		cout << "\t\t\t��ϵͳ��ʾ������������ɾ���ĵ�Ӱ����:" << endl;
		cout << "\t\t\t";
		string name;
		cin >> name;
		int index = this->is_exist(name);
		if (index != -1)
		{
			for (int i = index; i < this->m_MoiNum - 1; i++) {
				this->m_MoiArray[i] = this->m_MoiArray[i + 1];
			}
			this->m_MoiNum--;//���µ�Ӱ����
			this->m_save();//���浽�ļ���
			cout << "\t\t\t��ϵͳ��ʾ��ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "\t\t\t��ϵͳ��ʾ��ɾ��ʧ�ܣ�δ�ҵ��õ�Ӱ��" << endl;
		}
	}
}

int mManager::is_exist(string m) {//�жϸõ�Ӱ�Ƿ����(�����Ӱ��Ϣ���ƣ�����������)
	int index = -1;
	for (int i = 0; i < this->m_MoiNum; i++)
	{
		if (this->m_MoiArray[i]->m_name == m ||
			this->m_MoiArray[i]->m_nation == m ||
			this->m_MoiArray[i]->m_types == m)
		{
			index = this->m_MoiArray[i]->m_no;
			break;
		}
	}
	return index;

}

//void mManager::updata_moi() {//���ĵ�Ӱ��Ϣ�����ơ���ţ�
//	if (this->fileisempt)
//	{
//		cout << "\t\t\t��ϵͳ��ʾ���ļ�Ϊ��!" << endl;
//	}
//	else
//	{
//		cout << "\t\t\t��Ҫѡ����ĵ�Ӱ����:" << endl;
//		cout << "\t\t\t";
//		string n;
//		cin >> n;
//		int index = this->is_exist(n)-1;
//		if (index != -2)
//		{
//				/*cout << "\t\t\t��Ҫѡ����ĵĵ�Ӱ���ԣ�" << endl;
//				cout << "\t\t\t��������������������������������������������������������������������������������\n";
//				cout << "\t\t\t��*********��ӭʹ�õ�Ӱ�޸�ϵͳ*********��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              1.����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              2.�����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              3.����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              4.�����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              5.�����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              0.��һ����              ��\t\n";
//				cout << "\t\t\t��������������������������������������������������������������������������������\n";
//				cout << endl;
//				int chocie = -1;
//				cout << "\t\t\t";
//				cin >> chocie;
//				switch (chocie)
//				{
//				case 0:
//				{
//					system("pause");
//					system("cls");
//				}
//				case 1:
//				{
//					cout << "\t\t\t���������޸ĺ�ı�ţ�";
//					int newNo;
//					cin >> newNo;
//					this->m_MoiArray[index]->m_no = newNo;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 2:
//				{
//					cout << "\t\t\t���������޸ĺ�����֣�";
//					int newName;
//					cin >> newName;
//					this->m_MoiArray[index]->m_name = newName;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 3:
//				{
//					cout << "\t\t\t���������޸ĺ�����";
//					int newType;
//					cin >> newType;
//					this->m_MoiArray[index]->m_types = newType;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 4:
//				{
//					cout << "\t\t\t���������޸ĺ�Ĺ��ң�";
//					int newNation;
//					cin >> newNation;
//					this->m_MoiArray[index]->m_nation = newNation;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 5:
//				{
//					cout << "\t\t\t���������޸ĺ�����ݣ�";
//					int newActor;
//					cin >> newActor;
//					this->m_MoiArray[index]->m_actor = newActor;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				default:
//					break;
//				}*/
//			
//			int no;
//			string name;
//			string types;
//			string nation;
//			string actor;
//			int data;
//			cout << "\t\t\t��������ĺ�ı��" << endl;
//			cout << "\t\t\t";
//			cin >> no;
//			cout << "\t\t\t��������ĺ�ĵ�Ӱ����" << endl;
//			cout << "\t\t\t";
//			cin >> name;
//			cout << "\t\t\t��������ĺ������" << endl;
//			cout << "\t\t\t";
//			cin >> types;
//			cout << "\t\t\t��������ĺ�Ĺ���" << endl;
//			cout << "\t\t\t";
//			cin >> nation;
//			cout << "\t\t\t��������ĺ������" << endl;
//			cout << "\t\t\t";
//			cin >> actor;
//			cout << "\t\t\t��������ĺ��ʱ��" << endl;
//			cout << "\t\t\t";
//			cin >> data;
//			this->m_MoiArray[index]->m_no = no;
//			this->m_MoiArray[index]->m_name = name;
//			this->m_MoiArray[index]->m_types = types;
//			this->m_MoiArray[index]->m_nation = nation;
//			this->m_MoiArray[index]->m_actor = actor;
//			this->m_MoiArray[index]->m_data = data;
//			this->m_save();//�������ݺ󣬱��浽�ļ���
//			cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//		}
//		else
//		{
//			cout << "\t\t\t��ϵͳ��ʾ���޸�ʧ�ܣ�δ�ҵ��õ�Ӱ��" << endl;
//		}
//	}
//}

void mManager::updata_moi() {//���ĵ�Ӱ��Ϣ�����ơ���ţ�
	if (this->fileisempt)
	{
		cout << "\t\t\t��ϵͳ��ʾ���ļ�Ϊ��!" << endl;
	}
	else
	{
		cout << "\t\t\t��Ҫѡ����ĵ�Ӱ����:" << endl;
		cout << "\t\t\t";
		string n;
		cin >> n;
		int index = this->is_exist(n) - 1;
		if (index != -2)
		{
			int no;
			string name;
			string types;
			string nation;
			string actor;
			int data;
			cout << "\t\t\t��������ĺ�ı��" << endl;
			cout << "\t\t\t";
			cin >> no;
			cout << "\t\t\t��������ĺ�ĵ�Ӱ����" << endl;
			cout << "\t\t\t";
			cin >> name;
			cout << "\t\t\t��������ĺ������" << endl;
			cout << "\t\t\t";
			cin >> types;
			cout << "\t\t\t��������ĺ�Ĺ���" << endl;
			cout << "\t\t\t";
			cin >> nation;
			cout << "\t\t\t��������ĺ������" << endl;
			cout << "\t\t\t";
			cin >> actor;
			cout << "\t\t\t��������ĺ��ʱ��" << endl;
			cout << "\t\t\t";
			cin >> data;
			this->m_MoiArray[index]->m_no = no;
			this->m_MoiArray[index]->m_name = name;
			this->m_MoiArray[index]->m_types = types;
			this->m_MoiArray[index]->m_nation = nation;
			this->m_MoiArray[index]->m_actor = actor;
			this->m_MoiArray[index]->m_data = data;
			this->m_save();//�������ݺ󣬱��浽�ļ���
			cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
		}
		else
		{
			cout << "\t\t\t��ϵͳ��ʾ����Ҫ����ĵ��û�������" << endl;
		}
	}

}

void mManager::sel_moi(string name) {//���ҵ�Ӱ(����)
	int index = -1;
	cout << "\t\t\t��ϵͳ��ʾ����������Ҫ���ҵĵ�Ӱ�����֣�";
	cout << "\t\t\t" << endl;
	while (index == -1 )
	{
		cout << "\t\t\t";
		cin >> name;
		index = this->is_exist(name);
		if (index != -1)
		{
			for (int i = 0; i < this->m_MoiNum; i++)
			{
				while (this->m_MoiArray[i]->m_name == name)
				{
					this->table();//��Ӱ��ͷ
					this->m_MoiArray[i]->showinfo();
					break;
				}
			}
		}
		else
		{
			cout << "\t\t\t��ϵͳ��ʾ������ҵĵ�Ӱ�����ڣ�����������:" << endl;
			continue;
		}
	}
}

void mManager::gra_moi() {//����Ӱ����
	int index = 0;
	string name;
	while (index == 0)
	{
		cout << "\t\t\t��ϵͳ��ʾ���������������ֵĵ�Ӱ������" << endl;
		cout << "\t\t\t";
		cin >> name;
		index = this->is_exist(name);
		while (index != -1)
		{
			double a, b, c, d;
			double score=0.0;
			cout << "\t\t\t��ϵͳ��ʾ�������Ӱ��֣������0-10��:" << endl;
			cout << "\t\t\t����ռ��30%:";
			cin >> a;
			cout << "\t\t\t����ռ��25%:";
			cin >> b;
			cout << "\t\t\t����ռ��25%:";
			cin >> c;
			cout << "\t\t\t����ռ��20%:";
			cin >> d;
			for (int i = 0; i < this->m_MoiNum; i++)
			{
				while (this->m_MoiArray[i]->m_no == this->is_exist(name))//index = this->is_exist(name);
				{
					if (this->m_MoiArray[i]->m_grade == 0)//û�����۹�
					{
						this->m_MoiArray[i]->m_num++;//���۴���+1
						this->m_MoiArray[i]->m_grade = score;
					}
					else
					{
						this->m_MoiArray[i]->m_num++;//���۴���+1
						this->m_MoiArray[i]->m_grade = (this->m_MoiArray[i]->score_movie(a, b, c, d) +
							this->m_MoiArray[i]->m_sum) / this->m_MoiArray[i]->m_num;
					}
					this->m_MoiArray[i]->m_sum = this->m_MoiArray[i]->m_sum + this->m_MoiArray[i]->score_movie(a, b, c, d);
					break;
				}
			}
			//��������
			score = this->m_MoiArray[index]->score_movie(a, b, c, d);
			cout << "\t\t\t";
			cout << "�����Ӱ" << name << "������Ϊ��" << score << endl;
			cout << "\t\t\t";
			cout << "��Ӱ" << name << "���յ�������" << this->m_MoiArray[index]->m_grade;
			
			cout << "\t\t\t" << endl;
			cout << "\t\t\t��ϵͳ��ʾ�����ֳɹ�" << endl;
			this->m_save();
			system("pause");
			return;
		}
		cout << "\t\t\t��ϵͳ��ʾ���Ҳ�����Ҫ���ֵĵ�Ӱ" << endl;
		break;
	}
}

void mManager::sel_type() {//�����Ͳ��ҵ�Ӱ
	string type;
	cout << "\t\t\t��ϵͳ��ʾ����������Ҫ���ҵĵ�Ӱ����:";
	cout << "\t\t\t" << endl;
	int index = -1;
	while (index == -1)
	{
		cout << "\t\t\t";
		cin >> type;
		index = this->is_exist(type);
		if (index != -1)
		{
			this->table();//��Ӱ��ͷ
			for (int i = 0; i < this->m_MoiNum; i++)
			{
				while (this->m_MoiArray[i]->m_types == type)
				{

					this->m_MoiArray[i]->showinfo();
					break;
				}
			}
		}
		else
		{
			cout << "\t\t\t��ϵͳ��ʾ������ҵĵ�Ӱ�඼û�У�����������:" << endl;
			continue;
		}
	}
}

void mManager::sel_nat() {//����������
	string nation;
	cout << "\t\t\t��ϵͳ��ʾ����������Ҫ���ҵĵ�Ӱ����:";
	cout << endl;
	int index = -1;
	while (index == -1)
	{
		cin >> nation;
		index = this->is_exist(nation);
		if (index != -1)
		{
			this->table();
			for (int i = 0; i < this->m_MoiNum; i++)
			{
				while (this->m_MoiArray[i]->m_nation == nation)
				{
					this->m_MoiArray[i]->showinfo();
					break;
				}
			}
		}
		else
		{
			cout << "\t\t\t��ϵͳ��ʾ������ҵĵ�Ӱ������û�У�����������:" << endl;
			continue;
		}
	}
}
//void mManager::updata_moi() {//���ĵ�Ӱ��Ϣ�����ơ���ţ�
//	if (this->fileisempt)
//	{
//		cout << "\t\t\t��ϵͳ��ʾ���ļ�Ϊ��!" << endl;
//	}
//	else
//	{
//		cout << "\t\t\t��Ҫѡ����ĵ�Ӱ����:" << endl;
//		cout << "\t\t\t";
//		string n;
//		cin >> n;
//		int index = this->is_exist(n)-1;
//		if (index != -2)
//		{
//				/*cout << "\t\t\t��Ҫѡ����ĵĵ�Ӱ���ԣ�" << endl;
//				cout << "\t\t\t��������������������������������������������������������������������������������\n";
//				cout << "\t\t\t��*********��ӭʹ�õ�Ӱ�޸�ϵͳ*********��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              1.����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              2.�����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              3.����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              4.�����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              5.�����޸�              ��\t\n";
//				cout << "\t\t\t��                                      ��\t\n";
//				cout << "\t\t\t��              0.��һ����              ��\t\n";
//				cout << "\t\t\t��������������������������������������������������������������������������������\n";
//				cout << endl;
//				int chocie = -1;
//				cout << "\t\t\t";
//				cin >> chocie;
//				switch (chocie)
//				{
//				case 0:
//				{
//					system("pause");
//					system("cls");
//				}
//				case 1:
//				{
//					cout << "\t\t\t���������޸ĺ�ı�ţ�";
//					int newNo;
//					cin >> newNo;
//					this->m_MoiArray[index]->m_no = newNo;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 2:
//				{
//					cout << "\t\t\t���������޸ĺ�����֣�";
//					int newName;
//					cin >> newName;
//					this->m_MoiArray[index]->m_name = newName;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 3:
//				{
//					cout << "\t\t\t���������޸ĺ�����";
//					int newType;
//					cin >> newType;
//					this->m_MoiArray[index]->m_types = newType;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 4:
//				{
//					cout << "\t\t\t���������޸ĺ�Ĺ��ң�";
//					int newNation;
//					cin >> newNation;
//					this->m_MoiArray[index]->m_nation = newNation;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				case 5:
//				{
//					cout << "\t\t\t���������޸ĺ�����ݣ�";
//					int newActor;
//					cin >> newActor;
//					this->m_MoiArray[index]->m_actor = newActor;
//					this->m_save();
//					cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//					break;
//				}
//				default:
//					break;
//				}*/
//			
//			int no;
//			string name;
//			string types;
//			string nation;
//			string actor;
//			int data;
//			cout << "\t\t\t��������ĺ�ı��" << endl;
//			cout << "\t\t\t";
//			cin >> no;
//			cout << "\t\t\t��������ĺ�ĵ�Ӱ����" << endl;
//			cout << "\t\t\t";
//			cin >> name;
//			cout << "\t\t\t��������ĺ������" << endl;
//			cout << "\t\t\t";
//			cin >> types;
//			cout << "\t\t\t��������ĺ�Ĺ���" << endl;
//			cout << "\t\t\t";
//			cin >> nation;
//			cout << "\t\t\t��������ĺ������" << endl;
//			cout << "\t\t\t";
//			cin >> actor;
//			cout << "\t\t\t��������ĺ��ʱ��" << endl;
//			cout << "\t\t\t";
//			cin >> data;
//			this->m_MoiArray[index]->m_no = no;
//			this->m_MoiArray[index]->m_name = name;
//			this->m_MoiArray[index]->m_types = types;
//			this->m_MoiArray[index]->m_nation = nation;
//			this->m_MoiArray[index]->m_actor = actor;
//			this->m_MoiArray[index]->m_data = data;
//			this->m_save();//�������ݺ󣬱��浽�ļ���
//			cout << "\t\t\t��ϵͳ��ʾ����Ϣ���ĳɹ�!" << endl;
//		}
//		else
//		{
//			cout << "\t\t\t��ϵͳ��ʾ���޸�ʧ�ܣ�δ�ҵ��õ�Ӱ��" << endl;
//		}
//	}
//}
mManager::~mManager() {}



