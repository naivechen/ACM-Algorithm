// https://www.hackerrank.com/challenges/the-grid-search
// When I wrote this, only God and I understood what I was doing
// now, God only knows

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
const int maxn=1001;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int hdir[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,1},{2,1},{-2,-1},{2,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//---------------------------------------------------------
int g[maxn][maxn];
int p[maxn][maxn];
int R,C,r,c;
bool check(int x, int y)
{
    int xx=x, yy=y, i, j;
    for(i=1, xx=x;i<=r;i++, xx++)
    {
        for(j=1, yy=y;j<=c;j++, yy++)
        {
            if(xx<1 || xx>R || yy<1 || yy>C) return false;
            if(g[xx][yy]!=p[i][j]) return false;
        }
    }
    return true;
}
bool solve()
{
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            if(g[i][j]==p[1][1])
                if(check(i,j)) return true;
    return false;
}
int main()
{
    int t;
    char cc;
    cin>>t;
    while(t--)
    {
        cin>>R>>C;
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
            {
                cin>>cc;
                g[i][j]=cc-'0';
            }
        cin>>r>>c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                cin>>cc;
                p[i][j]=cc-'0';
            }
        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
}
