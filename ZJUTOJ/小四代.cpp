//http://acm.zjut.edu.cn/onlinejudge/problem.php?id=1255

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
//---------------------------------------------------------
char g[55][55];
int n;
void paint(int l, int r, int d)
{
    int now = d%4;
    g[l][r] = '*';
    if(now == 0)
    {
        if (r - 1 < 1  || g[l][r-2] == '*')
        {
            if (l+1 > n || g[l+1][r] == '*' || g[l+2][r] == '*')
                return;
            paint(l+1,r,d+1);
        }
        else
            paint(l,r-1,d);
    }
    else if(now == 1)
    {
        if (l + 1 > n  || g[l+2][r] == '*')
        {
            if (r+1 > n || g[l][r+1] == '*' || g[l][r+2] == '*')
                return;
            paint(l,r+1,d+1);
        }
        else
            paint(l+1,r,d);
    }
    else if(now == 2)
    {
        if (r + 1 > n  || g[l][r+2] == '*')
        {
            if (l-1 < 1 || g[l-1][r] == '*' || g[l-2][r] == '*')
                return;
            paint(l-1,r,d+1);
        }
        else
            paint(l,r+1,d);
    }
    else
    {
        if (l - 1 < 1 || g[l-2][r] == '*')
        {
            if (r-1 < 1 || g[l][r-1] == '*' || g[l][r-2] == '*')
                return;
            paint(l,r-1,d+1);
        }
        else
            paint(l-1,r,d);
    }
}
 
int main()
{
    int i, j;
    while (~scanf("%d", &n))
    {
        memset(g, ' ',sizeof(g));
        paint(1,n,0);
        for (i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                printf("%c", g[i][j]);
            printf("\n");
        }
    }
    return 0;
}
