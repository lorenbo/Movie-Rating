#include"manager.h"
#include"manager.h"
#include"user.h"
#include"moive.h"
#include"mManager.h"
#include"iomanip"


mManager::mManager(){//初始化属性
	ifstream ifs;
	ifs.open(mFILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "\t\t\t【系统提示】文件不存在！" << endl;
		//进行初始化
		this->m_MoiNum = 0;
		this->m_MoiArray = NULL;
		this->fileisempt = true;
		ifs.close();
		return;
	}
	int num = this->get_moinum();
	this->m_MoiNum = num;
	this->m_MoiArray = new Moive * [this->m_MoiNum];//将文件放入数组
	this->init_moi();//数据更新
}

void mManager::add_moive()////增加电影
{
	cout << "\t\t\t【系统提示】请输入增加电影数量" << endl;
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
		for (int i = 0; i < addnum; i++)//添加新的数据
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
			cout << "\t\t\t第" << i + 1 << "个电影编号" << endl;
			cout << "\t\t\t";
			while (cin >> no)
			{
				int adjust = 0;
				for (int j = 0; j < this->m_MoiNum; j++)
				{
					if (no == this->m_MoiArray[j]->m_no)
					{
						cout << "\t\t\t【系统提示】此编号已存在!请重新输入" << endl;
						adjust = 1;
					}
				}
				if (adjust == 0)
				{
					break;
				}
			}
			cout << "\t\t\t第" << i + 1 << "个电影的姓名:" << endl;
			cout << "\t\t\t";
			while (cin >> name)
			{
				int adjust = 0;
				for (int j = 0; j < this->m_MoiNum; j++)
				{
					if (name == this->m_MoiArray[j]->m_name)
					{
						cout << "\t\t\t【系统提示】此电影已存在!请重新输入" << endl;
						adjust = 1;
					}
				}
				if (adjust == 0)
				{
					break;
				}
			}
			cout << "\t\t\t请输入电影的类型:" << endl;
			cout << "\t\t\t";
			cin >> types;
			cout << "\t\t\t请输入电影的国家:" << endl;
			cout << "\t\t\t";
			cin >> nation;
			cout << "\t\t\t请输入电影的主演:" << endl;
			cout << "\t\t\t";
			cin >> actor;
			cout << "\t\t\t请输入电影的时长:" << endl;
			cout << "\t\t\t";
			cin >> data;
			Moive* m = NULL;
			m = new Moive(no, name, types, nation, actor, data,grade,sum,num);
			newspace[this->m_MoiNum + i] = m;//将创建的电影指针，保存到数组中
		}

		delete[] this->m_MoiArray;//释放原有的空间
		this->m_MoiArray = newspace;//更改新空间的指向
		this->m_MoiNum = newsize;//更新电影数
		cout << "\t\t\t【系统提示】成功添加" << addnum << "个新电影" << endl;
		this->m_save();//保存数据到文件中
	}
}

