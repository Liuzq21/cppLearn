#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
    函数对象、仿函数 本质上是一个类
    3个特点
    返回bool类型的仿函数叫谓词
*/

class MyAdd
{
    public:
    int cnt=0;
    int operator() (int v1, int v2){   // 重载()
        cnt++; // 1、函数对象有自己的状态
        return v1+v2;
    }
};
void test()
{
    MyAdd myAdd;
    myAdd(10,10);   // 2、函数对象在使用的时候，可以像普通函数一样调用
}
void myPrint(MyAdd &myAdd, string s){}  // 3、函数对象可以作为参数传递

// 一元谓词operator() 接受一个参数。二元谓词见set map 的MyCompare
class GreatFive
{
    public:
    bool operator() (int v)
    {
        return v>5;
    }
};
void test02()
{
    vector<int> v;
    vector<int>::iterator it = find_if(v.begin(),v.end(),GreatFive()); //  GreatFive() 是匿名函数对象
}

// 内建的函数对象 引入头文件 #include<functional>  3类：算术、关系、逻辑
/*
-------------算术-------------------
    template<class T> T plus<T>   
    template<class T> T minus<T>
    template<class T> T multiplies<T>
    template<class T> T divides<T>
    template<class T> T modulus<T>   // 取模
    template<class T> T negate<T>    // 取反
-------------关系-------------------
    template<class T> bool equal to<T>         =
    template<class T> bool not equal to<T>     ！=
    template<class T> bool greater<T>          >
    template<class T> bool greater equal<T>    >=
    template<class T> bool less<T>             <          默认
    template<class T> bool less equal<T>       <=
-------------逻辑-------------------实际开发基本上用不到
    template<class T> bool logical and<T>
    template<class T> bool logical or<T>
    template<class T> bool logical not<T>
*/
#include<functional>
// 一元仿函数
void testa()
{
    negate<int>n;
    n(50);
}
// 二元仿函数
void testb()
{
    plus<int>p;
    p(1,2);
}
// 关系仿函数
void testc()
{
    vector<int>v;
    sort(v.begin(),v.end(), greater<int>());
}