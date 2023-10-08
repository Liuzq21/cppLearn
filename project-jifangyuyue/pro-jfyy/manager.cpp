#include"manager.h"
#include"globalFile.h"
#include<fstream>
#include<algorithm>
using namespace std;

void printTeacher(Teacher& t)
{
	cout << t.m_Empid << "\t\t" << t.m_Name << "\t\t" << t.m_Psw << endl;
}
void printStudent(Student& t)
{
	cout << t.m_id << "\t\t" << t.m_Name << "\t\t" << t.m_Psw << endl;
}

Manager::Manager() {}
Manager::Manager(string name, string psw) 
{ 
	this->m_Name = name; 
	this->m_Psw = psw; 
	this->initVector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) { cout << "文件读取失败" << endl; return; }

	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void Manager::operMenu() 
{
	cout << "\t\t==========管理员===============\n";
	cout << "\t\t|         1. 添加账号        |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         2. 显示账号       |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         3. 查看机房          |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         4. 清空预约        |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         其它：退出         |\n";
	cout << "\t\t|                            |\n";
	cout << "请输入你选择的功能：";
}
void Manager::addPerson() 
{
	cout << "请输入想要添加的类型" << endl;
	cout << "1.老师  2. 学生 " << endl;

	int selector;
	cin >> selector;
	
	string fileName;
	string tip;
	ofstream ofs;
	if (selector == 1)
	{
		fileName = TEACHER_FILE;
		tip = "请输入老师编号 ：";
	}
	else if (selector == 2)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学生学号 ：";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip;
	while(true)
	{
		cin >> id;
		if (!checkRepeat(id, selector)) break;
		else cout << id << "已经存在" << endl;
	}
	
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	if (selector == 1) { vTea.push_back(Teacher(id, name, pwd));}
	else { vStu.push_back(Student(id, name, pwd)); }
	cout << "添加成功"<<endl;
	system("pause");
	system("cls");
	ofs.close();
}

void Manager::showPerson() 
{
	cout << "1.显示老师  2.显示学生" << endl;
	int selector;
	cout << "请输入选择的功能：  ";
	cin >> selector;
	if (selector == 1)
	{
		cout << "编号\t\t" << "姓名\t\t" << "密码\t\t" << endl;
		for_each(vTea.begin(),vTea.end(),printTeacher);
	}
	else if (selector == 2)
	{
		cout << "学号\t\t" << "姓名\t\t" << "密码\t\t" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	system("pause");
	system("cls");
}
void Manager::showComputer() 
{
	cout << "机房信息如下：" << endl;
	cout << "机房编号\t\t" << "机房最大容量" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << it->m_ComId <<"\t\t" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile() 
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) { cout << "文件打开失败" << endl; return; }
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id >> s.m_Name >> s.m_Psw)
	{
		vStu.push_back(s);
	}
	cout << "学生容量为：" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) { cout << "文件打开失败" << endl; return; }

	Teacher t;
	while (ifs >> t.m_Empid >> t.m_Name >> t.m_Psw)
	{
		vTea.push_back(t);
	}
	cout << "教师容量为：" << vTea.size() << endl;
	ifs.close();


}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1) 
	{
		for (vector<Teacher>::iterator i = vTea.begin(); i != vTea.end(); i++)
		{
			if (id == i->m_Empid) return true;
		}
	}
	else if (type == 2) 
	{
		for (vector<Student>::iterator i = vStu.begin(); i != vStu.end(); i++)
		{
			if (id == i->m_id) return true;
		}
	}
	return false;
}

