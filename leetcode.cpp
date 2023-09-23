#include<iostream>
#include<string>
using namespace std;


int main(){
    const string s = "babad";
    int len = s.length();
    if(len == 0||len == 1){cout<<s<<endl; return 0;}

    int dp[len][len];
    cout<<s<<endl;
    for(int i=0; i<len;i++){
        dp[i][i] = 1;
    }
    
    int maxlen = 1; int index = len-1;
    for(int i=len-2;i>=0;i--){
        for(int j=i+1;j<len; j++){
            if(s[i] == s[j]) {
                if(j == i+1){
                    // 相邻
                    dp[i][j] = 1;
                }else{
                    if(dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                    }
                }
                if(dp[i][j] && maxlen < j-i+1){
                    maxlen = j-i+1;
                    index = i;
                }
            }
        }
    }
    cout<<s.substr(index, maxlen)<<endl;
    return 0;
}

