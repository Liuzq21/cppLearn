#include<set>
using namespace std;
/*
    集合，插入时就自动排序好了，底层是二叉树
    set不允许有重复的，multiset允许
    构造赋值大小交换 与其他类似
    插入删除  pari<set<int>::iterator, bool>=insert(elem) erase(elem) erase(pos) erase(beg,end)
    查找  find(key) 存在返回元素的迭代器。不存在则返回set。end()
    统计 int count(key)
    排序默认升序，改变规则（仿函数）
*/

/*
    对组
    pair<T1,T2> p = make_pair(value1, value2);
    p.first  p.second
*/


// 内置数据类型改变排序规则
class MyCompare
{
    public:
    bool operator() (int v1, int v2){
        return v1<v2;  // 降序
    }
};
void test01()
{
    set<int, MyCompare> s;  // 改变排序规则为降序
}
// 自定义数据类型指定排序规则，否则无法插入
class Person
{
    public:
    int age;
    int height;
};
class MyCompare2
{
    public:
    bool operator() (const Person &p1, const Person &p2){
        return p1.age<p2.age;  // 降序
    }
};
void test02()
{
    set<int, MyCompare2> s;
}