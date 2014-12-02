// http://codevs.cn/problem/1219/


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
int n,m;
LL dp[maxn][maxn];
int main()
{
    int x1,x2,y1,y2;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    dp[x1][y1]=1;
    for(int i=x1+1;i<=x2;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=dp[i-2][j-1]+dp[i-1][j-2]+dp[i-1][j+2]+dp[i-2][j+1];
    cout<<dp[x2][y2]<<endl;
}

