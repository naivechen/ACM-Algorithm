// http://codeforces.com/contest/490/problem/B


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
const int maxn=2000010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int next[1100000], a[1100000], out[1100000];
struct node
{
  int u, v;
}ch[1100000];
int main()
{
    int n, i, j, u, v, cnt, pos;
    while(scanf("%d",&n)!=EOF)
    {
        memset(next,-1,sizeof(next));
        memset(out,0,sizeof(out));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&ch[i].u, &ch[i].v);
            next[ch[i].u]=ch[i].v;
            out[ch[i].v]++;
        }
        cnt=1;
        for(i=0;i!=-1;i=next[i])
        {
            if(cnt!=1&&!i) break;
            a[cnt]=next[i];
            cnt+=2;
        }
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(!out[ch[i].u])
            {
                pos=ch[i].u;
                break;
            }
        }
        a[0]=pos;
        cnt=2;
        for(i=pos;i!=-1;i=next[i])
        {
            a[cnt]=next[i];
            cnt+=2;
        }
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
    }
}
