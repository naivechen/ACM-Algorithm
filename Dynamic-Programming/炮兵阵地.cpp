// http://poj.org/problem?id=1185


#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
int n,m;
char g[110][11]; //记录原始图
int base[110];  //初始状态
int state[110];    //枚举状态
int soldier[110];  //枚举状态对应的士兵数量
int dp[110][110][110];  //dp[r][i][j] 表示枚举第r行时，state[i],state[j]的状态
int num;              //总的枚举数量
void init()
{
    memset(g,0,sizeof(g));
    memset(base,0,sizeof(base));
    memset(state,0,sizeof(state));
    memset(soldier,0,sizeof(soldier));
    memset(dp,0,sizeof(dp));
    num=0;
}
bool judge(int a,int b)
{
    if(a & b) return true;
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",g[i]);
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='H')
                base[i]+=(1<<j);
        }
    }
    for(int i=0;i<(1<<m);i++)
    {
        if(judge(i,i<<1) || judge(i,i<<2)) continue ;
        int k=i;
        while(k)
        {
            soldier[num]+=(k&1);
            k>>=1;
        }
        state[num++]=i;
    }
    //第0行
    for(int i=0;i<num;i++)
    {
        if(judge(state[i],base[0])) continue ;
        dp[0][i][0]=soldier[i];
    }
    //第1行
    for(int i=0;i<num;i++)
    {
        if(judge(state[i],base[1])) continue ;
        for(int j=0;j<num;j++)
        {
            if(judge(state[i],state[j])) continue ;
            if(judge(state[j],base[0])) continue ;
            dp[1][i][j]=max(dp[1][i][j],dp[0][j][0]+soldier[i]);
        }
    }
    for(int r=2;r<n;r++)
    {
        for(int i=0;i<num;i++)
        {
            if(judge(state[i],base[r])) continue ;
            for(int j=0;j<num;j++)
            {
                if(judge(state[j],base[r-1])) continue ;
                if(judge(state[j],state[i])) continue ;
                for(int k=0;k<num;k++)
                {
                    if(judge(state[k],base[r-2])) continue ;
                    if(judge(state[k],state[i])) continue ;
                    if(judge(state[k],state[j])) continue ;
                    dp[r][i][j]=max(dp[r][i][j],dp[r-1][j][k]+soldier[i]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
            ans=max(ans,dp[n-1][i][j]);
    cout<<ans<<endl;
}
