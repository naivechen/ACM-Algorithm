// http://www.spoj.com/problems/ABSP1/


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
const int maxn=10010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n;
LL a[maxn],sum[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        LL ans=0;
        for(int i=1;i<n;i++)
        {
            LL tmp=sum[n]-sum[i]-(n-i)*a[i];
            ans+=tmp;
        }
        printf("%lld\n",ans);
    }
}
