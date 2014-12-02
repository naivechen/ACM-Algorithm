// http://codevs.cn/problem/1014/


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
const int maxn=20010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,v,val[maxn];
int dp[maxn];
int main()
{
    cin>>v;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=v;j>=val[i];j--)
            dp[j]=max(dp[j],dp[j-val[i]]+val[i]);
    int ans=-1;
    for(int i=1;i<=v;i++)
        ans=max(ans,dp[i]);
    cout<<v-ans<<endl;
}
