#include<string>
/*
    string 构造：
        string()
        string(const char * )
        string(const string& str)
        string(int, char) // n个char初始化
    string 赋值：
        =
        assign(const char *s);
        assign(const char *s,int n); 把字符串s的前n个字符赋值给当前字符串
        assign(string &s);
        assign(int n, char);
    string 拼接 同上类似
        +=
        append(const string& s, int pos, int n)  // 把s的从pos开始的n个拼接
    string 查找、替换 没找到返回-1
        int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
        int find(const char s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
        int find(const char* s , int pos， int n) const;  //从pos位置查找s的前n个字符第一次位置
        int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
        int rfind(const string& str, int pos = npos) const;   //查找str最后一次位置,从pos开始查找
        int rfind( const char* s, int pos = npos) const;  // 查找s最后一次出现位置,从pos开始查找
        int rfind(const char* s, int pos， int n) const;  // 从pos查找s的前n个字符最后一次位置
        int rfind(const char c, int pos = 0) const;  //查找字符c最后一次出现位置
        string& replace(int pos, int n, const string& str);   //替换从pos开始n个字符为字符串str
        string& replace(int pos, int n,const char* s );   //替换从pos开始的n个字符为字符串s
    string 比较 相当于 s1 - s2
        int compare( const string &s ) const; //  与字符串s比较
        int compare(const char *s ) const;  //  与字符串s比较
    string 获取字符
        []
        at(int)
    string 插入
        string& insert(int pos, const char* s );  //插入字符串
        string& insert( int pos,const string& str);  //插入字符串
        string& insert(int pos, int n, char c);  // 在指定位置插入n个字符c
        string& erase(int pos, int n = npos) ;  //删除从Pos开始的n个字符
    string 子串获取
        string sub(int pos =0, int n = npos); const // 返回从pos开始的n个字符


*/
