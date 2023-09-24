#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Person
{
public:
    int age;
    char name[64];
};

int main()
{
    //文件打开方式 ：in out ate（文件尾） app（追加） trunc（文件存在先删除再创建） binary

    // 读文件---字节流
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(! ifs.is_open()) {cout<<"open fail!"<<endl; return 0;}

    // 四种方法读
    char buf[1024] ={0}; 
    // while(ifs >>buf){cout<<buf<<endl;}
    // while(ifs.getline(buf, sizeof(buf))){cout<<buf<<endl;}
    string buf;
    // while (getline(ifs,buf)){cout<<buf<<endl;}
    char c;
    // while (( c = ifs.get()) != EOF) {cout<<c<<endl;}
    ifs.close();

    // 写文件---字节流
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<"name:lzq"<<endl;
    ofs.close();
    return 1;

    // 读文件---二进制
    ifstream ifs("person",ios::in | ios::binary);
    if(! ifs.is_open()) {cout<<"open fail!"<<endl; return 0;}

    Person p;
    ifs.read((char *)&p,sizeof(Person));
    ifs.close();

    // 写文件---二进制 写类
    // ofstream ofs;
    // ofs.open("person",ios::out | ios::binary);
    ofstream ofs("person",ios::out | ios::binary);

    Person p = {23,"lzq"};
    ofs.write((const char*)&p, sizeof(Person));
    ofs.close();
}