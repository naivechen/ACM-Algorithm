// http://poj.org/problem?id=2486


#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <cassert>
#include <set>
using namespace std;
#define LL long long
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=205;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m,ans,step;
int val[maxn], next[maxn][maxn],cnt[maxn],vis[maxn];
int dp[2][maxn][maxn];
void dfs(int u)
{
    int v;
    for(int i=0;i<=step;i++)
        dp[0][u][i]=dp[1][u][i]=val[u];
    vis[u]=1;
    for(int i=1;i<=cnt[u];i++)
    {
        v=next[u][i];
        if(!vis[v])
        {
            dfs(v);
            for(int j=step;j>=0;j--)
                for(int k=0;k<=j;k++)
                {
                    dp[0][u][j+2]=max(dp[0][u][j+2],dp[0][v][k]+dp[0][u][j-k]);
                    dp[1][u][j+2]=max(dp[1][u][j+2],dp[0][v][k]+dp[1][u][j-k]);
                    dp[1][u][j+1]=max(dp[1][u][j+1],dp[1][v][k]+dp[0][u][j-k]);
                }
        }
    }
}
int main()
{
    while(scanf("%d %d",&n,&step)!=EOF)
    {
        int u,v;
        memset(dp,0,sizeof(dp));
        memset(next,0,sizeof(next));
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            cin>>val[i];
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            next[u][++cnt[u]]=v;
            next[v][++cnt[v]]=u;
        }
        dfs(1);
        cout<<dp[1][1][step]<<endl;
    }
    return 0;
}
