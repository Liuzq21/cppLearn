#include<deque>
#include<algorithm>
/*
    内部有一个中控器，每段维护一个缓冲区，缓冲区中存放真实的数据。
    访问较慢，插入删除很快。支持随机访问

    很多方法和vector类似
    // 默认构造
    // 赋值
    // 大小
    // 插入删除
    push_back(elem);
    push_front(elem);
    pop_back();
    pop_front();
    其他的和vector一样
    // 排序algorithm里面的
    sort(d.begin(),d.end());  // 对于支持随机访问的容器，都可以进行排序
*/