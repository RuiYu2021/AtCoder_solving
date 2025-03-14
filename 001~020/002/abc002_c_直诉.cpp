#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int x1,y1, x2,y2 ,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    x2-=x1,x3-=x1, y2-=y1,y3-=y1;
    printf("%.1f\n",fabs(x2*y3-x3*y2)/2);//注意abs前头有个f，表示浮点数
    return 0;
}