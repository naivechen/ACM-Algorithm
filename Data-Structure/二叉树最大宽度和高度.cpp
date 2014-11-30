// http://codevs.cn/problem/1501/


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
const int maxn=210;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int tree[maxn][maxn];
int b[maxn];
#define L 1
#define R 2
int n,dep,x;
void dfs(int pos,int k)
{
    b[k]=b[k]+1;
    if(k>x) x=k;
    if(tree[pos][L]!=0) dfs(tree[pos][L],k+1);
    if(tree[pos][R]!=0) dfs(tree[pos][R],k+1);
}
int main()
{
    while(cin>>n)
    {
        memset(tree,0,sizeof(tree));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            int u,v;
            cin>>u>>v;
            tree[i][L]=u;
            tree[i][R]=v;
        }
        dep=0,x=0;
        dfs(1,1);
        for(int i=0;i<maxn;i++)
            dep=max(dep,b[i]);
        cout<<dep<<" "<<x<<endl;
    }
}
