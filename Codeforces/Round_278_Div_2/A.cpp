// http://codeforces.com/contest/488/problem/A


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
const int maxn=1010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//----------------------------------------------------------
int n,m;
LL inp;
bool check(LL x)
{
    if(x==0) return false;
    if(x<0) x=-x;
    while(x)
    {
        int yu=x%10;
        if(yu==8) return true;
        x/=10;
    }
    return false;
}
int main()
{
    // freopen("in.txt","r",stdin);
    cin>>inp;
    if(check(inp)==true)
    {
        int ans=1;
        inp++;

        while(check(inp)==false)
        {
            ans++;
            inp++;
        }
        cout<<ans<<endl;
    }
    else
    {
        inp=inp+1;
        int ans=1;
        while(check(inp)==false)
        {
            ans++;
            inp++;
        }
        cout<<ans<<endl;
    }
}
