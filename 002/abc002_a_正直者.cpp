#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    // int a,b;scanf("%d%d",&a,&b);
    // printf("%d\n",max(a,b));

    long long c;int d; scanf("%lld%d",&c,&d);
    printf("%lld\n",max(c,(long long)d)); //不同类型间不能直接用，需要转换一下。
    return 0;
}