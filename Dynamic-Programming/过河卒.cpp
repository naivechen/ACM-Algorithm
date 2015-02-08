// http://codevs.cn/problem/1010/

// When I wrote this, only God and I understood what I was doing
// now, God only knows

#pragma comment(liner, "/STACK:1024000000,1024000000")
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
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define LL long long int
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=40;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int hdir[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,1},{2,1},{-2,-1},{2,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//---------------------------------------------------------
int n,m;
int x,y;
int dp[maxn][maxn];
int vis[maxn][maxn];
int main()
{
    cin>>n>>m>>x>>y;
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int xx=x+hdir[i][0];
        int yy=y+hdir[i][1];
        if(xx>=0 && x<=n && yy>=0 && yy<=m)
        {
            vis[xx][yy]=1;
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        if(!vis[i][0])
            if(i>1) dp[i][0]=dp[i-1][0];
            else dp[i][0]=1;
    for(int j=1;j<=m;j++)
        if(!vis[0][j])
            if(j>1) dp[0][j]=dp[0][j-1];
            else dp[0][j]=1;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!vis[i][j]) dp[i][j]=dp[i-1][j]+dp[i][j-1];
    cout<<dp[n][m]<<endl;
}
