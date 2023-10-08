#include<iostream>
using namespace std;
#include"orderFile.h"
#include<fstream>
#include"globalFile.h"


OrderFile::OrderFile() 
{
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open()) { cout << "文件打开失败" << endl; return; }
	this->m_size = 1;
	string date;
	string stuID;
	string stuName;
	string interval;
	string roomID;
	string status;
	int pos;
	map<string, string> m;
	while (ifs >> date >> stuID >> stuName >> interval >> roomID >> status)
	{
		 pos = date.find(":");
		 if (pos != -1)
		 {
			 m.insert(make_pair(date.substr(0, pos), date.substr(pos + 1, date.size() - pos)));
		 }

		 pos = stuID.find(":");
		 if (pos != -1)
		 {
			 m.insert(make_pair(stuID.substr(0, pos), stuID.substr(pos + 1, stuID.size() - pos)));
		 }

		 pos = stuName.find(":");
		 if (pos != -1)
		 {
			 m.insert(make_pair(stuName.substr(0, pos), stuName.substr(pos + 1, stuName.size() - pos)));
		 }
		 pos = interval.find(":");
		 if (pos != -1)
		 {
			 m.insert(make_pair(interval.substr(0, pos), interval.substr(pos + 1, interval.size() - pos)));
		 }
		 pos = roomID.find(":");
		 if (pos != -1)
		 {
			 m.insert(make_pair(roomID.substr(0, pos), roomID.substr(pos + 1, roomID.size() - pos)));
		 }
		 pos = status.find(":");
		 if (pos != -1)
		 {
			 m.insert(make_pair(status.substr(0, pos), status.substr(pos + 1, status.size() - pos)));
		 }
		 m_orderData.insert(make_pair(m_size, m));
		 m_size++;
	}

}

void OrderFile::updateOrder() 
{
	if (this->m_size == 0) { return; }

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "stuID:" << this->m_orderData[i]["stuID"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "roomID:" << this->m_orderData[i]["roomID"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}