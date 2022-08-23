#include"pManager.h"
#include"person.h"
#include"manager.h"
#include"user.h"
#include"moive.h"
#include"iomanip"

pManager::pManager() {//初始化属性
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	if (!ifs.is_open()) {
		cout << "\t\t\t【系统提示】文件不存在！" << endl;
		//初始化属性
		this->m_PerNum = 0;
		this->m_PerArray = NULL;
		this->fileisempt= true;
		ifs.close();
		return;
	}

	//2.文件存在，但无数据
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "\t\t\t【系统提示】文件数据为空！" << endl;
		//初始化属性
		this->m_PerNum = 0;
		this->m_PerArray = NULL;
		this->fileisempt = true;
		ifs.close();
		return;
	}

	//3.文件存在，且数据也存在
	int num = this->get_pernum();
	this->m_PerNum=num;//更新人数
	this->fileisempt = false;//更新文件为不空标志
	this->m_PerArray = new User * [this->m_PerNum];//将文件放入数组
	this->init_per();//更新数据
}

void  pManager::show_Menu() {//登录菜单
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃*********欢迎使用电影评分系统*********┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              1.用    户              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              2.管 理 员              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              3.系统帮助              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              0.退出系统              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
}

void  pManager::exit_Menu() {//退出系统
	cout << "\t\t\t【系统提示】欢迎您的下次使用！" << endl;
	system("pause");
	exit(0);
}

void  pManager::user_face() {//用户登录成功界面
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃***********欢迎使用用户系统***********┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              1.搜索电影              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              2.电影评分              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              3.返回界面              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              0.退出系统              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;

}

void  pManager::sel_face() {//用户搜索电影界面
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃*********欢迎使用电影搜索系统*********┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              1.名字搜索              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              2.类型搜索              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              3.地区搜索              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              4.上一界面              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              0.退出系统              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;
}



void  pManager::manage_face() {//管理登录成功界面
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃**********欢迎使用管理员系统**********┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃          1.显示所有用户信息          ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              2.增加用户              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              3.删除用户              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              4.修改用户              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃          5.显示所有电影信息          ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              6.增加电影              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              7.删除电影              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              8.修改电影              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              9.上一界面              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┃              0.退出系统              ┃\t\n";
	cout << "\t\t\t┃                                      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << endl;

}

