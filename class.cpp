/*
    类和对象
    * 深拷贝、浅拷贝：如果属性有在堆区操作，需要在拷贝构造里进行深拷贝，在析构函数中释放
    * 成员变量和成员函数是分开存储的，函数仅存一份，使用this指针来区分是哪个实例调用的函数。
    * 友元，让类外一些函数或类访问私有属性【全局函数做友元、类做友元、成员函数做友元】
*/
#include<iostream>

using namespace std;

class Circle{  // class 与 struct 的区别：class 默认全是事private，struct 是public。
private: // 类内可以，类外不可以。儿子不可以访问父亲。
// 属性私有化，设置接口，做到读写可控
public: // 类内、类外可以访问
    static int m_s; // 静态成员变量：所有成员共享，编译阶段分配内存，类内声明类外初始化
    int m_r;
    int m_b,m_c;
    int *m_a; // 堆内开辟属性
    Circle(int r=5){}
    Circle(int r,int a){ // 有参构造 无参构造 普通构造 
        m_r = r;
        m_a = new int(a);
        cout<<"构造函数，可重载，可有参数"<<endl;}
    // 常用在值传递，返回，初始化
    Circle(const Circle &c){ // 深拷贝
        this->m_r = c.m_r;
        m_a = new int (*(c.m_a));
    } // 拷贝构造. 不可用于初始化匿名对象 Circle(c2) == Circle c2 会报错重定义

    ~Circle(){  // 将堆区的数据释放
        if(m_a != NULL) {delete m_a;}
        cout<<"析构函数，不可重载，不可有参数, 类销毁前执行一次";}
    

    // 初始化列表
    Circle(int b, int c): m_b(b),m_c(c){}

    double carculate() const // 使用常函数，不能再里面修改成员变量，只能使用常变量
    { 
        return 2 * 3.14 * m_r;
    }
    static void show(){cout<<m_s;} // 静态成员函数只能访问静态变量 

protected: // 类内可以，类外不可以。儿子可以访问父亲的此处
};
int Circle::m_s = 100;  // 静态成员变量初始化

class Friend
{
    friend void godGay(Friend &f);// 友元全局函数访问私有属性
    friend class Gay;// 友元类访问私有属性
    friend void Gay::visit();// 成员函数做友元
public:
    string m_sittingroom;
    Friend();
private:
    string m_badroom;

};
Friend::Friend()  // 类外实现成员函数
{
    m_sittingroom = "aaa";
    m_badroom = "bbb";
}

// 友元全局函数访问私有属性
void godGay(Friend &f)
{
    cout<<f.m_badroom;
}
// 友元类访问私有属性
class Gay
{
public:
    Friend f;
    void visit()
    {
        cout<<f.m_badroom<<endl;
    }
};


int main(){
    // 定义方法：
    Circle crl1;
    Circle c(4);
    Circle c2 = Circle(c);
    Circle c3 = c2;
    crl1.m_r = 10;
    cout<<crl1.carculate()<<endl;

    // 静态成员: 可直接类名访问
    cout<<Circle::m_s<<endl;
    Circle::show();
    return 1;
}