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
	if (!ifs.is_open()) { cout << "�ļ���ȡʧ��" << endl; return; }


	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void Student::operMenu() 
{
	cout << "\t\t==========ѧ��"<<this->m_Name<<"��¼============== = \n";
	cout << "\t\t|         1. ����ԤԼ        |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         2. �鿴����ԤԼ       |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         3. �鿴����ԤԼ          |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         4. ȡ��ԤԼ       |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         �������˳�         |\n";
	cout << "\t\t|                            |\n";
	cout << "��������ѡ��Ĺ��ܣ�";
}
void Student::applyOrder() 
{
	cout << "��������ʱ��Ϊ��һ�����壬����������ҪԤԼ����������" << endl;
	cout << "1. ��һ 2. �ܶ� 3. ���� 4. ���� 5. ����" << endl;
	cout << "����������ҪԤԼ����������:";
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
		cout << "�����������������:";
	}

	cout << "��������ҪԤԼ��ʱ���\n 1.���� 2.���� ��";
	while (true)
	{
		cin >> interval;
		if (interval ==1 || interval == 2)
		{
			break;
		}
		cout << "�����������������:";
	}
	cout << "��ѡ�����\n 1�Ż���������" << vCom[0].m_MaxNum << "\n2�Ż���������" << vCom[1].m_MaxNum << "\n3�Ż���������" << vCom[2].m_MaxNum << endl;
	while (true)
	{
		cin >> room;
		if (room <= 3 && room >= 1)
		{
			break;
		}
		cout << "�����������������:";
	}

	cout << "ԤԼ�ɹ��������" << endl;
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
	if (of.m_size == 0) { cout << "û��ԤԼ��¼" << endl; return; }

	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["stuID"].c_str()) == this->m_id)
		{
			cout << "ԤԼ�ţ�" << i;
			cout << "ԤԼ���ڣ�  ��" << of.m_orderData[i]["date"];
			cout << "ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.m_orderData[i]["roomID"];
			cout << "ԤԼ״̬�� " << of.m_orderData[i]["status"]<<endl;
		}
	}
	system("pause");
	system("cls");
}
void Student::showAllOrder() 
{
	OrderFile of;
	if (of.m_size == 0) { cout << "û��ԤԼ��¼" << endl; return; }

	for (int i = 0; i < of.m_size; i++)
	{
		cout << "ԤԼ�ˣ�" << of.m_orderData[i]["stuName"];
		cout << "ԤԼ���ڣ�  ��" << of.m_orderData[i]["date"];
		cout << "ԤԼʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "������" << of.m_orderData[i]["roomID"];
		cout << "ԤԼ״̬�� " << of.m_orderData[i]["status"] << endl;
		
	}
	system("pause");
	system("cls");
}
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_size == 0) { return; }

	this->showMyOrder();

	cout << "ѡ����Ҫȡ����ԤԼ��:" << endl;
	int orderid;
	cin >> orderid;
	if (atoi(of.m_orderData[orderid]["stuID"].c_str()) == this->m_id)
	{
		of.m_orderData[orderid]["status"] = "0";
		cout << "ȡ���ɹ�" << endl;
	}
	else { cout << "��Ȩ�޸�" << endl; }

	of.updateOrder();
}