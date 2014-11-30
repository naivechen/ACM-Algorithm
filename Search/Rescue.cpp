// http://acm.hdu.edu.cn/showproblem.php?pid=1242


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
char g[maxn][maxn];
int n,m,x,y,vis[maxn][maxn];
struct chen
{
    int x,y,step;
    friend bool operator<(chen a, chen b) // 优先队列，需要学一下STL
    {
        return a.step>b.step;
    }
}info;
int bfs()
{
    priority_queue<chen> q;
    info.x=x;info.y=y;
    info.step=0;
    vis[info.x][info.y]=1;
    q.push(info);
    while(!q.empty())
    {
        chen ch=q.top();
        q.pop();
        vis[ch.x][ch.y]=1;
        if(g[ch.x][ch.y]=='r')
        {
            return ch.step;
        }
        for(int i=0;i<4;i++)
        {
            int x=fdir[i][0]+ch.x;
            int y=fdir[i][1]+ch.y;
            if(x>=1 && x<=n && y>=1 && y<=m && !vis[x][y] )
            {
                vis[x][y]=1;
                if(g[x][y]=='.' || g[x][y]=='r')
                {
                    info.x=x;info.y=y;
                    info.step=ch.step+1;
                    q.push(info);
                }
                else if(g[x][y]=='x')
                {
                    info.x=x;info.y=y;
                    info.step=ch.step+2;
                    q.push(info);
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
                if(g[i][j]=='a')
                {
                    x=i;y=j;
                }
            }
        int ans=bfs();
        if(ans!=-1)printf("%d\n",ans);
        else printf("Poor ANGEL has to stay in the prison all his life.\n" );
    }
}
