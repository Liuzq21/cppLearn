/*
	机房预约系统
*/
#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

void managerMenu(Identity* &manager)
{
	while (true)
	{
		// 调用管理员子菜单
		manager->operMenu();
		// 将父类指针 转为 子类 调用其它接口
		Manager* man = (Manager*)manager;
		int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			// 添加账号
			man->addPerson();
			break;
		case 2:
			// 查看账号
			man->showPerson();
			break;
		case 3:
			// 查看机房
			man->showComputer();
			break;
		case 4:
			// 清空预约
			man->cleanFile();
			break;

		default:
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		// 调用学生子菜单
		student->operMenu();
		// 将父类指针 转为 子类 调用其它接口
		Student* man = (Student*)student;
		int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			// 申请预约
			man->applyOrder();
			break;
		case 2:
			// 查看自身预约
			man->showMyOrder();
			break;
		case 3:
			// 查看所有预约
			man->showAllOrder();
			break;
		case 4:
			// 取消预约
			man->cancelOrder();
			break;

		default:
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}

void loginIn(string fileName, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) { cout << "文件不存在"; ifs.close(); return; }

	int id;
	string name;
	string pwd;
	if (type == 1){// student
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2) { // teacher
		cout << "请输入你的职工号：";
		cin >> id;
	}
	cout << "请输入你的用户名：";
	cin >> name;
	cout << "请输入你的密码：";
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs>>fId && ifs>>fName && ifs>>fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				// 进入学生的子菜单

				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		int fEmpId;
		string fName;
		string fPwd;
		while (ifs >> fEmpId && ifs >> fName && ifs >> fPwd)
		{
			if (fEmpId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(fEmpId, name, pwd);
				// 进入老师的子菜单


				return;
			}
		}

	}
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// 进入管理员的子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败"; 
	system("pause");
	return; 
}
int main()
{
	int choice;
	
	while (true)
	{
		cout << "=============== 欢迎来到传智 播客机房预约系统============" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t=============================\n";
		cout << "\t\t|         1. 学生代表        |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2. 老    师        |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3. 管理员          |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0. 退出系统        |\n";
		cout << "\t\t|                            |\n";
		cout << "请输入你的选择：";
		cin >> choice;
		switch (choice)
		{
		case 1: // 学生身份
			loginIn(STUDENT_FILE, 1);
			break;
		case 2: // 老师身份
			loginIn(TEACHER_FILE, 2);
			break;
		case 3: // 管理员
			loginIn(ADMIN_FILE, 3);
			
			break;
		case 0: // 退出系统
			cout << "欢迎下次使用"<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入\n";
			system("cls");
			break;
		}
	}
	return 0;
}