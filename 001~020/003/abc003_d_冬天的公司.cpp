#include<iostream>
#include<cstdio>
using namespace std;
const int N=910,mod=1e9+7;
typedef long long ll;
ll c[N][N];//预处理好组合数。
void Prework(){
    c[0][0]=c[1][0]=c[1][1]=1; //c[i,j]:在i个数中选择j个的方案数.
    for(int i=2;i<N;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;//j=i时后者为0，也没问题
    }
}
ll f(int sum,int D,int L){//可能会有D=x*y了，那么需要令c[0][0]=1.
    if(sum<D+L) return 0;//考虑减去部分行列后，可能放不下的情形。

    return c[sum][D]*c[sum-D][L]%mod;
}
int get_1(int x){//返回二进制下1的个数。
    int cnt=0;
    while(x)
        cnt+=(x&1),x>>=1;
    return cnt;
}
int main(){
    Prework();
    int r,c,x,y,D,L;scanf("%d%d%d%d%d%d",&r,&c,&x,&y,&D,&L);

    ll parts=(r-x+1)*(c-y+1);//全图能划分为多少个区块。

    if(D+L==x*y){
        printf("%lld\n",parts*c[x*y][D]%mod);
        return 0;
    }

    ll sum=f(x*y,D,L);

    ll dismatch=0;//接下来计算不符合的数目。
    for(int i=1;i<(1<<4);i++){//从1开始，也就是“下行”空缺.
        //高二位的1表示空缺左右列，低二位的1表示空缺上下行。 1011
        int flag = (get_1(i)%2? 1:-1);
        dismatch=(dismatch + flag*f(
            max(x-get_1(i&3), 0) * max(y-get_1(i>>2), 0),
            D,L)) % mod;
    }

    // printf("sum=%d dismatch=%d\n",sum,dismatch);
    sum=(sum-dismatch+mod)%mod; //这里可能会超int，所以开个longlong.
    //dismatch最终的结果会是在-mod~mod之间，因此这里最多是3mod，会超2.1e9的int范围。
    printf("%lld\n",(ll)parts*sum%mod);
    return 0;
}