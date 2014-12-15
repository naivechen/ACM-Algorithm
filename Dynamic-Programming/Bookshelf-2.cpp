// http://poj.org/problem?id=3628


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
const int maxn=20000010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m;
int c[22],w[22],dp[maxn];
int main()
{
    cin>>n>>m;
    {
        int sum=0;
        for(int i=1;i<=n;i++)
            cin>>c[i],sum+=c[i];
        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int j=sum-c[i];j>=0;j--)
                if(dp[j]) dp[j+c[i]]=1;
        int i;
        for(i=m;i<=sum;i++)
            if(dp[i]) break;
        cout<<i-m<<endl;
    }
}
