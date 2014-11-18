// http://codeforces.com/contest/489/problem/A


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
const int maxn=5010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
typedef vector<int> INT;
//---------------------------------------------------------
int n;
int a[maxn],b[maxn];
struct Point
{
    int x,y;
}ch[maxn];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],b[i]=a[i];
    int ans=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) continue;
        ans++;
        ch[ans].x=i;
        for(int j=i+1;j<n;j++)
        {
            if(b[j]==a[i])
            {
                ch[ans].y=j;
                swap(b[i],b[j]);
                break;
            }
        }
    }
    if(!ans) cout<<ans<<endl;
    else
    {
        cout<<ans<<endl;
        for(int i=1;i<=ans;i++)
            cout<<ch[i].x<<" "<<ch[i].y<<endl;
    }
}
