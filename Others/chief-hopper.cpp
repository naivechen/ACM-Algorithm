// https://www.hackerrank.com/challenges/chief-hopper


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
const int maxn=100010;
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
LL h[maxn];
int n;
bool check(LL target)
{
    for(int i=1;i<=n;i++)
    {
        if(target<h[i]) target-=(h[i]-target);
        else target+=(target-h[i]);
        if(target>=inf) return true;
        if(target<0) return false;
    }
    return true;
}
int main()
{
    LL left=0, right=0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%lld", &h[i]), right+=h[i];
    while(left<=right)
    {
        LL mid=(left+right)/2;
        if(check(mid)) right=mid-1;
        else left=mid+1;
    }
    printf("%lld\n", left);
}