int mManager::get_moinum() {//电影总数
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

void mManager::m_save() {//保存数据（将电影写入文件中）
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

void mManager::init_moi() {//更新电影数据
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
		this->m_MoiArray[index] = m;//保存在数组中
		index++;
	}
	ifs.close();
}

void mManager::show_moi() {// 显示所有电影
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

void mManager::table() {//电影表头
	cout <<setw(16) << setiosflags(ios::left) << setfill(' ') << "编号"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "名称"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "类型"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "国家"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "主演"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "时长（分钟）"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "评分"
		<< setw(16) << setiosflags(ios::left) << setfill(' ') << "评分次数" << endl;
}

void mManager::del_moi() {//删除电影（电影名称）
	if (this->fileisempt)
	{
		cout << "\t\t\t【系统提示】文件为空！" << endl;
	}
	else
	{
		cout << "\t\t\t【系统提示】请输入你想删除的电影名称:" << endl;
		cout << "\t\t\t";
		string name;
		cin >> name;
		int index = this->is_exist(name);
		if (index != -1)
		{
			for (int i = index; i < this->m_MoiNum - 1; i++) {
				this->m_MoiArray[i] = this->m_MoiArray[i + 1];
			}
			this->m_MoiNum--;//更新电影数量
			this->m_save();//保存到文件中
			cout << "\t\t\t【系统提示】删除成功！" << endl;
		}
		else
		{
			cout << "\t\t\t【系统提示】删除失败，未找到该电影！" << endl;
		}
	}
}

int mManager::is_exist(string m) {//判断该电影是否存在(传入电影信息名称，国籍，类型)
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

//void mManager::updata_moi() {//更改电影信息（名称、编号）
//	if (this->fileisempt)
//	{
//		cout << "\t\t\t【系统提示】文件为空!" << endl;
//	}
//	else
//	{
//		cout << "\t\t\t你要选择更改电影名称:" << endl;
//		cout << "\t\t\t";
//		string n;
//		cin >> n;
//		int index = this->is_exist(n)-1;
//		if (index != -2)
//		{
//				/*cout << "\t\t\t你要选择更改的电影属性：" << endl;
//				cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
//				cout << "\t\t\t┃*********欢迎使用电影修改系统*********┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              1.编号修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              2.名字修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              3.类别修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              4.国家修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              5.主演修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              0.上一界面              ┃\t\n";
//				cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
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
//					cout << "\t\t\t请你输入修改后的编号：";
//					int newNo;
//					cin >> newNo;
//					this->m_MoiArray[index]->m_no = newNo;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 2:
//				{
//					cout << "\t\t\t请你输入修改后的名字：";
//					int newName;
//					cin >> newName;
//					this->m_MoiArray[index]->m_name = newName;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 3:
//				{
//					cout << "\t\t\t请你输入修改后的类别：";
//					int newType;
//					cin >> newType;
//					this->m_MoiArray[index]->m_types = newType;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 4:
//				{
//					cout << "\t\t\t请你输入修改后的国家：";
//					int newNation;
//					cin >> newNation;
//					this->m_MoiArray[index]->m_nation = newNation;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 5:
//				{
//					cout << "\t\t\t请你输入修改后的主演：";
//					int newActor;
//					cin >> newActor;
//					this->m_MoiArray[index]->m_actor = newActor;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
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
//			cout << "\t\t\t请输入更改后的编号" << endl;
//			cout << "\t\t\t";
//			cin >> no;
//			cout << "\t\t\t请输入更改后的电影名称" << endl;
//			cout << "\t\t\t";
//			cin >> name;
//			cout << "\t\t\t请输入更改后的类型" << endl;
//			cout << "\t\t\t";
//			cin >> types;
//			cout << "\t\t\t请输入更改后的国籍" << endl;
//			cout << "\t\t\t";
//			cin >> nation;
//			cout << "\t\t\t请输入更改后的主演" << endl;
//			cout << "\t\t\t";
//			cin >> actor;
//			cout << "\t\t\t请输入更改后的时长" << endl;
//			cout << "\t\t\t";
//			cin >> data;
//			this->m_MoiArray[index]->m_no = no;
//			this->m_MoiArray[index]->m_name = name;
//			this->m_MoiArray[index]->m_types = types;
//			this->m_MoiArray[index]->m_nation = nation;
//			this->m_MoiArray[index]->m_actor = actor;
//			this->m_MoiArray[index]->m_data = data;
//			this->m_save();//更新数据后，保存到文件中
//			cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//		}
//		else
//		{
//			cout << "\t\t\t【系统提示】修改失败，未找到该电影！" << endl;
//		}
//	}
//}

void mManager::updata_moi() {//更改电影信息（名称、编号）
	if (this->fileisempt)
	{
		cout << "\t\t\t【系统提示】文件为空!" << endl;
	}
	else
	{
		cout << "\t\t\t你要选择更改电影名称:" << endl;
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
			cout << "\t\t\t请输入更改后的编号" << endl;
			cout << "\t\t\t";
			cin >> no;
			cout << "\t\t\t请输入更改后的电影名称" << endl;
			cout << "\t\t\t";
			cin >> name;
			cout << "\t\t\t请输入更改后的类型" << endl;
			cout << "\t\t\t";
			cin >> types;
			cout << "\t\t\t请输入更改后的国籍" << endl;
			cout << "\t\t\t";
			cin >> nation;
			cout << "\t\t\t请输入更改后的主演" << endl;
			cout << "\t\t\t";
			cin >> actor;
			cout << "\t\t\t请输入更改后的时长" << endl;
			cout << "\t\t\t";
			cin >> data;
			this->m_MoiArray[index]->m_no = no;
			this->m_MoiArray[index]->m_name = name;
			this->m_MoiArray[index]->m_types = types;
			this->m_MoiArray[index]->m_nation = nation;
			this->m_MoiArray[index]->m_actor = actor;
			this->m_MoiArray[index]->m_data = data;
			this->m_save();//更新数据后，保存到文件中
			cout << "\t\t\t【系统提示】信息更改成功!" << endl;
		}
		else
		{
			cout << "\t\t\t【系统提示】你要求更改的用户不存在" << endl;
		}
	}

}

void mManager::sel_moi(string name) {//查找电影(名称)
	int index = -1;
	cout << "\t\t\t【系统提示】请输入你要查找的电影的名字：";
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
					this->table();//电影表头
					this->m_MoiArray[i]->showinfo();
					break;
				}
			}
		}
		else
		{
			cout << "\t\t\t【系统提示】你查找的电影不存在，请重新输入:" << endl;
			continue;
		}
	}
}

