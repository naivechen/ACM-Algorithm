// http://codeforces.com/contest/483/problem/C

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
#include <unistd.h>
using namespace std;
#define LL long long int
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=100002;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------
int ans[maxn];
int a[maxn];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    memset(a,0,sizeof(a));
    ans[1]=1;
    int num=2;
    a[1]=1;
    int flag=1;
    for(int i=k;i>1;i--)
    {
        if(flag)
        {
            int tmp=ans[num-1]+i;
            if(a[tmp]==0)
            {
                ans[num]=tmp;
                num++;
                a[tmp]=1;
            }
            else
            {
                tmp=ans[num-1]-i;
                ans[num]=tmp;
                num++;
                a[tmp]=1;
            }
        }
        else
        {
            int tmp=ans[num-1]-i;
            if(a[tmp]==0)
            {
                ans[num]=tmp;
                num++;
                a[tmp]=1;
            }
            else
            {
                tmp=ans[num-1]+i;
                ans[num]=tmp;
                num++;
                a[tmp]=1;
            }

        }
        if(flag==1) flag=0;
        else flag=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            ans[num]=i;
            a[i]=1;
            num++;
        }
    }
    for(int i=1;i<num;i++)
    {
        if(i>1) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
}
