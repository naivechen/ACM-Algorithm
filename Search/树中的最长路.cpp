// http://hihocoder.com/problemset/problem/1050?sid=246641



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
const int maxn=100010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
vector<int> g[maxn];
int ans;
int st;
void dfs(int root,int father,int num)
{
    if(g[root].size()==1 && root!=st)
    {
        if(num>ans)
        {
            ans=num;
            st=root;
        }
    }
    else
    {
        for(int i=0;i<g[root].size();i++)
        {
            int u=g[root][i];
            if(u!=father)
            {
                dfs(u,root,num+1);
            }
        }
    }
}
int main()
{
   // freopen("in","r",stdin);
    scanf("%d",&n);
    int u,v;
    st=1;
    ans=0;
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==1) ans=0;
    else
    {
        dfs(1,-1,0);
        ans=0;
        dfs(st,-1,0);
    }
    printf("%d\n",ans);
}
