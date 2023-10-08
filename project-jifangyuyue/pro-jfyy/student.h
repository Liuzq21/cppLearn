#pragma once
#include<iostream>
#include<vector>
#include"identity.h"
#include "computerRoom.h"
using namespace std;

class Student : public Identity
{
public:
	int m_id;
	vector<ComputerRoom> vCom;

	Student();
	Student(int id, string name, string psw);

	virtual void operMenu();
	void applyOrder();
	void showMyOrder();
	void showAllOrder();
	void cancelOrder();

	
};
