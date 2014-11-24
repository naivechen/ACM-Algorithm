// http://acm.hdu.edu.cn/showproblem.php?pid=1312


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
const int maxn=100;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n,m,g[maxn][maxn];
int x,y;
struct chen
{
    int x,y;
}info;
void bfs()
{
    queue<chen> q;
    info.x=x;info.y=y;
    q.push(info);
    while(!q.empty())
    {
        chen ch=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=fdir[i][0]+ch.x;
            int yy=fdir[i][1]+ch.y;
            if(xx>=1 && xx<=n && yy>=1 && yy<=m && g[xx][yy]==0)
            {
                info.x=xx;info.y=yy;
                g[xx][yy]=2;
                q.push(info);
            }
        }
    }
}
int main()
{
    while(cin>>m>>n)
    {
        if(n==0 && m==0) break;
        char c;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='#') g[i][j]=1;
                else if(c=='@') {x=i;y=j;g[i][j]=2;}
            }
        bfs();
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(g[i][j]==2) ans++;
        cout<<ans<<endl;
    }
}


