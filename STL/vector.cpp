#include<vector>
#include<iostream>
using namespace std;
/*
    vector:
        动态扩展：找更大的空间，复制过去
        支持随机访问迭代器

        // 默认构造函数
        vector<T> v;
        vector(v.begin() , v.end());  // 将v[begin(), end())区间中的元素拷贝给本身。
        vector(n，elem);  //构造函数将n个elem拷贝给本身。
        vector( const vector &vec);  //拷贝构造函数。
        vector<int> v(10,100);

        // 赋值
        =
        assign( beg, end ); // 将[beg, end)迭代器区间中的数据拷贝赋值给本身。
        assign(n,elem);    将n个elem拷贝赋值给本身。

        // 容量和大小
        empty();   //判断容器是否为空
        capacity();  //容器的容量
        size();   //返回容器中元素的个数
        resize(int num ) ; //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                          //如果容器变短，则末尾超出容器长度的元素被删除。
        resize(int num，elem);// 重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                              //如果容器变短，则末尾超出容器长度的元素被删除
        
        // 插入删除
        push_back(ele);//尾部插入元素ele
        pop_back( );//删除最后一个元素
        insert(const_iterator pos, ele);//迭代器指向位置pos插入元素ele
        insert(const_iterator pos，int count, ele);//迭代器指向位置pos插入count个元素ele
        erase(const_iterator pos );//删除迭代器指向的元素
        erase(const_iterator start，const_iterator end);//删除迭代器从start到end之间的元素
        clear();//删除容器中所有元素

        // 获取元素
        []
        at();
        front();  // 返回容器中第一个数据元素
        back(); //返回容器中最后一个数据元素

        // 互换容器
        swap(vec); 
        // 可以巧用swap收缩v内存
        vector<T>(v).swap(v);

        // 预留空间  ---- 数据量很大时，预留空间，减少开辟空间次数
        reserve(int len) // /容器预留len个元素长度，预留位置不初始化，元素不可访问。

*/

void test()
{
    vector<int> v(10,100);
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<*it<<endl;
    }
}