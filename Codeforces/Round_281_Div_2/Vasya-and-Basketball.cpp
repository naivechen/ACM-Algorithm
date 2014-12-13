// http://codeforces.com/contest/493/problem/C


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
const int maxn=200010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t1,t2;
int l1,l2;
int n,m,ans,ans1,ans2;
int a[200005],b[200005],c[400005];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),c[i]=a[i];
    sort(a+1,a+n+1);
    m=read();
    for(int i=1;i<=m;i++)b[i]=read(),c[i+n]=b[i];
    sort(b+1,b+m+1);
    sort(c+1,c+n+m+1);
    ans1=n*3;ans2=m*3;
    ans=(ans1-ans2);
    l1=l2=0;
    for(int i=1;i<=n+m;i++)
    {
        while(l1!=n&&a[l1+1]<=c[i])l1++;
        while(l2!=m&&b[l2+1]<=c[i])l2++;
        t1=l1*2+(n-l1)*3,t2=l2*2+(m-l2)*3;
        if(t1-t2>ans||(t1-t2==ans&&t1>ans1))ans=t1-t2,ans1=t1,ans2=t2;
    }
    printf("%d:%d\n",ans1,ans2);
    return 0;
}
