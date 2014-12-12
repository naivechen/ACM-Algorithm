// http://codeforces.com/contest/493/problem/A



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
const int maxn=210;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
char as[maxn],ar[maxn],te[maxn];
int t1[maxn],t2[maxn];
int main()
{
    scanf(" %s %s",ar,as);
    int n,a,b,c;
    char c1,c2;
    scanf(" %d",&n);
    for(int i=0;i<n;i++)
    {
        scanf(" %d %c %d %c",&a,&c1,&b,&c2);
        if(c1=='h')
        {
            if(t1[b]>=2) continue;
            if(c2=='y') t1[b]++;
            else t1[b]+=2;
            if(t1[b]>=2) printf("%s %d %d\n",ar,b,a);
        }
        else
        {
            if(t2[b]>=2) continue;
            if(c2=='y') t2[b]++;
            else t2[b]+=2;
            if(t2[b]>=2) printf("%s %d %d\n",as,b,a);
        }
    }
}

