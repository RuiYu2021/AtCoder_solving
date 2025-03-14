#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int N=3e4+10,TIME=2410;
typedef pair<int,int> pii;
int n;
pii a[N];

void Init(int idx){
    int x,y;scanf("%d-%d",&x,&y);
    x-=x%5;
    if(y%5) y+=(5-y%5);
    if(y%100==60) y=(y/100+1)*100; //进位要给小时数+1
    a[idx]={x,y};
    // printf("%d %d\n",a[idx].first,a[idx].second);
}


void Solution1(){ //排序。
    sort(a+1,a+n+1);
    a[n+1]={9999,10000};
    int L=a[1].first, R=a[1].second;
    for(int i=2,x,y;i<=n+1;i++){
        x=a[i].first, y=a[i].second;
        if(x<=R) R=max(R,y);
        else{
            printf("%04d-%04d\n",L,R);
            L=x, R=y;
        }
    }
}
int b[TIME];
void Solution2(){ //桶存储
    for(int i=1;i<=n;i++)
        b[a[i].first]++,b[a[i].second+1]--;

    int pre=0,sum=0,L;
    for(int i=0;i<=2401;i++){
        sum+=b[i];
        if(sum){
            if(i==0 || pre==0) L=i;
        }
        else
            if(pre) printf("%04d-%04d\n",L,i-1);
        pre=sum;
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) Init(i);

    // if(n%7<=3)
    //     Solution1();
    // else
    Solution2();

    return 0;
}