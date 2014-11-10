// http://codeforces.com/contest/485/problem/B

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
int n;
int main()
{
    cin>>n;
    LL maxx=-inf,minx=inf,maxy=-inf,miny=inf;
    for(int i=1;i<=n;i++)
    {
        LL x,y;
        cin>>x>>y;
        if(x>maxx) maxx=x;
        if(x<minx) minx=x;
        if(y>maxy) maxy=y;
        if(y<miny) miny=y;
    }
    int ans=max(maxx-minx,maxy-miny);
    LL ret=(LL)ans;
    cout<<ret*ret<<endl;
}
