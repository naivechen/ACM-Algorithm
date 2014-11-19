// http://codeforces.com/contest/489/problem/B


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
const int maxn=110;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n,m,g[maxn][maxn];
int a[maxn],b;
int vis[maxn],lin[maxn];
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
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    memset(g,0,sizeof(g));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>b;
        for(int j=1;j<=n;j++)
            if(abs(a[j]-b)<=1) g[i][j]=1;
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i)) ans++;
    }
    cout<<ans<<endl;
}

