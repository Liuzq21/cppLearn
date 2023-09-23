#include<iostream>
#include<string>
using namespace std;

struct Student 
{
    string name;
    int age;
    float grade;
}s2; // 顺便创建一个结构体变量

struct Teacher
{
    int id;
    string name;
    Student student;
}t1;


int main(){
    // 结构体定义
    Student s1 = {"lzq", 22, 100};
    // 结构体数组
    Student s2[4] = 
    {
        {"a" , 12 , 2},
        {"b" , 12 , 2}
    };
    cout<< s2[0].age<<endl;
    // 结构体指针
    Student *p = &s1;
    cout<< p->age <<endl;

    // 结构体嵌套
    t1.student.age = 10;

    return 0;
}