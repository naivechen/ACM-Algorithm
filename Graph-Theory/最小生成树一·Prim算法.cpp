// http://hihocoder.com/problemset/problem/1097?sid=246600



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
const int maxn=100510;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
struct chen
{
    int x,y;
    int dis;
}ch[1000010];
int num=0;
int path[1000010];
bool cmp(chen a,chen b)
{
    return a.dis<b.dis;
}
int find(int x)
{
    int r=x;
    while(r!=path[r])
    {
        r=path[r];
    }
    int i=x,j=-1;
    while(i!=j)
    {
        j=path[i];
        path[i]=r;
        i=j;
    }
    return r;
}
int main()
{
    freopen("in","r",stdin);
    int dis,u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&dis);
            if(j>i)
            {
                num++;
                ch[num].x=i;
                ch[num].y=j;
                ch[num].dis=dis;
            }
        }
    sort(ch+1,ch+1+num,cmp);
    for(int i=1;i<=n;i++)
        path[i]=i;
    int ans=0;
    for(int i=1;i<=num;i++)
    {
        int fa=find(ch[i].x);
        int fb=find(ch[i].y);
        if(fa!=fb)
        {
            ans+=ch[i].dis;
            path[fa]=fb;
        }
    }
    printf("%d\n",ans);
}
