#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=12;
char a[N],b[N],ok[10]="atcoder"; //数组请定义在main函数外边！
bool tf[129];

int main(){
    scanf("%s%s",a+1,b+1);
    int n=strlen(a+1);
    // printf("%s",b+1);

    for(int i=0;i<7;i++) tf[ok[i]]=true;//这些字母可以被@替换

    for(int i=1;i<=n;i++){
        char ca=a[i],cb=b[i];



        int cnt=(ca=='@')+(cb=='@');
        if(cnt==1 && (tf[ca]+tf[cb]==0) || (cnt==0 && ca!=cb)){
            printf("You will lose\n");
            return 0;
        }
    }
    printf("You can win\n");
    return 0;
}