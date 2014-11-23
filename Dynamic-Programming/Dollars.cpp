// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=83


#include<stdio.h>
#define N 30005
#include<string.h>
#define ll long long
int d[11]= {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[15][N];//dp[i][j]表示用前i种硬币，组成j分的种类数
ll DP(ll i,ll j)
{
    //printf("%d %d %d\n",i,j,dp[i][j]);
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=0;
    for(int k=0;j-k*d[i]>=0;k++)
    {
        dp[i][j]+=DP(i-1,j-k*d[i]);
    }
    return dp[i][j];
}
int main()
{
    double nn;
    memset(dp,-1,sizeof(dp));//赋值一次即可，否则可能会超时
    while(scanf("%lf",&nn)!=EOF)
    {
        if(nn==0.00)
            break;
        int n=(int)(nn*100+0.5);//注意精度
        for(ll i=0; i<=n; i++)
            dp[0][i]=1;
            printf("%6.2f%17lld\n",nn,DP(10,n));
    }
    return 0;
}
