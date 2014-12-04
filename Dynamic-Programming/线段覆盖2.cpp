// http://codevs.cn/problem/3027/


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
const int maxn=2100;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
struct chen
{
    int x,y,val;
}info;
chen ch[maxn],dp[maxn];
int n;
bool cmp(chen a, chen b)
{
    return a.y<b.y;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ch[i].x>>ch[i].y>>ch[i].val;
    sort(ch+1,ch+1+n,cmp);
    int maxval=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=1;j<i;j++)
        {
            if(ch[i].x>=ch[j].y && tmp<ch[j].val)
                tmp=ch[j].val;
        }
        ch[i].val=tmp+ch[i].val;
        if(maxval<ch[i].val) maxval=ch[i].val;
    }
    cout<<maxval<<endl;
}
