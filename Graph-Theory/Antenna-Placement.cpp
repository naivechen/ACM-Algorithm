// http://poj.org/problem?id=3020


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
const int maxn=600;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
int gg[maxn][maxn];  // * -> 1
int g[maxn][maxn],vis[maxn],lin[maxn];
bool find(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(g[x][i] && !vis[i])
        {
            vis[i]=1;
            if(lin[i]==0 || find(lin[i]))
            {
                lin[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("in","r",stdin);
    int t;
    char c;
    cin>>t;
    while(t--)
    {
        int num=0;
        cin>>n>>m;
        memset(gg,0,sizeof(gg));
        memset(lin,0,sizeof(lin));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='*') gg[i][j]=++num;
                else gg[i][j]=0;
            }
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(gg[i][j]==0) continue;
                for(int k=0;k<4;k++)
                {
                    int x=i+dir[k][0], y=j+dir[k][1];
                    if(gg[x][y])  g[gg[i][j]][gg[x][y]]=g[gg[x][y]][gg[i][j]]=1;
                }
            }
        }
        n=num;m=num;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i)) ans++;
        }
        cout<<num-ans/2<<endl;
    }
}
