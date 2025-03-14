#include<iostream>
// #include<typeinfo>
#include<cstdio>
using namespace std;
int main(){
    // printf("%d\n",typeid(double)==typeid(1.2));
    int m;
    scanf("%d",&m);
    double km=m/1000.0; //注意此处的类型转换方式
    int vv;
    if(km<0.1) //先处理，最后再输出。
        vv=0;
    else if(km<=5)
        vv=km*10;
    else if(km<=30)
        vv=km+50;
    else if(km<=70)
        vv=(km-30)/5+80;
    else
        vv=89;
    printf("%02d\n",vv); //输出格式

    return 0;
}