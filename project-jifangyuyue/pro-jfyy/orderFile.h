#pragma once
#include<iostream>
using namespace std;
#include "globalFile.h"
#include<map>

class OrderFile
{
public:
	int m_size;
	map<int, map<string, string>> m_orderData;

	OrderFile();
	void updateOrder();

};