// cpp核心编程

#include<iostream>
using namespace std;

// 一、四个区
/*
    c++ 程序执行，将内存分为四个区域
    * 代码区 ： 共享，只读。
    * 全局区 ： 全局变量，常量，静态变量
    * 栈区 ： 编译器自动分配回收；函数参数值，局部变量。故不要返回局部变量的地址
    * 堆区 ： 程序员分配，利用new可以分配堆区内存 eg  int *p = new int（10）；释放用delete p ； delete[] arr;
*/
// 二、引用
/*
    引用：给变量起别名. 数据类型 &别名 = 原名
    1、必须初始化
    2、初始化后不可改变
    3、如果函数的返回是个引用，则这个函数可以作为左值
    4、注意引用的变量的生命周期
    其本质是一个指针常量（值可改，方向不可改）
*/
void yinyong(){
    int a =10;
    int &b = a;
    b = 100;
    cout<<a<<endl;
}
void swap(int &a, int &b){ // 引用传递，简化指针修改实参
    int temp = a;
    a = b;
    b = temp;
}
int& test01(const int &num){  // 用const修饰，防止误改
    static int a =10;  // 全局区
    return a; // 返回a的引用
} // test01() = 100; 如果函数的返回是个引用，则这个函数可以作为左值

// 三、函数重载
/*
    函数高级
    * 默认参数: 如果某个位置有默认值，则其右边都得有默认值
    * 占位参数：也可以有默认值
    * 函数重载：函数名相同，函数参数个数 | 类型不同 | 顺序不同 。 提高复用性
*/
int func(int a, int b=10, int c=30); // func(10) = 10+20+30; func(10,10) = 10+10+30;
int func(int a, int b, int c){  // 定义时有默认参数，则实现时不可有默认参数 
    return a+b+c;
}
// int func02(int = 10); 
// int func(double a, double b);
// int func(int a, double b);
// void func(int &a);  调用 func(a);
// void func(const int &a); 调用 func(10);

// 四、运算符重载
class Person
{
    friend ostream& operator<< (ostream& cout,Person &p);
public:
    int age;
    // Person operator+ (Person a) // 通过成员函数重载 p1.operator+(p2) 等同于 p1 + p2
    // {
    //     Person temp;
    //     temp.age = a.age+this->age;
    //     return temp;
    // }// 调用 Person p3 = p1+p2;

    // 重载前置++
    Person& operator++ () // 返回值一定要是引用形式，不然 ++(++a) 结果会错。返回引用是一直对一个数据操作
    {
        ++age;
        return *this;
    }
    // 重载后置++ 用int占位参数表示
    Person operator++ (int)  // 返回值一定要是值的形式。 
    {
        Person temp = *this;
        this->age++;
        return temp;
    }
    // 重载赋值= 注意浅拷贝
    Person& operator= (Person &p)
    {
        // 如果m_Age是指针类型, 深拷贝
        // if (m_Age != NULL){delete m_Age;m_Age =NULL;} 
        // m_Age = new int(*p.m_Age);
        this->age = p.age;
        return *this;
    }

    // 重载函数调用()。也称为仿函数
    void operator()(string& s)
    {
        cout<<s<<endl;
    } // Person()("hello world"); 
};
Person operator+ (Person& p1, Person& p2)
{
    Person temp;
    temp.age = p1.age +p2.age;
    return temp;   
}
    // << 只能全局函数重载
ostream& operator<< (ostream& cout,Person &p)
{
    cout<<"age:"<<p.age;
    return cout;
}; // cout<< p <<endl;

    // 重载关系运算符 < > == !=
bool operator==(Person& p1, Person& p2)
{
    if (p1.age == p2.age) return true;
    else return false;
}

// 五、继承，父类private不可继承
    // 继承方式：【public private protected】public 照搬父类能访问属性权限。private和protected 修改父类能访问的属性权限为 private和protected权限
    // 不管哪种继承方式，子类其实都继承了父类的属性，在内存中也有，但private是访问不到而已。
    // 菱形继承问题：B、C继承A。D继承B、C。二义性问题（加作用域解决），属性重复问题（利用虚继承解决class B\C virtual public A）
class Father
{
public:
    int m_same1;
    void same1(){cout<<m_same1;}
};
class Child : public Father  // 继承语法：【class 子类名 : 继承方式 父类名, 继承方式 父类名...】
{
public:
    int m_dif1;
    void dif1(){cout<<m_dif1;}
    int m_same1; // 同名成员
};
    // Child().m_same1;  访问子类同名成员
    // Child().::m_same1; 访问父类同名成员
    // 调用成员函数类似，父类要加作用域

// 六、多态【静态多态（即重载等，编译阶段确定地址）、动态多态（派生类、虚函数，运行时确定地址）】

