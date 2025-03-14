/*
风向(int) 风程
->风向(string) 风力(int)

下标  1    2    3  ...
左   113  113+225*1  113+225*2
右   337  562  787
方位 NNE  NE   ENE

规律：角度每次加225，那么可以改用两个变量存储；
有的方位是相邻两者之和——但这个想法没啥用。

最终，仅需建立一个数组存储除所有方位（除了N）。最后特判一下N的情况。

风力虽没规律，但是仍可以简化存储：
显然，相邻风力的上下限就相差了0.1，你就可以用下个风力的min，减去0.1后，得到此风力的max。

    0    1    2    3    4    5         12
   0.0  0.3  1.6  3.4  5.5  8.0  ...  32.7

并且，注意输出C。

*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const char a[][5]={"","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
int b[]={0,3,16,34,55,80,108,139,172,208,245,285,327};

风力i: b[i]<= <b[i+1]
int main(){
    int deg,dis;
    scanf("%d%d",&deg,&dis);

    int level;

    dis=int(dis/6.0+0.5);
    for(int i=0;i<12;i++){
        int L=b[i],R=b[i+1]-1;
        if(L<=dis && dis<=R)
            level=i;
    }
    if(dis>=b[12]) level=12;

    if(level==0){ //为了不改变下面的代码，这里直接return
        printf("C 0\n");
        return 0;
    }

    int L=113,R=337;
    for(int i=1;i<=15;i++){
        if(L<=deg && deg<=R) //要注意，C++没有连续比较的写法
            printf("%s ",a[i]);
        L+=225, R+=225;
    }
    if(deg<=112 || deg>=3488)
        printf("N ");

    printf("%d\n",level);

    return 0;
}