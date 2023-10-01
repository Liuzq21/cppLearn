/*
    泛型编程 函数模板 类模板
    普通函数和模板函数的区别：优先调普通函数。普通函数可以发生隐式类型转换，模板函数在指定模板类型时才可以发生。如果有更好的匹配，则会调用函数模板
    建议用显示指定使用模板
*/
#include<iostream>
using namespace std;

// 一、 函数模板
template<typename T> // typename 可以替换为 class。 函数模板可重载
void mySwap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
class Person{public: int a; string b;};

template<typename T>
bool myCompare(T &a, T &b){ a=b;return true;}

template<> bool myCompare(Person &p1, Person &p2){ // 重载以实现Person版本的myCompare函数
    if(p1.a == p2.a && p1.b == p2.b) return true;
    else return false;
}

int test01()
{
    int a=1;
    int b=3;
    mySwap(a,b);
    mySwap<int>(a,b);  // 指定 T 的类型
    mySwap<>(a,b);  // 空模板参数列表，可以强制调用模板，而不是普通函数
    return 0;
}

// 二、类模板

    // 类模板与友元 类外实现全局函数
template<class NameType, class AgeType> class Person;
template<class NameType, class AgeType>
void showPerson(Person<NameType,AgeType> p ){}

template<class NameType, class AgeType = int>  // 类模板可以有默认参数
class Person
{
    friend void showPerson<>(Person<NameType,AgeType> p ); // 加了友元，变为全局函数，需要加一个空模板参数列表
    public:
    NameType m_name;
    AgeType m_age;
    void show();
};// Person<string, int> p1; 
void test02()
{
    Person<string, int> p1;  // 类模板没有自动类型推导
}
    // 类模板的对象作为函数参数--3种方法
void print01(Person<string, int> &p){cout<<"s"<<endl;return;}   // 常用
template<class T1, class T2>
void print02(Person<T1,T2> &p){cout<<"s"<<endl;return;}
template<class T>
void print03(T &p){cout<<"s"<<endl;}

    // 类模板与继承
class Child : public Person<string>{};
template<class NameType>
class Child2 : public Person<NameType>{};
    // 类模板成员函数的类外实现
template<class NameType, class AgeType>
void Person<NameType,AgeType>::show() {cout<<"类外实现"<<endl;}
