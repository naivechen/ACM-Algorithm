// http://poj.org/problem?id=1422


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
int g[maxn][maxn],vis[maxn],lin[maxn];
bool find(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(g[x][i] && !vis[i])
        {
            vis[i]=1;
            if(lin[i]==0 || find(lin[i]))
            {
                lin[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(lin,0,sizeof(lin));
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u][v]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i)) ans++;
        }
        cout<<n-ans<<endl;
    }
}

