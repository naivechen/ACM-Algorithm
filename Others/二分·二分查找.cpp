// http://hihocoder.com/problemset/problem/1128?sid=258706

// When I wrote this, only God and I understood what I was doing
// now, God only knows

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
const int maxn=1000010;
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
int n,m;
set<int> se;
int main()
{
    int inp;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&inp);
        se.insert(inp);
    }
    if(se.find(m)==se.end())
        printf("-1\n");
    else
    {
        set<int>::iterator it=se.begin();
        int num=1;
        while(it!=se.end())
        {
            int tmp=*it;
            if(tmp==m)
            {
                printf("%d\n",num);
                break;
            }
            ++it;
            num++;
        }
    }
}
