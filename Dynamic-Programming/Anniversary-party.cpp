// http://poj.org/problem?id=2342

#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdlib>
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
const int maxn=100010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int vis[maxn];
int dp[maxn][10];
int father[maxn];
int n;
void dfs(int  root)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && father[i]==root)
        {
            dfs(i);
            dp[root][1]+=dp[i][0];
            dp[root][0]+=max(dp[i][1],dp[i][0]);
        }
    }
}
int main()
{
   // freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(father,0,sizeof(father));
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d",&dp[i][1]);
        int root=0;
        while(1)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            if(u==0 && v==0) break;
            father[u]=v;
            root=v;
        }
        dfs(root);
        printf("%d\n", max(dp[root][1],dp[root][0])) ;
    }
}
