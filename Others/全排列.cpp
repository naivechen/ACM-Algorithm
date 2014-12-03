// http://codevs.cn/problem/1294/


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
const int maxn=210;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m,da[maxn];
int vis[maxn];
void solve(int pos)
{
    if(pos>n)
    {
        for(int i=1;i<pos;i++)
            printf("%d ",da[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            da[pos]=i;
            vis[i]=1;
            solve(pos+1);
            vis[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    solve(1);
}
