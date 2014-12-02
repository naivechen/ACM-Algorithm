// http://codevs.cn/problem/1220/


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
int a[maxn][maxn],dp[maxn][maxn];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        dp[n][i]=a[n][i];
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
    cout<<dp[1][1]<<endl;
}
