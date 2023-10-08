#pragma once
#include<iostream>
#include<vector>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;


class Manager : public Identity
{
public :
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<ComputerRoom> vCom;

	Manager();
	Manager(string name, string psw);
	virtual void operMenu();
	void addPerson();
	void showPerson();
	void showComputer();
	void cleanFile();

	void initVector();
	bool checkRepeat(int id, int type);
};