void mManager::gra_moi() {//给电影评分
	int index = 0;
	string name;
	while (index == 0)
	{
		cout << "\t\t\t【系统提示】请输入你想评分的电影的名字" << endl;
		cout << "\t\t\t";
		cin >> name;
		index = this->is_exist(name);
		while (index != -1)
		{
			double a, b, c, d;
			double score=0.0;
			cout << "\t\t\t【系统提示】请给电影打分，各板块0-10分:" << endl;
			cout << "\t\t\t剧情占比30%:";
			cin >> a;
			cout << "\t\t\t画面占比25%:";
			cin >> b;
			cout << "\t\t\t表演占比25%:";
			cin >> c;
			cout << "\t\t\t音乐占比20%:";
			cin >> d;
			for (int i = 0; i < this->m_MoiNum; i++)
			{
				while (this->m_MoiArray[i]->m_no == this->is_exist(name))//index = this->is_exist(name);
				{
					if (this->m_MoiArray[i]->m_grade == 0)//没有评论过
					{
						this->m_MoiArray[i]->m_num++;//评论次数+1
						this->m_MoiArray[i]->m_grade = score;
					}
					else
					{
						this->m_MoiArray[i]->m_num++;//评论次数+1
						this->m_MoiArray[i]->m_grade = (this->m_MoiArray[i]->score_movie(a, b, c, d) +
							this->m_MoiArray[i]->m_sum) / this->m_MoiArray[i]->m_num;
					}
					this->m_MoiArray[i]->m_sum = this->m_MoiArray[i]->m_sum + this->m_MoiArray[i]->score_movie(a, b, c, d);
					break;
				}
			}
			//保存数据
			score = this->m_MoiArray[index]->score_movie(a, b, c, d);
			cout << "\t\t\t";
			cout << "你给电影" << name << "的评分为：" << score << endl;
			cout << "\t\t\t";
			cout << "电影" << name << "最终的评分是" << this->m_MoiArray[index]->m_grade;
			
			cout << "\t\t\t" << endl;
			cout << "\t\t\t【系统提示】评分成功" << endl;
			this->m_save();
			system("pause");
			return;
		}
		cout << "\t\t\t【系统提示】找不到你要评分的电影" << endl;
		break;
	}
}

