// http://hihocoder.com/problemset/problem/1032?sid=218878
// http://blog.csdn.net/geniusluzh/article/details/8639759

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
const int maxn=10000010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
char s[maxn],ss[maxn<<1];
int dp[maxn<<1];
int solve(int len)
{
    int ans=0,right=-1,id=-1;
    for(int i=0;i<len;i++)
    {
        int r=1;
        if(right>=i)
            r=max(r,min(right-i+1,dp[2*id-i]));
        while((i-r+1>=0 && i+r-1<len) && (ss[i-r+1] == ss[i+r-1]))
            r++;
        r--;
        if(i+r-1>right)
        {
            right=i+r-1;
            id=i;
        }
        dp[i]=r;
        if(ans<r) ans=r;
    }
    return ans-1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int cnt=0,len=strlen(s);
        for(int i=0;i<len;i++)
        {
            ss[cnt++]='#';
            ss[cnt++]=s[i];
        }
        ss[cnt++]='#';
        printf("%d\n",solve(cnt));
    }
}
