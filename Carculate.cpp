#include<iostream>
using namespace std;
// 多态例子：计算器类，多态

class AbstractCarculate
{
public:
    int m_num1;
    int m_num2;
    virtual int getResult(){return 0;};
};

class AddCarculater : public AbstractCarculate
{
    int getResult() {return m_num1 + m_num2;}
};
class SubCarculater : public AbstractCarculate
{
    int getResult() {return m_num1 - m_num2;}
};
int main()
{
    AbstractCarculate *add = new AddCarculater;  // 用父类指针指向子类对象
    add->m_num1 = 10;
    add->m_num2 = 20;
    cout<<add->getResult();
    delete add; // 这种情况，如果类中有堆区数据需要维护，父类的析构函数需要写成虚析构
    AbstractCarculate *sub = new SubCarculater;
    delete sub;
}
// 多态例子：制作饮品
class AbstrackDrinking
{
public:
    virtual void Boil() =0;
    virtual void Brew() =0;
    virtual void Pour() =0;
    virtual void Put() =0;
    void makeDrink(){Boil();Brew();Pour();Put();return;}
};
class Coffee : public AbstrackDrinking
{
    virtual void Boil(){cout<<"coffee boil"<<endl;}
    virtual void Brew(){cout<<"brew coffee"<<endl;}
    virtual void Pour(){cout<<"pour in coffee cup"<<endl;}
    virtual void Put(){cout<<"put coffee"<<endl;}
};
void doMakeDrink(AbstrackDrinking* ad)
{
    ad->makeDrink();
    delete ad;
}// doMakeDrink(new Coffee);
