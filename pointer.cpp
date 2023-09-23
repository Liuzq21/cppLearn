#include<iostream>
using namespace std;

void swap(int *p1, int *p2){
    int e = *p1;
    *p1 = *p2;
    *p2 = e;
}

int main(){
    int *p = NULL;  // empty pointer. unaccessable
    // 0~255 是系统使用的内存编号。
    // 野指针是 没被分配的其他内存地址
    int a=3;
    const int *p = &a;  // 常量指针的指向可以修改，指针指向的值不可修改。
    int * const p1 = &a; // 指针常量指针的指向不可改，指向的值可以改。
    const int * const p2 = &a; // 都不可改

    // 指针和数组
    int arr[] = {1,2,3,4,5,6};
    int *p = arr;
    cout<< "first number : "<< *p<<endl;
    p++;
    cout<< "second number : "<< *p<<endl;

    // 指针和函数
    int a =1;
    int b=2;
    swap(&a, &b);

    return 0;
}