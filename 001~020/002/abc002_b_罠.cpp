#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=35;
char a[N];int len;
string s="aeiou";
int main(){
    scanf("%s",a+1); //从下标为1的地方开始读取（这可以避免+1-1绕来绕去的转换）
    len=strlen(a+1);
    // for(int i=1;i<=len;i++){//不是元音之一，就输出。找=find
    //     if(s.find(a[i])==s.npos) //no_position
    //         putchar(a[i]);
    // }
    // putchar('\n');

    //或者：
    bool b[128];memset(b,0,sizeof(b));//全设为false
    b['a']=b['e']=b['i']=b['o']=b['u']=true;
    for(int i=1;i<=len;i++) b[ch]
        if(!b[a[i]]) //辅音。
            putchar(a[i]);
    putchar('\n');
    return 0;
}