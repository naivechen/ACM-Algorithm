// http://codeforces.com/contest/488/problem/B


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
int n,a[maxn];
bool check(int x1,int x2,int x3,int x4)
{
    int p1=(x1+x2+x3+x4);
    int p2=(x2+x3);
    int p3=x4-x1;
    if(p1==4*p3 && p2==2*p3) return true;
    return false;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(n==0) cout<<"YES"<<endl<<1<<endl<<1<<endl<<3<<endl<<3<<endl;
    else if(n==4)
    {
        if(check(a[1],a[2],a[3],a[4])) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(n==1)
    {
        cout<<"YES"<<endl<<2*a[1]<<endl<<2*a[1]<<endl<<3*a[1]<<endl;
    }
    else if(n==2)
    {
        if((3*a[1])<a[2]) cout<<"NO"<<endl;
        else cout<<"YES"<<endl<<4*a[1]-a[2]<<endl<<3*a[1]<<endl;
    }
    else if(n==3)
    {
        int b[5];

        for(int i=1;i<=1510;i++)
        {
            for(int j=1;j<=n;j++) b[j]=a[j];
            b[4]=i;
            sort(b+1,b+1+n+1);
            if(check(b[1],b[2],b[3],b[4]))
            {
                cout<<"YES"<<endl<<i<<endl;
                return 0;
            }
        }
        cout<<"NO"<<endl;
    }
}
