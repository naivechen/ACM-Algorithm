// http://acm.hust.edu.cn/vjudge/problem/visitOriginUrl.action?id=41822


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
int dis[maxn][maxn];
int x[maxn],y[maxn];
int dp[1<<16][maxn];
int num;
char c;
int Dis(int i,int j)
{
    return max(abs(x[i]-x[j]),abs(y[i]-y[j]));
}
void init()
{
    memset(dis,0,sizeof(dis));
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(dp,0,sizeof(dp));
    num=0;
}
int main()
{
  //  freopen("in","r",stdin);
    while(cin>>n>>m)
    {
        init();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                if(c=='L') x[0]=i,y[0]=j;
                else if(c=='#')
                {
                    x[++num]=i;
                    y[num]=j;
                }
            }
        if(!num)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<=num;i++)
            for(int j=0;j<=num;j++)
                dis[i][j]=Dis(i,j);
        int maxn=(1<<num)-1;
        for(int i=0;i<=maxn;i++)
            for(int j=0;j<=num;j++)
                dp[i][j]=inf;
        for(int i=1;i<=num;i++)
            dp[1<<(i-1)][i]=dis[0][i];
        for(int i=0;i<maxn;i++)
        {
            for(int j=1;j<=num;j++)
                if((1<<(j-1) ) & i)
                {
                    for(int k=1;k<=num;k++)
                        if(!( (1<<(k-1)) & i ) && dp[i+(1<<(k-1))][k]>dp[i][j]+dis[j][k])
                            dp[i+(1<<(k-1))][k]=dp[i][j]+dis[j][k];
                }
        }
        int ans=inf;
        for(int i=1;i<=num;i++)
            if(dp[maxn][i]+dis[0][i]<ans) ans=dp[maxn][i]+dis[0][i];
        cout<<ans<<endl;
    }
}
