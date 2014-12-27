// http://hihocoder.com/problemset/problem/1089


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
const int maxn=110;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
int g[maxn][maxn];
int dp[maxn][maxn];
void Floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]),dp[j][i]=dp[i][j];
}
int main()
{
   // freopen("in","r",stdin);
    cin>>n>>m;
    memset(dp,0x1f,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=dp[v][u]=min(w,dp[u][v]);
    }
    Floyd();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>1) cout<<" "<<dp[i][j];
            else cout<<dp[i][j];
        }
        cout<<endl;
    }
}
