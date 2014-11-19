// http://acm.hdu.edu.cn/showproblem.php?pid=2063


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
const int maxn=510;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int g[maxn][maxn],lin[maxn],vis[maxn];
int n,m,k,u,v;
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
    while(cin>>k && k)
    {
        memset(lin,0,sizeof(lin));
        memset(g,0,sizeof(g));
        cin>>n>>m;
        for(int i=1;i<=k;i++)
        {
            cin>>u>>v;
            g[u][v]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i)) ans++;
        }
        cout<<ans<<endl;
    }
}
