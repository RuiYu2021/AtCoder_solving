#include<iostream>
#include<cstdio>
// #define choice 3
using namespace std;
const int N=13;
bool mp[N][N];int n,m,ans=0;
int choice;

bool vis[N];
void dfs(int p){//现在要选第p个人

    if(p==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(vis[i]){
                cnt++;
                for(int j=i+1;j<=n;j++)
                    if(vis[j] && !mp[i][j])
                        return;
            }
        ans=max(ans,cnt);
        return;
    }
    //选
    vis[p]=true;
    dfs(p+1);


    vis[p]=false;
    //不选
    dfs(p+1);
}

int total_cnt=0;
void dfs_jz(int p){
    if(p==n+1){
        ans=max(ans,total_cnt);
        return;
    }
    bool able=true;
    for(int i=1;i<p;i++)
        if(vis[i] && !mp[i][p]){
            able=false;
            break;
        }

    if(able){
        vis[p]=true,total_cnt++;
        dfs_jz(p+1);


        vis[p]=false,total_cnt--;//回溯的“复原”思想
    }

    dfs_jz(p+1);
}

void Solution1(){//dfs
    if(choice==1)
        dfs(1);
    else
        dfs_jz(1);
    printf("%d\n",ans);
}

int bits[N];
void Solution2(){//位运算（这个东西与其看我写，不如自己写一遍）

    for(int i=1;i<=n;i++)
        mp[i][i]=1;


    // mp[1][1~5]=1,1,0,1,0

    // 11010&11101 //压位

    // 11000&01111


    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=n;j++)
            t=(t<<1)|mp[i][j];//0|0=0 0|1=1
        bits[i]=t;
    }

    // 000101001 ~ 110111111
    //         1

    for(int i=1;i<(1<<n);i++){

        int result=(1<<n)-1, t=i, cnt=0;
        for(int j=n;j>=1;j--){ //注意顺序：一开始的个位，是最后那个人。
            if(t&1) result&=bits[j], cnt++;
            t>>=1;
        }
        
        // A={1,2,3},B={1,2,3,4,5} A|B=B

        if((result&i)==i) ans=max(ans,cnt);//优先级注意下，不然先执行==
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++) 1 2
        scanf("%d%d",&x,&y), mp[x][y]=mp[y][x]=1; //互相认识

    choice=(n+m)%3+1;
    if(choice<=2)
        Solution1();
    else
        Solution2();
    
    return 0;
}
