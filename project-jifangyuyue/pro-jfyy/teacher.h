#pragma once
#include<iostream>
#include"identity.h"

using namespace std;



class Teacher : public Identity
{
public:
	int m_Empid;
	Teacher();
	Teacher(int empid, string name, string psw);

	virtual void operMenu();
	void validOrder();
	void showAllOrder();
};