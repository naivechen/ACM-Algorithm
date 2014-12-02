// http://codevs.cn/problem/1214/


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
const int maxn=20010;
const double eps=1e-8;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
//---------------------------------------------------------------
struct chen
{
    int x,y;
}info;
chen ch[maxn];
int n;
bool my(chen a, chen b)
{
    return a.y<b.y;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        ch[i].x=min(u,v);
        ch[i].y=max(u,v);
    }
    sort(ch+1,ch+1+n,my);
    int ans=1,cmp=ch[1].y;
    for(int i=2;i<=n;i++)
    {
        if(ch[i].x>=cmp)
        {
            cmp=ch[i].y;
            ans++;
        }
    }
    cout<<ans<<endl;
}
