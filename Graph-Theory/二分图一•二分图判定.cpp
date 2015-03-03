// http://hihocoder.com/problemset/problem/1121?sid=255086

// When I wrote this, only God and I understood what I was doing
// now, God only knows

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
const int maxn=10010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
vector<int> g[maxn];
int a[maxn];
bool dfs(int p, int color)
{
    for(int i=0;i<g[p].size();i++)
    {
        int tmp=g[p][i];
        if(a[tmp]==-1)
        {
            a[tmp]=color;
            dfs(tmp, color^1);
        }
        else
        {
            if(a[tmp]!=color)
                return false;
        }
    }
    return true;
}
int main()
{
  //  freopen("in","r", stdin);
    int t, u, v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            g[i].clear(), a[i]=-1;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==-1)
            {
                a[i]=0;
                flag=dfs(i,1);
                if(flag==false)
                    break;
            }
        }
        if(flag) cout<<"Correct"<<endl;
        else cout<<"Wrong"<<endl;
    }
}


