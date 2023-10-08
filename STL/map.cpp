#include<map>
using namespace std;
/*
    对组
    pair<T1,T2> p = make_pair(value1, value2);
    p.first  p.second
*/
/*
    map 中所有元素都是pair； key ： value。按照key自动排序
    map / multimap 是关联容器，底层是二叉树

    构造：map<T1,T2> m;
    size() empty() swap(st);
    插入删除：insert(pair<T1,T2>(key,value))  insert(make_pair(key,value))  删除时按key删
    访问 m[5] // 【】的方法，如果没有则创建，并赋值为0
    查找：find(key)
    统计：count(key)
    排序：默认升序。改变排序规则，与set类似
*/