void  pManager::add_user(){//管理员增加用户
	cout << "\t\t\t【系统提示】请输入增加用户数量" << endl;
	cout << "\t\t\t";
	int addnum = 0;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_PerNum + addnum;
		User** newspace = new User *[newsize];
		if (this->m_PerArray != NULL)
		{
			for (int i = 0; i < this->m_PerNum; i++)
			{
				newspace[i] = this->m_PerArray[i];
			}
		}
		
		for (int i = 0; i < addnum; i++)//添加新的数据
		{
			int no;
			string name;
			string access = "用户";
			cout << "\t\t\t第" << i + 1 << "个用户编号" << endl;
			cout << "\t\t\t";
			while (cin >> no)
			{
				int adjust = 0;
				for (int j = 0; j < this->m_PerNum; j++)
				{
					if (this->m_PerArray[j]->p_no == no)
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
			cout << "\t\t\t第" << i + 1 << "个用户的姓名:" << endl;
			cout<<"\t\t\t";
			cin >> name;
			User* u = NULL;
			u = new User(no, name, access);
			newspace[this->m_PerNum + i] = u;//将创建的用户指针，保存到数组中
		}
		
		delete[] this->m_PerArray;//释放原有的空间
		this->m_PerArray = newspace;//更改新空间的指向
		this->m_PerNum = newsize;//更新用户人数
		cout << "\t\t\t【系统提示】成功添加" << addnum << "个新职工" << endl;
		this->p_save();//保存数据到文件中
	}
	else
	{
		cout << "\t\t\t【系统提示】输入数量无效，添加失败！" << endl;
	}
}

void  pManager::p_save(){//保存数据
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件（将数据写入文件中）

	for (int i = 0; i < this->m_PerNum; i++)
	{
		ofs << this->m_PerArray[i]->p_no << " "
			<< this->m_PerArray[i]->p_name << " "
			<< this->m_PerArray[i]->p_access << endl;
	}
	ofs.close();
}

int  pManager::get_pernum() {//获得人数
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int no;
	string name;
	string access;
	int count = 0;
	while (ifs>>no&&ifs>>name&&ifs>>access)
	{
		count++;
	}
	return count;
}

void  pManager::init_per() {//更新人员信息
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	int no;
	string name;
	string access;
	int index = 0;
	while (ifs >> no && ifs >> name && ifs >> access)
	{
		User* u = NULL;
		u = new User(no, name, access);
		this->m_PerArray[index] = u;//保存在数组中
		index++;
	}
	ifs.close();
}

void  pManager::show_per() {//展示所有人员
	for (int i = 0; i <this->m_PerNum; i++)
	{
		cout << "\t\t\t";
		this->m_PerArray[i]->showinfo();
	}
}
void pManager::table() {//展示所有人表头
	cout << "\t\t\t";
	cout << setw(16) << setiosflags(ios::left) << setfill(' ') << "编号" <<
		setw(16) << setiosflags(ios::left) << setfill(' ') << "姓名" <<
		setw(16) << setiosflags(ios::left) << setfill(' ') << "权限" << endl;
}

int  pManager::is_exist(int no) {//通过编号判断是否存在该用户
	int index = -1;
	for (int i = 0; i < this->m_PerNum; i++)
	{
		if (this->m_PerArray[i]->p_no == no)
		{
			index = i;
			break;
		}
	}
	return index;
}

void  pManager::del_per() {//删除人员
	if (this->fileisempt)
	{
		cout << "\t\t\t【系统提示】文件为空" << endl;
	}
	else
	{
		cout << "\t\t\t【系统提示】请输入你想删除的用户编号:" << endl;
		int no=0;
		cout << "\t\t\t";
		cin >> no;
		int index =this->is_exist(no);//判断需要删除的人员是否存在
		if (index != -1)
		{
			for (int i = index; i < this->m_PerNum-1; i++) {
				this->m_PerArray[i] = this->m_PerArray[i + 1];
			}
			this->m_PerNum--;//更新人员数量
			this->p_save();
			cout << "\t\t\t【系统提示】删除成功！" << endl;
		}
		else
		{
			cout << "\t\t\t【系统提示】删除失败，未找到该用户！" << endl;
		}
	}
}

void  pManager::updata_per() {//修改人员信息
	if (this->fileisempt)
	{
		cout << "\t\t\t【系统提示】文件为空！" << endl;
	}
	else
	{
		cout << "\t\t\t【系统提示】你要选择更改用户的编号:" << endl;
		cout << "\t\t\t";
		int no = 0;
		cin >> no;
		int index = this->is_exist(no);
		if (index != -1)
		{
			int newNo;
			string name;
			string access;
			cout << "\t\t\t【系统提示】请输入更改后的编号：" << endl;
			cout << "\t\t\t";
			cin >> newNo;
			cout << "\t\t\t【系统提示】请输入更改后的名字：" << endl;
			cout << "\t\t\t";
			cin >> name;
			cout << "\t\t\t【系统提示】请输入更改的权限：" << endl;
			cout << "\t\t\t";
			cin >> access;
			this->m_PerArray[index]->p_name = name;
			this->m_PerArray[index]->p_access = access;

			this->p_save();
			cout << "\t\t\t【系统提示】信息更改成功!" << endl;
		}
		else
		{
			cout << "\t\t\t【系统提示】修改失败，未找到该用户!" << endl;
		}
	}
}

void  pManager::user_log() {//用户登录
	string name;
	while (true)
	{
		cout << "\t\t\t【系统提示】请输入你要登录的名字" << endl;
		cout << "\t\t\t";
		cin >> name;
		for (int i = 0; i < this->m_PerNum; i++)
		{
			while (this->m_PerArray[i]->p_name == name && this->m_PerArray[i]->p_access == "用户")
			{
				cout << "\t\t\t【系统提示】登录成功，欢迎你" + name + "!!!" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
		cout << "\t\t\t【系统提示】你输入的信息有误，请重新输入!" << endl;
	}
}

void  pManager::manager_log() {//管理员登录
	int password = 0;
	string name;
	while (true)
	{
		cout << "\t\t\t【系统提示】请输入你要登录的名字:" << endl;
		cout << "\t\t\t";
		cin >> name;
		cout << "\t\t\t【系统提示】请输入你要登录的密码:" << endl;
		cout << "\t\t\t";
		cin >> password;
		for (int i = 0; i < this->m_PerNum; i++)
		{
			while (this->m_PerArray[i]->p_name == name &&
				this->m_PerArray[i]->p_access == "管理")
			{
				if (password==123456)
				{


					cout << "\t\t\t【系统提示】登录成功，欢迎你" + name + "!!!" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
		}
		cout << "\t\t\t【系统提示】你输入的信息有误，请重新输入!" << endl;
	
	}
}

pManager::~pManager() {//释放堆区数据

}