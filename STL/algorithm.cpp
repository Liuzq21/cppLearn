#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

/*
    for_each(beg, end,_func);  // 每个元素执行_func
    transform(beg1,end1,beg2,_func);  // [原始容器起始，原始容器结束，目标容器起始迭代器，仿函数] 搬运
    // 常用查找统计
    find(beg, end, value)    // 查找---返回值是迭代器，没找的返回end()
    find_if(beg, end, _pred)    // 按条件查找, 第三个参数是谓词
    adjacent_find(beg,end)           // 查相邻重复元素，查到返回第一个元素的迭代器，没找到返回end(); 面试直接用
    bool binary_search(beg,end,value)  // 无序序列中不可用，查找指定元素
    int count(beg, end, value)         // 统计内置数据类型、自定义类型(需要重写==操作符)
    count_if(beg,end,_pred)
    // 常用排序
    sort(beg, end, _pred)
    random_shuffle(beg, end)  // 洗牌，打乱
    merge(beg1, end1, beg2, end2, dest) // 两个容器合并，放到dest容器内。必须都有序。注意目标容器提前分配空间resize()
    reverse(beg, end)      
    // 常用拷贝和替换
    copy(beg,end,dst)  // 注意分配空间
    replace(beg, end, oldvalue, newvalue)
    replace_if(beg, end, _pred, newvalue)
    swap(container c1, container c2)  // 交换同种类型容器

    算术生成算法----- 在numeric头文件里
    T total = accumulate(beg, end, value) // value是起始累加值，开始累加beg到end的值
    fill(begin, end, value)  // 用value填充

    常用集合算法(不只是set，适用于所有容器)------ 交并差
    iterator itEnd = set_intersection(beg1,end1,beg2,end2,dst)   // 注意开辟空间，取小容器的值 resize(min(size1,size2)) 返回值是交集的最后一个元素位置
    set_union(beg1,end1,beg2,end2,dst)  // 开辟空间resize(size1+size2) 返回值是并集的最后一个元素位置
    set_difference(beg1,end1,beg2,end2,dst)   // resize(max(size1,size2)) 返回值是差集的最后一个元素位置
*/
class TransformPlus10
{
    int operator() (int v){
        return v+10;
    }
};
class Person
{
    public:
    int age;
    int height;

    bool operator== (Person& p1)
    {
        if(p1.age == this->age) return true;
    }
};
void test01()
{
    vector<int>v1,v2;
    v2.resize(v1.size()); // 目标容器要提前开辟空间
    transform(v1.begin(),v1.end(),v2.begin(), TransformPlus10());

    Person p1,p2;
    vector<Person> v3;
    v3.push_back(p1);
    v3.push_back(p2);
    count(v3.begin(),v3.end(),p2);  // 需要重写==操作符
}