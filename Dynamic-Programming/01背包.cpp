// http://hihocoder.com/problemset/problem/1038?sid=232769


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
int cost[maxn],val[maxn];
int dp[maxn];
int main()
{
   // freopen("in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>cost[i]>>val[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=cost[i];j--)
            dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
    cout<<dp[m]<<endl;
}
