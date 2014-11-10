// http://codeforces.com/contest/485/problem/C


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
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n,bit[100];
LL get()
{
    LL ret=0;
    for(int i=0;i<100;i++)
    {
        if(bit[i]==1)
            ret=ret+(1LL<<i);
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        memset(bit,0,sizeof(bit));
        LL le,ri;
        scanf("%I64d %I64d",&le,&ri);
        LL m=le,num=0;
        while(m)
        {
            if(m&1) bit[num]=1;
            num++;
            m/=2;
        }
        m=le;
        LL ret=le;
        while(m<=ri)
        {
            ret=m;
            for(int i=0;i<100;i++)
                if(bit[i]==0)
                {
                    bit[i]=1;
                    break;
                }
            m=get();
        }
        printf("%I64d\n",ret);
    }
}
