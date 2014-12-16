// http://acm.zjut.edu.cn/onlinejudge/problem.php?id=1319


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
const int maxn=200010;
const double eps=1e-8;
const int fdir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int edir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
const int mod=1000000007;
const int inf=0x3fffffff;
const double pi=acos(-1.0);
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//---------------------------------------------------------
int main()
{
    int n,a,b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(a>b) swap(a,b);
        int aa=0,bb=0;
        int le=0,ri=0;
        int flag=1;
        while(n--)
        {
            if(flag) aa+=a;
            else bb+=b;
            if(aa>bb) flag^=1;
            else if(aa<bb) flag=1;
        }
        int tmp=min(aa,bb);
        cout<<1000000000-tmp<<endl;
    }
}
