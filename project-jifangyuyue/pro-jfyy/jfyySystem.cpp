/*
	����ԤԼϵͳ
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
		// ���ù���Ա�Ӳ˵�
		manager->operMenu();
		// ������ָ�� תΪ ���� ���������ӿ�
		Manager* man = (Manager*)manager;
		int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			// ����˺�
			man->addPerson();
			break;
		case 2:
			// �鿴�˺�
			man->showPerson();
			break;
		case 3:
			// �鿴����
			man->showComputer();
			break;
		case 4:
			// ���ԤԼ
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
		// ����ѧ���Ӳ˵�
		student->operMenu();
		// ������ָ�� תΪ ���� ���������ӿ�
		Student* man = (Student*)student;
		int selector;
		cin >> selector;
		switch (selector)
		{
		case 1:
			// ����ԤԼ
			man->applyOrder();
			break;
		case 2:
			// �鿴����ԤԼ
			man->showMyOrder();
			break;
		case 3:
			// �鿴����ԤԼ
			man->showAllOrder();
			break;
		case 4:
			// ȡ��ԤԼ
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
	if (!ifs.is_open()) { cout << "�ļ�������"; ifs.close(); return; }

	int id;
	string name;
	string pwd;
	if (type == 1){// student
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2) { // teacher
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	cout << "����������û�����";
	cin >> name;
	cout << "������������룺";
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
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				// ����ѧ�����Ӳ˵�

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
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(fEmpId, name, pwd);
				// ������ʦ���Ӳ˵�


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
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				// �������Ա���Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��"; 
	system("pause");
	return; 
}
int main()
{
	int choice;
	
	while (true)
	{
		cout << "=============== ��ӭ�������� ���ͻ���ԤԼϵͳ============" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t=============================\n";
		cout << "\t\t|         1. ѧ������        |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         2. ��    ʦ        |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         3. ����Ա          |\n";
		cout << "\t\t|                            |\n";
		cout << "\t\t|         0. �˳�ϵͳ        |\n";
		cout << "\t\t|                            |\n";
		cout << "���������ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 1: // ѧ�����
			loginIn(STUDENT_FILE, 1);
			break;
		case 2: // ��ʦ���
			loginIn(TEACHER_FILE, 2);
			break;
		case 3: // ����Ա
			loginIn(ADMIN_FILE, 3);
			
			break;
		case 0: // �˳�ϵͳ
			cout << "��ӭ�´�ʹ��"<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������\n";
			system("cls");
			break;
		}
	}
	return 0;
}