// http://codevs.cn/problem/1017/


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
const int maxn=60;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int hdir[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,1},{2,1},{-2,-1},{2,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//---------------------------------------------------------
string s;
LL f[maxn][10],n,i,j,r,k;
long long merge(int l,int r){
    long long num=0;
    for(;l<=r;l++)num=num*10+s[l]-'0';
    return num;
}
int main()
{
    cin>>n>>k;
    cin>>s;
    for(i=0;i<n;i++)
      f[i][0]=merge(0,i);
      for(i=1;i<n;i++)
        for(j=1;j<=k;j++)
            for(r=0;r<i;r++)//枚举断开点
              f[i][j]=max(f[i][j],f[r][j-1]*merge(r+1,i));
    cout<<f[n-1][k]<<endl;
}
