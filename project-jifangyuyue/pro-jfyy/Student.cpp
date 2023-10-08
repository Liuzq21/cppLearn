#include<iostream>
#include<fstream>
#include"student.h"
#include "globalFile.h"
#include "computerRoom.h"
#include"orderFile.h"
using namespace std;

Student::Student()
{}
Student::Student(int id, string name, string psw) 
{
	this->m_id = id;
	this->m_Name = name;
	this->m_Psw = psw;

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

void Student::operMenu() 
{
	cout << "\t\t==========学生"<<this->m_Name<<"登录============== = \n";
	cout << "\t\t|         1. 申请预约        |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         2. 查看自身预约       |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         3. 查看所有预约          |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         4. 取消预约       |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         其它：退出         |\n";
	cout << "\t\t|                            |\n";
	cout << "请输入你选择的功能：";
}
void Student::applyOrder() 
{
	cout << "机房开发时间为周一至周五，请输入你需要预约的日期数字" << endl;
	cout << "1. 周一 2. 周二 3. 周三 4. 周四 5. 周五" << endl;
	cout << "请输入你需要预约的日期数字:";
	int day=0;
	int interval;
	int room;
	while (true)
	{
		cin >> day;
		if (day <=5 && day >=1)
		{
			break;
		}
		cout << "输入错误，请重新输入:";
	}

	cout << "请输入需要预约的时间段\n 1.上午 2.下午 ：";
	while (true)
	{
		cin >> interval;
		if (interval ==1 || interval == 2)
		{
			break;
		}
		cout << "输入错误，请重新输入:";
	}
	cout << "请选择机房\n 1号机房容量：" << vCom[0].m_MaxNum << "\n2号机房容量：" << vCom[1].m_MaxNum << "\n3号机房容量：" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room <= 3 && room >= 1)
		{
			break;
		}
		cout << "输入错误，请重新输入:";
	}

	cout << "预约成功！审核中" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << day << " ";
	ofs << "stuID:" << m_id << " ";
	ofs << "stuName:" << m_Name << " ";
	ofs << "interval:" << interval << " ";
	ofs << "roomID:" << room << " ";
	ofs << "status:" << "1" <<" " << endl;
	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyOrder() 
{
	OrderFile of;
	if (of.m_size == 0) { cout << "没有预约记录" << endl; return; }

	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_id)
		{
			cout << "预约号：" << i;
			cout << "预约日期：  周" << of.m_orderData[i]["date"];
			cout << "预约时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房：" << of.m_orderData[i]["roomID"];
			cout << "预约状态： " << of.m_orderData[i]["status"]<<endl;
		}
	}
	system("pause");
	system("cls");
}
void Student::showAllOrder() 
{
	OrderFile of;
	if (of.m_size == 0) { cout << "没有预约记录" << endl; return; }

	for (int i = 0; i < of.m_size; i++)
	{
		cout << "预约人：" << of.m_orderData[i]["stuName"];
		cout << "预约日期：  周" << of.m_orderData[i]["date"];
		cout << "预约时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "机房：" << of.m_orderData[i]["roomID"];
		cout << "预约状态： " << of.m_orderData[i]["status"] << endl;
		
	}
	system("pause");
	system("cls");
}
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0) { return; }

	this->showMyOrder();

	cout << "选择需要取消的预约号:" << endl;
	int orderid;
	cin >> orderid;
	if (atoi(of.m_orderData[orderid]["stuID"].c_str()) == this->m_id)
	{
		of.m_orderData[orderid]["status"] = "0";
		cout << "取消成功" << endl;
	}
	else { cout << "无权修改" << endl; }

	of.updateOrder();
}