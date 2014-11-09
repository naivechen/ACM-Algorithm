// http://codeforces.com/contest/485/problem/A

#pragma comment(linker, "/STACK:1024000000,1024000000")
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
using namespace std;
#define LL long long
#define L(u) (u<<1)
#define R(u) (u<<1|1)
#define pii pair<int,int>
#define mpair make_pair
const int maxn=100010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
int n,m,vis[maxn];
int main()
{
    scanf("%d %d",&n,&m);
    while(true)
    {
        if(n==0)
        {
            printf("Yes\n");
            break;
        }
        if(vis[n]==1)
        {
            printf("No\n");
            break;
        }
        vis[n]=1;
        n=(n+n)%m;
    }
}

