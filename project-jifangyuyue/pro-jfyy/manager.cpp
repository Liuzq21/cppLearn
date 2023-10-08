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
	if (!ifs.is_open()) { cout << "�ļ���ȡʧ��" << endl; return; }

	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

void Manager::operMenu() 
{
	cout << "\t\t==========����Ա===============\n";
	cout << "\t\t|         1. ����˺�        |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         2. ��ʾ�˺�       |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         3. �鿴����          |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         4. ���ԤԼ        |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|         �������˳�         |\n";
	cout << "\t\t|                            |\n";
	cout << "��������ѡ��Ĺ��ܣ�";
}
void Manager::addPerson() 
{
	cout << "��������Ҫ��ӵ�����" << endl;
	cout << "1.��ʦ  2. ѧ�� " << endl;

	int selector;
	cin >> selector;
	
	string fileName;
	string tip;
	ofstream ofs;
	if (selector == 1)
	{
		fileName = TEACHER_FILE;
		tip = "��������ʦ��� ��";
	}
	else if (selector == 2)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ��ѧ�� ��";
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
		else cout << id << "�Ѿ�����" << endl;
	}
	
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	if (selector == 1) { vTea.push_back(Teacher(id, name, pwd));}
	else { vStu.push_back(Student(id, name, pwd)); }
	cout << "��ӳɹ�"<<endl;
	system("pause");
	system("cls");
	ofs.close();
}

void Manager::showPerson() 
{
	cout << "1.��ʾ��ʦ  2.��ʾѧ��" << endl;
	int selector;
	cout << "������ѡ��Ĺ��ܣ�  ";
	cin >> selector;
	if (selector == 1)
	{
		cout << "���\t\t" << "����\t\t" << "����\t\t" << endl;
		for_each(vTea.begin(),vTea.end(),printTeacher);
	}
	else if (selector == 2)
	{
		cout << "ѧ��\t\t" << "����\t\t" << "����\t\t" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	system("pause");
	system("cls");
}
void Manager::showComputer() 
{
	cout << "������Ϣ���£�" << endl;
	cout << "�������\t\t" << "�����������" << endl;
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
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) { cout << "�ļ���ʧ��" << endl; return; }
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id >> s.m_Name >> s.m_Psw)
	{
		vStu.push_back(s);
	}
	cout << "ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) { cout << "�ļ���ʧ��" << endl; return; }

	Teacher t;
	while (ifs >> t.m_Empid >> t.m_Name >> t.m_Psw)
	{
		vTea.push_back(t);
	}
	cout << "��ʦ����Ϊ��" << vTea.size() << endl;
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

