// http://acm.hdu.edu.cn/showproblem.php?pid=1241


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
const int maxn=1010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//----------------------------------------------------------
char g[maxn][maxn];
int n,m;
struct chen
{
    int x,y;
}info;
bool check(int x,int y)
{
    if(1<=x && x<=n && 1<=y && y<=m) return true;
    return false;
}
void bfs(int i,int j)
{
    info.x=i;info.y=j;
    queue<chen> q;
    q.push(info);
    while(!q.empty())
    {
        chen ch=q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int x=edir[i][0]+ch.x;
            int y=edir[i][1]+ch.y;
            if(check(x,y) && g[x][y]=='@')
            {
                g[x][y]='*';
                info.x=x;info.y=y;
                q.push(info);
            }
        }
    }
}
int main()
{
    while(cin>>n>>m && n && m)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>g[i][j];
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(g[i][j]=='@')
                {
                    g[i][j]='*';
                    bfs(i,j);
                    ans++;
                }
            }
        cout<<ans<<endl;
    }
}