void mManager::sel_type() {//按类型查找电影
	string type;
	cout << "\t\t\t【系统提示】请输入你要查找的电影类型:";
	cout << "\t\t\t" << endl;
	int index = -1;
	while (index == -1)
	{
		cout << "\t\t\t";
		cin >> type;
		index = this->is_exist(type);
		if (index != -1)
		{
			this->table();//电影表头
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
			cout << "\t\t\t【系统提示】你查找的电影类都没有，请重新输入:" << endl;
			continue;
		}
	}
}

void mManager::sel_nat() {//按国籍查找
	string nation;
	cout << "\t\t\t【系统提示】请输入你要查找的电影国家:";
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
			cout << "\t\t\t【系统提示】你查找的电影国籍都没有，请重新输入:" << endl;
			continue;
		}
	}
}
//void mManager::updata_moi() {//更改电影信息（名称、编号）
//	if (this->fileisempt)
//	{
//		cout << "\t\t\t【系统提示】文件为空!" << endl;
//	}
//	else
//	{
//		cout << "\t\t\t你要选择更改电影名称:" << endl;
//		cout << "\t\t\t";
//		string n;
//		cin >> n;
//		int index = this->is_exist(n)-1;
//		if (index != -2)
//		{
//				/*cout << "\t\t\t你要选择更改的电影属性：" << endl;
//				cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
//				cout << "\t\t\t┃*********欢迎使用电影修改系统*********┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              1.编号修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              2.名字修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              3.类别修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              4.国家修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              5.主演修改              ┃\t\n";
//				cout << "\t\t\t┃                                      ┃\t\n";
//				cout << "\t\t\t┃              0.上一界面              ┃\t\n";
//				cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
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
//					cout << "\t\t\t请你输入修改后的编号：";
//					int newNo;
//					cin >> newNo;
//					this->m_MoiArray[index]->m_no = newNo;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 2:
//				{
//					cout << "\t\t\t请你输入修改后的名字：";
//					int newName;
//					cin >> newName;
//					this->m_MoiArray[index]->m_name = newName;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 3:
//				{
//					cout << "\t\t\t请你输入修改后的类别：";
//					int newType;
//					cin >> newType;
//					this->m_MoiArray[index]->m_types = newType;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 4:
//				{
//					cout << "\t\t\t请你输入修改后的国家：";
//					int newNation;
//					cin >> newNation;
//					this->m_MoiArray[index]->m_nation = newNation;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//					break;
//				}
//				case 5:
//				{
//					cout << "\t\t\t请你输入修改后的主演：";
//					int newActor;
//					cin >> newActor;
//					this->m_MoiArray[index]->m_actor = newActor;
//					this->m_save();
//					cout << "\t\t\t【系统提示】信息更改成功!" << endl;
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
//			cout << "\t\t\t请输入更改后的编号" << endl;
//			cout << "\t\t\t";
//			cin >> no;
//			cout << "\t\t\t请输入更改后的电影名称" << endl;
//			cout << "\t\t\t";
//			cin >> name;
//			cout << "\t\t\t请输入更改后的类型" << endl;
//			cout << "\t\t\t";
//			cin >> types;
//			cout << "\t\t\t请输入更改后的国籍" << endl;
//			cout << "\t\t\t";
//			cin >> nation;
//			cout << "\t\t\t请输入更改后的主演" << endl;
//			cout << "\t\t\t";
//			cin >> actor;
//			cout << "\t\t\t请输入更改后的时长" << endl;
//			cout << "\t\t\t";
//			cin >> data;
//			this->m_MoiArray[index]->m_no = no;
//			this->m_MoiArray[index]->m_name = name;
//			this->m_MoiArray[index]->m_types = types;
//			this->m_MoiArray[index]->m_nation = nation;
//			this->m_MoiArray[index]->m_actor = actor;
//			this->m_MoiArray[index]->m_data = data;
//			this->m_save();//更新数据后，保存到文件中
//			cout << "\t\t\t【系统提示】信息更改成功!" << endl;
//		}
//		else
//		{
//			cout << "\t\t\t【系统提示】修改失败，未找到该电影！" << endl;
//		}
//	}
//}
mManager::~mManager() {}



