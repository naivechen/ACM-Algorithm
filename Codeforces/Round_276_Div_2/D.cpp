// http://codeforces.com/contest/485/problem/D


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
const int maxn=20000010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n,a[maxn],ans;
int b[maxn];
int solve(int x)
{
    int le=1,ri=n,mid;
    while(le<=ri)
    {
        mid=(le+ri)/2;
        if(a[mid]==x) return a[mid];
        else if(a[mid]<x) le=mid+1;
        else ri=mid-1;
    }
    return a[le-1];
}
int main()
{
    int nn,val;
    scanf("%d",&nn);
    n=0;
    for(int i=1;i<=nn;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+1+nn);
    a[0]=-1;
    for(int i=1;i<=nn;i++)
    {
        if(b[i]!=a[n])
        {
            ++n;
            a[n]=b[i];
        }
    }
    // from 1 to n
    ans=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=a[i];
        while(tmp<=a[n])
        {
            tmp=tmp+a[i];
            int fm=solve(tmp-1);
            int cmp=fm%a[i];
            ans=max(ans,cmp);
        }
    }
    printf("%d\n",ans);
}

