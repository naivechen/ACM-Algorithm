// http://acm.zjut.edu.cn/onlinejudge/problem.php?id=1257

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
int n,a[maxn],dp[maxn][2];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[1][1]=a[1];
        dp[1][0]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i][1]=dp[i-1][0]+a[i];
            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        }
        printf("%d\n",max(dp[n][1],dp[n][0]));
    }
}
