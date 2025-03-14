#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=110;
int a[N];
int main(){
    double ans=0;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    sort(a+1,a+n+1), reverse(a+1,a+n+1);

    for(int i=1;i<=k;i++){
        double t=a[i];
        for(int j=1;j<=i;j++)
            t/=2;
        ans+=t;
        // ans+=a[i]/t;
        // t*=2;
    }

    printf("%.9lf\n",ans);
    return 0;
}