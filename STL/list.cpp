#include<list>
#include<string>
using namespace std;
/*
    list
    双向循环链表
    双向迭代器
    构造、赋值、大小 和 vector 类似
    数据存取: front()  back()
    反转：L1.reverse()
    排序：L1.sort()  因为不支持随机访问，所以不可sort(L.begin(),L.end());
    交换
    swap(lst);

    插入删除 和deque 类似
*/

// 自定义类排序
class Person
{
    public:
    int age;
    int height;
};

bool comparePerson(Person &p1, Person &p2)
{
    if (p1.age > p2.age) return true;  // 按年龄降序
    if (p1.age == p2.age)
    {
        if(p1.height < p2.height) return true;  // 按体重升序
    }
    else return false;

}

void sortPerson()
{
    list<Person> L1;
    L1.sort(comparePerson);
}